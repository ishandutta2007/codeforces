#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int in[MAXN], ans[MAXN], sz[MAXN], t;
vector<int> adj[MAXN];

int dfs(int v){
    ans[++t]=v, in[v]=t; sz[v]=1;
    for (int to:adj[v]) sz[v]+=dfs(to);
    return sz[v];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=2,a;i<=n;++i) cin >> a, adj[a].push_back(i);
    dfs(1);
    while (q--){
        int a, b; cin >> a >> b;
        cout << (b>sz[a]?-1:ans[in[a]+b-1]) << '\n';
    }
}