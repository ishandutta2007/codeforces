#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    int ll = x, rr = x;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a <= rr) rr = max(rr, b);
        if (ll <= b) ll = min(ll, a);
    }
    cout << rr - ll + 1 << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}