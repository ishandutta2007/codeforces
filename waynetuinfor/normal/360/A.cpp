#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5000 + 10, inf = 1e18;
int ub[maxn], l[maxn], r[maxn], d[maxn], t[maxn], tag[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> t[i] >> l[i] >> r[i] >> d[i];
    fill(ub, ub + maxn, inf);
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j) tag[j] += d[i];
        } else {
            int ans = -inf;
            for (int j = l[i]; j <= r[i]; ++j) {
                ans = max(ans, ub[j] + tag[j]);
                ub[j] = min(ub[j], d[i] - tag[j]);
            }
            if (ans < d[i]) return cout << "NO" << endl, 0;
        }
    }
    for (int i = m - 1; i >= 0; --i) {
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j) tag[j] -= d[i];
        } else {
            int ans = -inf;
            for (int j = l[i]; j <= r[i]; ++j) {
                ans = max(ans, ub[j] + tag[j]);
                ub[j] = min(ub[j], d[i] - tag[j]);
            }
            if (ans < d[i]) return cout << "NO" << endl, 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << min(ub[i], (int)1e9) << ' '; cout << endl;
    return 0;
}