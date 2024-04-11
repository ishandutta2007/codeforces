#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n], c[n], ans[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    ans[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (i != n - 1) {
            ans[i] = a[i];
            if (ans[i] == ans[i - 1]) ans[i] = b[i];
        } else {
            ans[i] = a[i];
            if (ans[i] == ans[i - 1] || ans[i] == ans[0]) ans[i] = b[i];
            if (ans[i] == ans[i - 1] || ans[i] == ans[0]) ans[i] = c[i];
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}