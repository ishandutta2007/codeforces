#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,cost[100001],lt[100001],gt[100001];
vector<int> adj[100001];
vector<int> ga[100001];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cost[i] = i;

    lli ans = 0;
    for(int cur=1;cur<=n;cur++) {
        for(auto &it:adj[cur]) {
            if(it < cur) lt[cur]++;
            else gt[cur]++, ga[cur].push_back(it);
        }
    }
    for(int cur=1;cur<=n;cur++) for(auto &it:adj[cur]) if(it < cur) {
        ans += lt[it];
    }
    printf("%lld\n",ans);

    int q;
    scanf("%d",&q);
    while(q--) {
        int cur;
        scanf("%d",&cur);
        ans -= 1ll*lt[cur]*gt[cur];
        lt[cur] = sz(adj[cur]);
        gt[cur] = 0;
        
        for(auto &it:ga[cur]) {
            ans -= gt[it];
            lt[it]--;
            gt[it]++;
            ga[it].push_back(cur);
            ans += lt[it];
        }
        ga[cur].clear();
        printf("%lld\n",ans);
    }
    
    return 0;
}