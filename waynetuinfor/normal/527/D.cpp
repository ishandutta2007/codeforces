#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;
int dp[maxn];

inline void cmax(int &a, int b) { a = max(a, b); }

struct fenwick {
    int dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) cmax(dat[p], v); }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) cmax(v, dat[p]); return v; }
} bit;

int x[maxn], w[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v, ds;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> w[i];
        v.push_back(i);
        ds.push_back(x[i] + w[i]);
    }
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    sort(v.begin(), v.end(), [&](const int &i, const int &j) { return x[i] < x[j]; });
    bit.init();
    for (int i : v) {
        int qp = upper_bound(ds.begin(), ds.end(), x[i] - w[i]) - ds.begin();
        dp[i] = bit.qry(qp) + 1;
        int mp = lower_bound(ds.begin(), ds.end(), x[i] + w[i]) - ds.begin() + 1;
        bit.add(mp, dp[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) cmax(ans, dp[i]);
    cout << ans << endl;
    return 0;
}