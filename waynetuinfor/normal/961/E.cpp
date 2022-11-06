#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], b[maxn], c[maxn];

struct fenwick {
    int dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] += v; }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v += dat[p]; return v; }
} bit;

int main() {
    int n; scanf("%d", &n);
    vector<int> ds;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i), ds.push_back(a[i]);
    for (int i = 1; i <= n; ++i) ds.push_back(i);
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 1; i <= n; ++i) b[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin() + 1;
    for (int i = 1; i <= n; ++i) c[i] = lower_bound(ds.begin(), ds.end(), i) - ds.begin() + 1;
    vector<int> o(n); iota(o.begin(), o.end(), 1);
    bit.init();
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    int p = 1;
    long long ans = 0;
    for (int i = 0; i < o.size(); ++i) {
        while (p <= n && p <= a[o[i]]) bit.add(b[p], 1), ++p;
        ans += bit.qry(maxn - 1) - bit.qry(c[o[i]] - 1);
    }
    for (int i = 1; i <= n; ++i) if (a[i] >= i) --ans;
    ans >>= 1;
    printf("%" PRId64 "\n", ans);
    return 0;
}