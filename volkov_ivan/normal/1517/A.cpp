#include <bits/stdc++.h>
//#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; 
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        if (n % 2050 != 0) {
            cout << "-1\n";
            continue;
        }
        long long r = n / 2050;
        int ans = 0;
        while (r > 0) {
            ans += r % 10;
            r /= 10;
        }
        cout << ans << "\n";
    }
    return 0;
}