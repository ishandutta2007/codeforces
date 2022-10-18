#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    vector<int> a(n), b(n), d(n);
    ll mod = 998244353, ans = 1, dif = 0, r = 1, l = 1;
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
        c[i] = make_pair(a[i], b[i]);
        ans = ans * (ll)(i + 1) % mod;
    }
    sort(c.begin(), c.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    rep(i, 0, n) d[i] = c[i].second;
    if (b == d) {
        ll k = 1;
        dif = 1;
        rep(i, 1, n) {
            if (c[i] == c[i - 1])
                k++;
            else
                k = 1;
            dif = dif * k % mod;
        }
    }
    ll k = 1;
    rep(i, 1, n) {
        if (a[i] == a[i - 1])
            k++;
        else
            k = 1;
        r = r * k % mod;
    }
    k = 1;
    rep(i, 1, n) {
        if (b[i] == b[i - 1])
            k++;
        else
            k = 1;
        l = l * k % mod;
    }
    cout << (ans - r - l + dif + 10LL * mod) % mod << endl;
    return 0;
}