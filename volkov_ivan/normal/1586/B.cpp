#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <bool> used(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        used[b] = 1;
    }
    int x = -1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            x = i;
            break;
        }
    }
    assert(x != -1);
    for (int i = 1; i <= n; i++) {
        if (i != x) {
            cout << i << ' ' << x << "\n";
        }
    }
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