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
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            kek.insert(a[j] - a[i]);
    }
    cout << kek.size() << "\n";
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