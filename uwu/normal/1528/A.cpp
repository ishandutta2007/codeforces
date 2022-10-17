#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll dp[MAXN][2];
ll l[MAXN], r[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p){
    dp[v][0]=dp[v][1]=0;
    for (int to:adj[v]){
        if (to==p) continue;
        dfs(to,v);
        dp[v][0]+=max(dp[to][0]+abs(l[v]-l[to]),dp[to][1]+abs(l[v]-r[to]));
        dp[v][1]+=max(dp[to][0]+abs(r[v]-l[to]),dp[to][1]+abs(r[v]-r[to]));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) adj[i].clear();
        for (int i=1;i<=n;++i) cin >> l[i] >> r[i];
        for (int i=1;i<=n-1;++i){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,1);
        cout << max(dp[1][0],dp[1][1]) << '\n';
    }
}