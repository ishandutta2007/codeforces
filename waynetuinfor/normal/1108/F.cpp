#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int fa[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<tuple<int, int, int>> e;
    for (int i = 0; i < m; ++i) {
        int x, y, w; scanf("%d%d%d", &x, &y, &w);
        --x, --y;
        e.emplace_back(w, x, y);
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < n; ++i) fa[i] = i;
    long long ans = 0;
    for (int i = 0; i < m; ) {
        int j = i;
        vector<pair<int, int>> v;
        while (j < m && get<0>(e[j]) == get<0>(e[i])) {
            int x = get<1>(e[j]);
            int y = get<2>(e[j]);
            v.emplace_back(x, y);
            ++j;
        }
        int mrg = 0;
        vector<pair<int, int>> p;
        for (int k = 0; k < (int)v.size(); ++k) {
            int x = v[k].first, y = v[k].second;
            if (find(x) == find(y)) continue;
            p.emplace_back(x, y);
        }
        for (int k = 0; k < (int)p.size(); ++k) {
            int x = p[k].first, y = p[k].second;
            if (find(x) == find(y)) ++ans;
            fa[find(x)] = find(y);
        }
        i = j;
    }
    printf("%lld\n", ans);
}