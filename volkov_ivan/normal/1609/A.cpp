#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sm = 0, maxi = 0, pw = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x % 2 == 0) {
            x /= 2;
            pw *= 2;
        }
        sm += x;
        maxi = max(maxi, x);
    }
    cout << (sm - maxi) + maxi * pw << "\n";
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