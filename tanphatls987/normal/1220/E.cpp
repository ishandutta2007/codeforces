#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n;
ll w[N];
vector<int> adj[N];
int pa[N];
int num[N], low[N];
int mark[N];

void DFS(int u, int z) {
    static int n1 = 0;
    low[u] = num[u] = ++n1;
    pa[u] = z;

    for(auto v : adj[u]) {
        if (v == z) continue;
        if (!num[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            mark[u] |= mark[v];
        } else low[u] = min(low[u], num[v]);
    }
    mark[u] |= low[u] < num[u];
}
void prepare() {
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int st;
    cin >> st;


    mark[st] = 1;
    DFS(st, -1);
    
}
ll f[N];
ll DP(int u) {
    if (mark[u]) return 0;
    ll &res = f[u];
    if (res != -1) return res;
    return res = DP(pa[u]) + w[u];
}
ll solve() {
    ll ans = 0;
    memset(f, -1, sizeof(f));
    for(int i = 1; i <= n; i++) ans = max(ans, DP(i));


    for(int i = 1; i <= n; i++) if (mark[i]) {
        ans += w[i];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    prepare();
    cout << solve();
}