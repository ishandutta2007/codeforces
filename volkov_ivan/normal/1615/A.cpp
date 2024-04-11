#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sm += x;
    }
    if (sm % n == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}