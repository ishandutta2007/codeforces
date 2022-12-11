#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int res = abs(x1 - x2) + abs(y1 - y2);
    if (x1 != x2 && y1 != y2) res += 2;
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}