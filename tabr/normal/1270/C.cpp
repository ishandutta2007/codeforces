#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll x = 0, y = 0;
        rep(i, 0, n) {
            cin >> a[i];
            x += a[i];
            y ^= a[i];
        }
        ll b1 = y;
        y = 0;
        x += b1;
        cout << 2 << endl;
        cout << b1 << ' ' << x << endl;
    }
    return 0;
}