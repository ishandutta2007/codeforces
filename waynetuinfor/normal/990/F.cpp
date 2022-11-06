#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int s[maxn], z[maxn];
int ed[maxn], h[maxn], ans[maxn];
bool v[maxn];
vector<int> g[maxn];

void dfs(int x) {
    v[x] = true;
    for (int e : g[x]) {
        int u = (ed[e] ^ x);
        if (v[u]) continue;
        dfs(u);
        ans[e] = x == h[e] ? z[u] : -z[u];
        z[x] += z[u];
        z[u] = 0;
    }
}

int main() {
    int n; scanf("%d", &n);
    long long c = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]), z[i] = s[i], c += s[i];
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y); --x, --y;
        h[i] = x;
        g[x].push_back(i);
        g[y].push_back(i);
        ed[i] = x ^ y;
    }
    if (c != 0) return 0 * puts("Impossible");
    dfs(0);
    puts("Possible");
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    return 0;
}