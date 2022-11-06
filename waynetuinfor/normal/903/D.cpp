#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct fenwick {
    long double dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, long double v) { for (; p < maxn; p += p & -p) dat[p] += v; }
    long long qry(int p, long double v = 0) { for (; p; p -= p & -p) v += dat[p]; return v; }
} bit1, bit2;

int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    bit1.init(); bit2.init(); 
    long double ans = 0;
    for (int i = 1; i <= n; ++i) {
        int pos = lower_bound(v.begin(), v.end(), a[i] - 1) - v.begin() + 1;
        long double c = bit2.qry(pos - 1);
        long double s = bit1.qry(pos - 1);
        ans += a[i] * c - s;
        pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        bit2.add(pos, 1); bit1.add(pos, a[i]);
    } 
    bit1.init(); bit2.init();
    for (int i = 1; i <= n; ++i) {
        int pos = upper_bound(v.begin(), v.end(), a[i] + 1) - v.begin();
        long double c = bit2.qry(maxn - 1) - bit2.qry(pos);
        long double s = bit1.qry(maxn - 1) - bit1.qry(pos);
        ans += a[i] * c - s;
        pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        bit2.add(pos, 1); bit1.add(pos, a[i]);
    } 
    cout << fixed << setprecision(0) << ans << endl;
    return 0;
}