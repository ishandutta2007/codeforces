#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e7;
int p[maxn];

int main() {
    int n, a; cin >> n >> a;
    for (int i = 0; i < n; ++i) cin >> p[i];
    if (n == 1) return cout << "0" << endl, 0;
    sort(p, p + n);
    if (n == 2) {
        if (a == p[0] || a == p[1]) cout << 0 << endl;
        else if (a < p[0]) cout << p[0] - a << endl;
        else if (a > p[1]) cout << a - p[1] << endl;
        if (a > p[0] && a < p[1]) cout << min(a - p[0], p[1] - a) << endl;
        return 0;
    }
    if (a <= p[0]) return cout << p[n - 2] - a << endl, 0;
    if (a >= p[n - 1]) return cout << a - p[1] << endl, 0;
    int ans = inf;
    if (a >= p[0] && a <= p[1]) {
        ans = p[n - 1] - a;
        if (p[n - 2] >= a) ans = min(ans, 2 * (a - p[0]) + p[n - 2] - a);
        // cout << ans << endl;
        // return 0;
    }
    if (a >= p[n - 2] && a <= p[n - 1]) {
        ans = min(ans, a - p[0]);
        if (p[1] <= a) ans = min(ans, 2 * (p[n - 1] - a) + a - p[1]);
    }
    if (p[n - 1] >= a && a >= p[1]) ans = min(ans, 2 * (p[n - 1] - a) + a - p[1]), ans = min(ans, 2 * (a - p[1]) + p[n - 1] - a);
    if (p[n - 2] >= a && a >= p[0]) ans = min(ans, 2 * (p[n - 2] - a) + a - p[0]), ans = min(ans, 2 * (a - p[0]) + p[n - 2] - a);
    cout << ans << endl;
    return 0;
}