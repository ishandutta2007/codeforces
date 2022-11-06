#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int maxn = 5e5 + 5, mod = 1e9 + 7;
long long c[maxn], pw[maxn];
cc_hash_table<long long, vector<pair<int, int>>> ed;
int fa[maxn], all;

void init(int n) {
    for (int i = 0; i < n; ++i) fa[i] = i;
    all = n;
}

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return; 
    fa[x] = y;
    --all;
}

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%lld", &c[i]);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % mod;
    vector<long long> ds;
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        ed[c[x] ^ c[y]].emplace_back(x, y);
        ds.push_back(c[x] ^ c[y]);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    long long ans = pw[n] * (((1ll << k) - ds.size()) % mod) % mod;
    init(n);
    for (int i = 0; i < ds.size(); ++i) {
        long long d = ds[i];
        for (int j = 0; j < ed[d].size(); ++j) {
            merge(ed[d][j].first, ed[d][j].second);
        }
        (ans += pw[all]) %= mod;
        for (int j = 0; j < ed[d].size(); ++j) {
            fa[ed[d][j].first] = ed[d][j].first;
            fa[ed[d][j].second] = ed[d][j].second;
        }
        all = n;
    }
    printf("%lld\n", ans);
    return 0;
}