#include <bits/stdc++.h>
//#define int long long

using namespace std;

mt19937 rnd(239);

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << x << "\n";
        return;
    }
    if (x > y) {
        cout << x + y << "\n";
        return;
    }
    int k = (y / 2) / (x / 2); 
    int n = (y + k * x) / 2;
    assert(n % x == y % n);
    cout << n << "\n";
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