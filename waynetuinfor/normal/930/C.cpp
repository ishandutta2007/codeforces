#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], dp1[maxn], dp2[maxn];

struct fenwick {
    int dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] = max(dat[p], v); }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v = max(dat[p], v); return v; }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v;
    while (n--) {
        int l, r; cin >> l >> r;
        ++a[l]; --a[r + 1];
    }
    for (int i = 1; i <= m; ++i) a[i] += a[i - 1];
    bit.init();
    for (int i = 1; i <= m; ++i) ++a[i];
    for (int i = 1; i <= m; ++i) {
        dp1[i] = bit.qry(a[i]) + 1;
        bit.add(a[i], dp1[i]);
    }
    bit.init();
    for (int i = m; i >= 1; --i) {
        dp2[i] = bit.qry(a[i]) + 1;
        bit.add(a[i], dp2[i]);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) ans = max(ans, dp1[i] + dp2[i] - 1);
    cout << ans << endl;
    return 0;
}