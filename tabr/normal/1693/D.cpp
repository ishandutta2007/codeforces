#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    map<pair<int, int>, int> dp;
    for (int i = 0; i < n; i++) {
        debug(dp);
        map<pair<int, int>, int> new_dp;
        for (auto [p, q] : dp) {
            auto [x, y] = p;
            int nx = 0;
            int ny = n + 1;
            if (a[i - 1] < a[i]) {
                nx = max(nx, x);
            } else {
                ny = min(ny, y);
            }
            if (x > a[i]) {
                ny = min(ny, a[i - 1]);
            }
            if (y < a[i]) {
                nx = max(nx, a[i - 1]);
            }
            if (nx != 0 || ny != n + 1) {
                ans += q;
                new_dp[make_pair(nx, ny)] += q;
            }
        }
        new_dp[make_pair(n + 1, 0)]++;
        ans++;
        swap(dp, new_dp);
    }
    cout << ans << '\n';
    return 0;
}