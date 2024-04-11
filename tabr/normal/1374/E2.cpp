#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> z(4);
    vector<vector<int>> x(4), y(4);
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a ^= 1, b ^= 1;
        z[2 * a + b].emplace_back(t, i + 1);
    }
    vector<vector<int>> a(4);
    for (int i = 0; i < 4; i++) {
        sort(z[i].begin(), z[i].end());
        x[i].emplace_back(0);
        for (int j = 0; j < z[i].size(); j++) {
            a[i].emplace_back(z[i][j].first);
            x[i].emplace_back(x[i].back() + z[i][j].first);
            y[i].emplace_back(z[i][j].second);
        }
    }
    int inf = 2.1e9;
    int ans = inf;
    vector<int> t(4);
    int mx = min(a[1].size(), a[2].size());
    int all = a[1].size() + a[2].size() + a[3].size();
    int over = -1, kk = -1;
    for (int i = 0; i < x[0].size(); i++) {
        int j = max(0, k - i);
        if (mx < j) {
            continue;
        }
        int need = m - i - j - j;
        if (need < 0 || all + i < m) {
            continue;
        }
        int lo = -1, hi = 10001;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            int cnt = upper_bound(a[3].begin(), a[3].end(), mid) - a[3].begin();
            cnt += max(j, upper_bound(a[1].begin(), a[1].end(), mid) - a[1].begin());
            cnt += max(j, upper_bound(a[2].begin(), a[2].end(), mid) - a[2].begin());
            cnt += i;
            if (cnt >= m) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        vector<int> tt(4);
        tt[0] = i;
        tt[1] = max(j, upper_bound(a[1].begin(), a[1].end(), hi) - a[1].begin());
        tt[2] = max(j, upper_bound(a[2].begin(), a[2].end(), hi) - a[2].begin());
        tt[3] = upper_bound(a[3].begin(), a[3].end(), hi) - a[3].begin();
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += x[i][tt[i]];
        }
        sum -= (accumulate(tt.begin(), tt.end(), 0) - m) * hi;
        assert(accumulate(tt.begin(), tt.end(), 0) >= m);
        if (sum < ans) {
            ans = sum;
            t = tt;
            over = hi;
            kk = j;
        }
    }
    debug(ans, t);
    cout << (ans == inf ? -1 : ans) << '\n';
    int b = accumulate(t.begin(), t.end(), 0) - m;
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < t[i]; j++) {
            if (i != 0 && over == a[i][j] && b > 0) {
                if (i != 3 && j < kk) {
                    cout << y[i][j] << " ";
                    continue;
                }
                b--;
                continue;
            }
            cout << y[i][j] << " ";
        }
    }
    assert(ans == inf || b == 0);
    cout << '\n';
    return 0;
}