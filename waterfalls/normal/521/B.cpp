#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int m;
int x[100013];
int y[100013];
map<pair<int,int>,int> value;
map<pair<int,int>,int> below;
set<pair<int,pair<int,int> > > frontier;
int powM[100013];
int MOD = 1000000009;
int dX[3] = {-1,0,1};

int main() {
    scanf("%d",&m);
    powM[0] = 1;
    for (int i=1;i<=m;i++) powM[i] = ((long long) powM[i-1]*m)%MOD;
    for (int i=0;i<m;i++) {
        scanf("%d%d",&x[i],&y[i]);
        value[make_pair(x[i],y[i])] = i;
    }
    for (int i=0;i<m;i++) {
        int b = 0;
        for (int j=0;j<3;j++) if (value.count(make_pair(x[i]+dX[j],y[i]-1))) b+=1;
        below[make_pair(x[i],y[i])] = b;
    }
    for (int i=0;i<m;i++) {
        int ok = 1;
        for (int j=0;j<3;j++) if (below[make_pair(x[i]+dX[j],y[i]+1)]==1) ok = 0;
        if (ok) frontier.insert(make_pair(value[make_pair(x[i],y[i])],make_pair(x[i],y[i])));
    }
    int ans = 0;
    int which = 0;
    while (frontier.size()>0) {
        pair<int,pair<int,int> > next;
        if (which%2) next = *frontier.begin();
        else next = *(--frontier.end());
        int nX = next.second.first;
        int nY = next.second.second;
        frontier.erase(next);
        value.erase(make_pair(nX,nY));
        below[make_pair(nX,nY)] = 0;
        for (int j=0;j<3;j++) if (value.count(make_pair(nX+dX[j],nY+1))) {
            below[make_pair(nX+dX[j],nY+1)]-=1;
            if (below[make_pair(nX+dX[j],nY+1)]==1) {
                for (int k=0;k<3;k++) if (value.count(make_pair(nX+dX[j]+dX[k],nY)))
                    frontier.erase(make_pair(value[make_pair(nX+dX[j]+dX[k],nY)],make_pair(nX+dX[j]+dX[k],nY)));
            }
        }
        for (int j=0;j<3;j++) if (value.count(make_pair(nX+dX[j],nY-1))) {
            int ok = 1;
            for (int k=0;k<3;k++) if (below[make_pair(nX+dX[j]+dX[k],nY)]==1) ok = 0;
            if (ok) frontier.insert(make_pair(value[make_pair(nX+dX[j],nY-1)],make_pair(nX+dX[j],nY-1)));
        }
        ans = (ans+(long long) next.first*powM[m-1-which])%MOD;
        which+=1;
    }
    printf("%d\n",ans);

    return 0;
}