#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vector<int> l(n), r(n), c(n);

    int mn = numeric_limits<int>::max(), costn = 0;
    int mx = numeric_limits<int>::min(), costm = 0;

    map<pi, int> cost;

    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i] >> c[i];

        if (ckmin(mn, l[i])) costn = c[i];
        if (ckmax(mx, r[i])) costm = c[i];

        if (mn == l[i]) ckmin(costn, c[i]);
        if (mx == r[i]) ckmin(costm, c[i]);

        if (!cost.count(pi { l[i], r[i] })) cost[pi { l[i], r[i] }] = numeric_limits<int>::max();
        ckmin(cost[pi { l[i], r[i] }], c[i]);

        int ans = costn + costm;
        if (cost.count(pi { mn, mx })) ckmin(ans, cost[pi {mn, mx}]);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}