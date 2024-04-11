#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int val[MAXN], col[MAXN];
vector<int> adj[MAXN];

void dfs(int v, bool &ans){
    for (int to:adj[v]){
        if (col[to]) ans&=col[v]!=col[to];
        else{
            col[to]=-col[v];
            dfs(to,ans);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        for (int i=1;i<=n;++i){
            val[i]=col[i]=0;
            adj[i].clear();
        }
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            val[i]=-x;
        }
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            val[i]+=x;
        }
        for (int i=1;i<=m;++i){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        col[1]=1;
        bool bi=1;
        dfs(1,bi);
        if (bi){
            ll tot=0;
            for (int i=1;i<=n;++i) tot+=col[i]*val[i];
            cout << (tot?"NO":"YES") << '\n';
        }
        else{
            ll tot=0;
            for (int i=1;i<=n;++i) tot+=val[i];
            cout << (tot%2?"NO":"YES") << '\n';
        }
    }
}