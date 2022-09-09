#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int lim=2e9;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    set<pii> stc;
    map<int,int> byx,byy;
    map<int,set<pii>> segs;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%i %i",&x,&y);
        stc.insert({x,y});
        if(!byx.count(x))byx[x]=y;
        else byx[x]=min(byx[x],y);
        if(!byy.count(y))byy[y]=x;
        else byy[y]=min(byy[y],x);
    }
    int x,y;
    byx[lim]=0;
    byy[lim]=0;
    x=0;y=0;
    while(x<lim&&y<lim){
        if(stc.count({x,y}))x++,y++;
        else{
            if(byx.count(x)&&byx[x]<y)x++;
            else if(byy.count(y)&&byy[y]<x)y++;
            else{
                int dx=byx.upper_bound(x)->first-x;
                int dy=byy.upper_bound(y)->first-y;
                int mv=min(dx,dy);
                segs[x-y].insert({x,x+mv-1});
                x+=mv;
                y+=mv;
            }
        }
    }
    while(m--){
        int x,y;
        scanf("%i %i",&x,&y);
        if(stc.count({x,y}))printf("LOSE\n");
        else{
            if(segs.count(x-y)){
                auto it=segs[x-y].upper_bound({x,lim});
                if(it!=segs[x-y].begin()&&prev(it)->second>=x)printf("LOSE\n");
                else printf("WIN\n");
            }else printf("WIN\n");
        }
    }
    return 0;
}