#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

vector<int> adj[MN];
int col[MN], par[MN], leaf[MN], ans;

void dfs(int v){
    col[v] = 1;
    int dec = 0;
    for (int to : adj[v]){
        if (to == par[v]) continue;
        par[to] = v;
        dfs(to);
        if (col[to] == 0) dec++;
        if (col[to] == 1) col[v] = 0;
    }
    
    if (adj[v].size() == 1 && adj[v][0] == par[v]) leaf[v] = 1;
    if (col[v] == 1) dec--;
    if (leaf[v]) ans++;
    else ans -= dec;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        // reset
        for (int i = 1; i <= n; ++i){
            adj[i].clear();
            col[i] = -1;
            par[i] = 0;
            leaf[i] = 0;
        }
        ans = 0;

        for (int i = 1; i <= n - 1; ++i){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1);
        cout << ans << '\n';
    }
}