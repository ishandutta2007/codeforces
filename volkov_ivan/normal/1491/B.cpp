#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    int a[n + 1];
    bool has_wall = 1;
    bool all_same = 1;
    int lst = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1)
            lst = a[i];
        if (abs(a[i] - lst) > 1)
            has_wall = 0;
        if (a[i] != lst)
            all_same = 0;
        lst = a[i];
    }
    if (!has_wall) {
        cout << 0 << "\n";
        return;
    }
    if (!all_same) {
        cout << min(v, u) << "\n";
        return;
    }
    cout << v + min(v, u) << "\n";
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