#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int mx = 0, num_mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > mx) {
                mx = a[i], num_mx = 1;
            }
            else if (a[i] == mx) {
                ++num_mx;
            }
        }
        long long ans = 1LL;
        long long MOD = 998244353;
        if (num_mx > 1) {
            for (int i = 1; i <= n; i++) {
                ans *= i, ans %= MOD;
            }
        }
        else {
            int sec_mx = 0, num_sec_mx = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == mx) continue;
                if (a[i] > sec_mx) {
                    sec_mx = a[i], num_sec_mx = 1;
                }
                else if (a[i] == sec_mx) {
                    ++num_sec_mx;
                }
            }
            if (sec_mx < mx - 1) {
                ans = 0;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    if (i != num_sec_mx + 1) {
                        ans *= i, ans %= MOD;
                    }
                }
                ans *= num_sec_mx, ans %= MOD;
            }
        }
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
}