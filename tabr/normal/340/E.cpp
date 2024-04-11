#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

struct combination {
    ll mod;
    vector<ll> fac, finv, inv;

    combination(int n, ll m) : fac(n), finv(n), inv(n) {
        mod = m;
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }

    ll C(int n, int k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b;
    set<int> st;
    rep(i, 1, n + 1) st.insert(i);
    rep(i, 0, n) {
        cin >> a[i];
        if (a[i] == -1)
            b.push_back(i + 1);
        else
            st.erase(a[i]);
    }
    int m = 0, k = 0;
    for (auto x : b) {
        m++;
        if (st.find(x) != st.end())
            k++;
    }
    ll ans = 0, mod = 1e9 + 7;
    combination cm(m + 1, mod);
    rep(i, 0, k + 1) {
        ll sum = cm.C(k, i) * cm.fac[m - i] % mod;
        if (i % 2)
            sum *= -1;
        ans = (ans + sum + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}