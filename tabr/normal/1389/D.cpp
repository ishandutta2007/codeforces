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
        ll n, k;
        cin >> n >> k;
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 == l2) {
            if (r1 > r2) {
                swap(r2, r1);
            }
        }
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        ll inter = max(0LL, min(r1, r2) - l2);
        ll cur = inter * n;
        ll ans = 1e18;
        ll add = max(r1, r2) - l1 - inter;
        ll cost = add + max(0LL, l2 - r1);
        for (int i = 0; i < n; i++) {
            ll sum = cur + add * i;
            ll tmp = cost * i;
            if (sum < k) {
                tmp += max(0LL, l2 - r1);
                if (sum + add < k) {
                    sum += add;
                    tmp += add;
                    tmp += (k - sum) * 2;
                } else {
                    tmp += k - sum;
                }
            }
            ans = min(tmp, ans);
        }
        cout << ans << '\n';
    }
    return 0;
}