#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn], ans;
int a[maxn], tin[maxn], t;
bool rt[maxn];

void dfs(int now, int fa) {
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        if (tin[a[u]] && tin[a[u]] != tin[a[now]]) {
            cout << "-1" << endl;
            exit(0);
        }
        dfs(u, now);
    }
    if (a[now] == now) ans.push_back(now);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    fill(rt, rt + maxn, true);
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
        rt[b] = false;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) if (rt[i]) dfs(i, 0);
    cout << ans.size() << endl;
    for (int i : ans) cout << i << endl;
    return 0;
}