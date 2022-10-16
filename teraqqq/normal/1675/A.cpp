#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    cout << (max(0, x-a) + max(0, y-b) <= c ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}