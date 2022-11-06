#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<pair<int, int>> g[maxn];
int deg[maxn];
pair<int, int> ed[maxn];
int ans[maxn];
bool v[maxn], cut[maxn];
set<pair<int, int>> s;

void fit(int k) {
    while (s.size() && s.begin()->first < k) {
        int x = s.begin()->second;
        s.erase(s.begin());
        v[x] = true;
        for (auto e : g[x]) {
            if (cut[e.second]) continue;
            int u = e.first;
            if (v[u]) continue;
            s.erase(make_pair(deg[u], u));
            --deg[u];
            s.insert(make_pair(deg[u], u));
        }
    }
}

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        ed[i] = make_pair(x, y);
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
        ++deg[x], ++deg[y];
    }
    for (int i = 0; i < n; ++i) s.insert(make_pair(deg[i], i));
    fit(k);
    ans[m - 1] = s.size();
    for (int i = m - 1; i >= 0; --i) {
        int x = ed[i].first, y = ed[i].second;
        if (!v[x] && !v[y]) {
            s.erase(make_pair(deg[x], x));
            s.erase(make_pair(deg[y], y));
            --deg[x], --deg[y];
            s.insert(make_pair(deg[x], x));
            s.insert(make_pair(deg[y], y));
            cut[i] = true;
            fit(k);
        }
        if (i) ans[i - 1] = s.size();
    }
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    return 0;
}