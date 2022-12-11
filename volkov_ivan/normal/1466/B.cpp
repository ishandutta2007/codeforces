#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    set <int> kek;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n - 1]++;
    int cnt_diff = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] + 1 < a[i + 1])
            a[i]++;
        if (a[i] != a[i + 1])
            cnt_diff++;
    }
    cout << cnt_diff << "\n";
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
}