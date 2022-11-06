#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
vector<int> G[maxn];
int deg[maxn];
bool v[maxn];

void dfs(int);

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    int loop = 0, start = 0;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        if (a == b) ++loop;
        else ++deg[a], ++deg[b];
        G[a].push_back(b);
        G[b].push_back(a);
        start = max({ start, a, b });
    }
    dfs(start);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) if (!v[i] && G[i].size()) return cout << "0\n", 0;
    for (int i = 1; i <= n; ++i) ans += (LL)(deg[i]) * (LL)(deg[i] - 1) / 2;
    ans += (LL)(loop) * (LL)(loop - 1) / 2;
    ans += (LL)(loop) * (LL)(m - loop);
    return cout << ans << '\n', 0;
}

void dfs(int x) {
    v[x] = true;
    for (int u : G[x]) if (!v[u]) dfs(u);
}