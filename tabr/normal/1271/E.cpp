#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

ll n, k;
inline ll calc(ll x) { // x must be even
    ll res = 0, sum = 2;
    ll y = x;
    while (2LL * y <= n) {
        res += sum;
        sum *= 2LL;
        y *= 2LL;
    }
    res += min(n - y + 1, sum);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    if (n == k) {
        cout << 1 << endl;
        return 0;
    }
    if (k == 1) {
        cout << n << endl;
        return 0;
    }

    ll l = 2, r = n + 2 - (n % 2 == 1);
    while (r - l > 2) {
        ll m = (l + r) / 2;
        if (m % 2)
            m--;
        if (calc(m) >= k)
            l = m;
        else
            r = m;
    }
    if (calc(2 * (l + 1)) >= k - 1)
        l++;
    cout << l << endl;

    return 0;
}