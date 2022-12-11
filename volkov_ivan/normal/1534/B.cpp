#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans += abs(a[i] - a[i - 1]);        
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            int t = min(a[i] - a[i - 1], a[i] - a[i + 1]);
            ans -= t;
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}