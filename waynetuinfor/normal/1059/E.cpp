#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int w[maxn], l, dep[maxn];
long long sl[maxn];
set<pair<long long, int>> ks[maxn], kl[maxn];
long long s;

void dfs(int x, int p) {
    dep[x] = (~p ? dep[p] : 0) + 1;
    sl[x] = (~p ? sl[p] : 0) + w[x];
    for (const int &u : g[x]) dfs(u, x);
}

int dfs2(int x, int p) {
    int res = 0;
    for (const int &u : g[x]) {
        res += dfs2(u, x);
        if (ks[u].size() > ks[x].size()) {
            ks[u].swap(ks[x]);
            kl[u].swap(kl[x]);
        }
        for (const auto &it : ks[u]) ks[x].insert(it);
        for (const auto &it : kl[u]) kl[x].insert(it);
    }
    while (ks[x].size() && ks[x].rbegin()->first - (~p ? sl[p] : 0) > s) {
        int y = ks[x].rbegin()->second;
        ks[x].erase(make_pair(sl[y], y));
        kl[x].erase(make_pair(dep[y], y));
        ++res;
    }
    while (kl[x].size() && kl[x].rbegin()->first - (~p ? dep[p] : 0) > l) {
        int y = kl[x].rbegin()->second;
        ks[x].erase(make_pair(sl[y], y));
        kl[x].erase(make_pair(dep[y], y));
        ++res;
    }
    if (ks[x].size() == 0) {
        ks[x].insert(make_pair(sl[x], x));
        kl[x].insert(make_pair(dep[x], x));
    }
    return res;
}

int main() {
    int n; scanf("%d%d%lld", &n, &l, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    for (int i = 1; i < n; ++i) {
        int p; scanf("%d", &p); --p;
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        if (w[i] > s) {
            puts("-1");
            return 0;
        }
    }
    dfs(0, -1); 
    int ans = dfs2(0, -1);
    ans += ks[0].size();
    printf("%d\n", ans);
    return 0;
}