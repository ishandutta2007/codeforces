#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    if(__builtin_popcountll(n) == 1) {
        return -1;
    }
    ll ans = -1;
    for(int i = 1; i <= 31; ++i) {
        ll x = (1ll << i) * ((1ll << i) + 1) / 2;
        if(n >= x && (n - x) % (1ll << i) == 0) {
            return 1ll << i;
        }
    }
    if(ans == -1) {
        ll p = n;
        while(n % 2 == 0) n /= 2;
        if(n <= 2e9) {
            ll q = n;
            ll x = q * (q + 1) / 2;
            n = p;
            if(n >= x && (n - x) % q == 0) {
                return q;
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}