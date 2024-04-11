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
    int n, c;
    cin >> n >> c;
    vector<long long> a(c + 1);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x] = max(a[x], 1LL * y * z);
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 2; i * j <= c; j++) {
            a[i * j] = max(a[i * j], a[i] * j);
        }
    }
    for (int i = 1; i <= c; i++) {
        a[i] = max(a[i], a[i - 1]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        long long d, h;
        cin >> d >> h;
        long long b = 1LL * d * h;
        auto iter = lower_bound(a.begin(), a.end(), b + 1);
        int ans = -1;
        if (iter != a.end()) {
            ans = (int) (iter - a.begin());
        }
        cout << ans << " \n"[i == m - 1];
    }
    return 0;
}