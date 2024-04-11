#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(begin(a), end(a));
        sort(rbegin(b), rend(b));
        partial_sum(begin(a), end(a), begin(a));
        partial_sum(begin(b), end(b), begin(b));
        auto check = [&](ll k) {
            ll small = k / 4;
            ll x = a.back() + (k - n) * 100 - (small == 0 ? 0 : small <= n ? a[small - 1] : a.back() + (small - n) * 100);
            ll y = b[min<ll>(n, k - small) - 1];
            return x >= y;
        };
        ll L = n - 1, R = 1e9;
        while (L + 1 < R) {
            ll M = L + (R - L) / 2;
            check(M) ? R = M : L = M;
        }
        cout << R - n << '\n';
    }
    exit(0);
}