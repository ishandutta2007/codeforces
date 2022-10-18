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
    int n, m;
    cin >> n >> m;
    ll x, y, k;
    cin >> x >> k >> y;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<int> p(m + 2, -1);
    p[m + 1] = n;
    for (int i = 0, j = 0; i < n; i++) {
        if (j != m && a[i] == b[j]) {
            p[j + 1] = i;
            j++;
        }
    }
    if (p[m] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        if (p[i] + 1 == p[i + 1]) {
            continue;
        }
        bool ok = true;
        for (int j = p[i] + 1; j < p[i + 1]; j++) {
            if ((i == 0 || a[p[i]] < a[j]) && (i == m || a[p[i + 1]] < a[j])) {
                ok = false;
                break;
            }
        }
        ll add = 1e18;
        ll dif = p[i + 1] - p[i] - 1;
        if (!ok && dif < k) {
            cout << -1 << '\n';
            return 0;
        }
        for (ll j = !ok; j * k <= dif; j++) {
            add = min(add, x * j + y * (dif - k * j));
        }
        ans += add;
    }
    cout << ans << '\n';
    return 0;
}