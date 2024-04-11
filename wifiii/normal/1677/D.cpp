#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ok = 1;
        for(int i = n - 1; i >= n - k; --i) {
            if(a[i] != 0 && a[i] != -1) {
                ok = 0;
            } else {
                a[i] = 0;
            }
        }
        if(ok == 0) {
            cout << 0 << '\n';
            continue;
        }
        const int mod = 998244353;
        ll ans = 1;
        for(int i = 1; i <= k; ++i) ans = ans * i % mod;
        ll dp = k + 1;
        for(int i = 1; i < n - k; ++i) {
            if(a[i] == -1) {
                dp = dp * (k + 1 + i) % mod;
            } else if(a[i] == 0) {
                dp = dp * (k + 1) % mod;
            }
        }
        ans = ans * dp % mod;
        cout << ans << '\n';
    }
}