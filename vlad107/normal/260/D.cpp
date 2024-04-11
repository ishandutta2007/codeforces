#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <iomanip>
#include <assert.h>

#define mp make_pair
#define pb push_back
#define N 500500

typedef long long ll;

using namespace std;

set<pair<int,int> >g[2];
vector<pair<pair<int,int>,int> >ans;
int c[N],s[N],n;
int used[N];

int main(){
//    freopen("input","r",stdin);
//    freopen("output","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&c[i],&s[i]);
        g[c[i]].insert(mp(s[i],i));
    }
    memset(used,0,sizeof(used));
    while (!g[0].empty()&&!g[1].empty()){
        int u;
        if ((g[1].begin()->first)<(g[0].begin()->first))
            u=1;
        else u=0;
        int x=g[u].begin()->second;
        set<pair<int,int> >::iterator it=g[1-u].end();
        --it;
        int y=it->second;
        g[1-u].erase(it);
        g[u].erase(g[u].begin());
        ans.pb(mp(mp(1+x,1+y),s[x]));
        s[y]-=s[x];
        s[x]=0;
        used[x]=1;
        used[y]=1;
        g[1-u].insert(mp(s[y],y));
    }
    int u,v;
    for (int i=0;i<n;i++)
        if (c[i]==0)u=i;else v=i;
    for (int i=0;i<n;i++)
        if (!used[i]){
            if (c[i]==0)ans.pb(mp(mp(1+v,1+i),0));
            else ans.pb(mp(mp(1+u,1+i),0));
        }
    for (int i=0;i<ans.size();i++)printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);
    return 0;
}