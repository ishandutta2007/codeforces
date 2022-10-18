#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> ans(r - l + 1, 1);
        ll cnt = 0;
        ll nxt = (n - 1) * 2;
        ll lev = 1;
        ll lst = n * (n - 1) + 1;
        for (ll i = 1; i <= r; i++) {
            if (i == lst) {
                break;
            }
            if (cnt == 0 && nxt != 0 && i + nxt <= l) {
                i += nxt;
                i--;
                lev++;
                nxt -= 2;
                continue;
            }
            if (cnt == nxt) {
                cnt = 0;
                lev++;
                nxt -= 2;
            }
            ll res = lev;
            if (cnt % 2 == 1) {
                res += (cnt + 1) / 2;
            }
            cnt++;
            if (l <= i) {
                ans[i - l] = res;
            }
        }
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}