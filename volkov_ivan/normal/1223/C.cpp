#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n;
    int v[n + 1];
    int pref[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] /= 100;
    }
    sort(v + 1, v + n + 1, greater <int>());
    int x, a, y, b;
    cin >> x >> a >> y >> b >> k;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];
    int c = (a * b) / __gcd(a, b);
    for (int i = 1; i <= n; i++) {
        int cnt1 = i / a, cnt2 = i / b, cnt3 = i / c;
        cnt2 -= cnt3;
        int cur = 0;
        cur = pref[cnt1] * x;
        cur += pref[cnt3] * y;
        cur += (pref[cnt1 + cnt2] - pref[cnt1]) * y;
        if (cur >= k) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) solve();
    return 0;
}