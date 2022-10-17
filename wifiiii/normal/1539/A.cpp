#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // t / x
    int k;
    cin >> k;
    while(k--) {
        int n, x, t;
        cin >> n >> x >> t;
        // 0, 1, 2, ..., n, ..., t/x
        int up = min(n - 1, t / x);
        ll ans = 1ll * up * (up + 1) / 2;
        ans += 1ll * (n - 1 - up) * up;
        cout << ans << '\n';
    }
}