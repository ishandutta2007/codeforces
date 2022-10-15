#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int mx = 0;
        if (i + 1 < n) {
            mx = max(mx, a[i + 1]);
            ans += abs(a[i] - a[i + 1]);
        }
        else ans += a[i];
        if (i > 0) {
            mx = max(mx, a[i - 1]);
        }
        else ans += a[i];
        if (mx < a[i]) ans -= a[i] - mx;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}