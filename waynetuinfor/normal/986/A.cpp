#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, maxk = 100 + 5;
vector<int> g[maxn];
int a[maxn], d[maxk][maxn];

int main() {
    int n, m, k, s; scanf("%d %d %d %d", &n, &m, &k, &s);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 0; i < maxk; ++i) for (int j = 0; j < maxn; ++j) d[i][j] = maxn;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        d[a[i]][i] = 0;
        q.emplace(i, a[i]);
    }
    while (q.size()) {
        int x, c; tie(x, c) = q.front(); q.pop();
        for (int u : g[x]) {
            if (d[c][x] + 1 < d[c][u]) {
                d[c][u] = d[c][x] + 1;
                q.emplace(u, c);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> v;
        for (int j = 1; j <= k; ++j) v.push_back(d[j][i]);
        sort(v.begin(), v.end());
        int ans = 0;
        for (int j = 0; j < s; ++j) ans += v[j];
        printf("%d ", ans);
    }
    return 0;
}