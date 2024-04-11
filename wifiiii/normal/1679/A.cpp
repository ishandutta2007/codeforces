#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n % 2 == 1 || n == 2) {
            cout << -1 << '\n';
        } else {
            ll mn = 8e18;
            for(int i = 0; i <= 2; ++i) {
                if(n >= 4 * i && (n - 4 * i) % 6 == 0) {
                    mn = min(mn, (n - 4 * i) / 6 + i);
                }
            }
            ll mx = -8e18;
            for(int i = 0; i <= 2; ++i) {
                if(n >= 6 * i && (n - 6 * i) % 4 == 0) {
                    mx = max(mx, (n - 6 * i) / 4 + i);
                }
            }
            cout << mn << ' ' << mx << '\n';
        }
    }
}