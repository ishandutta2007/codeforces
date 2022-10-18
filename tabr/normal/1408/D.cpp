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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] <= c[j] && b[i] <= d[j]) {
                p.emplace_back(c[j] + 1 - a[i], d[j] + 1 - b[i]);
            }
        }
    }
    sort(p.begin(), p.end());
    debug(p);
    int ans = 1e9;
    int t = 0;
    for (int i = (int)p.size() - 1; i >= 0; i--) {
        ans = min(ans, t + p[i].first);
        t = max(t, p[i].second);
    }
    ans = min(ans, t);
    cout << ans << '\n';
    return 0;
}