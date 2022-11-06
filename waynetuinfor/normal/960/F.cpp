#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> ds[maxn];
int a[maxn], b[maxn], w[maxn];
int dp[maxn];

struct fenwick {
    vector<int> dat;
    void init(int n) { dat.resize(n, 0); }
    void add(int p, int v) { for (; p < dat.size(); p += p & -p) dat[p] = max(dat[p], v); }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v = max(v, dat[p]); return v; }
} bit[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d %d %d", a + i, b + i, w + i);
    for (int i = 0; i < m; ++i) ds[b[i]].push_back(w[i]);
    for (int i = 1; i <= n; ++i) {
        sort(ds[i].begin(), ds[i].end());
        ds[i].resize(unique(ds[i].begin(), ds[i].end()) - ds[i].begin());
        bit[i].init(ds[i].size() + 10);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int p = upper_bound(ds[a[i]].begin(), ds[a[i]].end(), w[i]) - ds[a[i]].begin();
        dp[i] = bit[a[i]].qry(p) + 1;
        p = lower_bound(ds[b[i]].begin(), ds[b[i]].end(), w[i]) - ds[b[i]].begin() + 1;
        bit[b[i]].add(p, dp[i]);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}