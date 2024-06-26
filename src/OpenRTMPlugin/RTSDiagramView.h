/*!
 * @brief  This is a definition of RTSystemEditorPlugin.
 * @author Hisashi Ikari
 * @file
 */
#ifndef CNOID_OPENRTM_PLUGIN_RTS_DIAGRAM_VIEW_H_INCLUDED
#define CNOID_OPENRTM_PLUGIN_RTS_DIAGRAM_VIEW_H_INCLUDED

#include <cnoid/View>
#include <cnoid/Dialog>
#include <cnoid/CorbaUtil>
#include "exportdecl.h"

using namespace cnoid;

namespace cnoid {
class RTSDiagramViewImpl;
class RTSComp;

class CNOID_EXPORT RTSDiagramView : public View
{
    Q_OBJECT

public:
    static void initializeClass(ExtensionManager* ext);
    static RTSDiagramView* instance();

    RTSDiagramView();
    virtual ~RTSDiagramView();

    SignalProxy<void(RTSComp*)> sigDoubleClickEvent();

public Q_SLOTS:
    void onRTSCompSelectionChange();

protected:
    virtual void onActivated() override;
    virtual void onDeactivated() override;
    virtual bool storeState(Archive& archive) override;
    virtual bool restoreState(const Archive& archive) override;

private:
    RTSDiagramViewImpl* impl;

};

}

#endif 
