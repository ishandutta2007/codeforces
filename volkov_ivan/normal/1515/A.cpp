#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int pref = 0;
    for (int i = 0; i < n; i++) {
        pref += w[i];
        if (pref == x) {
            if (i == n - 1) {
                cout << "NO\n";
                return;
            }
            swap(w[i], w[i + 1]);
            break;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << w[i] << ' ';
    }
    cout << "\n";
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