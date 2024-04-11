#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(const int n, const vector<int>& a) {
    int l = 0, r = 1e9+1;

    while (l + 1 != r) {
        int x = (l + r) / 2;

        vector<ll> v(n);
        for (int i = n; i--; ) v[i] = a[i];

        bool ok = true;

        for (int i = n - 1; i > 1; i--) {
            if (v[i] < x) {
                ok = false;
                break;
            }

            const int d = min<int>(a[i] / 3, (v[i] - x) / 3);
            v[i] -= 3 * d;
            v[i-1] += d;
            v[i-2] += 2*d;
        }

        for (ll t : v) if (t < x) ok = false;

        (ok ? l : r) = x;
    }

    return l;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int ans = solve(n, a);
        cout << ans << '\n';
    }
}