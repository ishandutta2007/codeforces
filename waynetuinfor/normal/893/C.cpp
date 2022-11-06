#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
vector<int> G[maxn];
int c[maxn], cur;
bool v[maxn];

void dfs(int now) {
    v[now] = true;
    cur = min(cur, c[now]);
    for (int u : G[now]) if (!v[u]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        cur = inf;
        dfs(i);
        ans += cur;
    }
    cout << ans << endl;
    return 0;
}