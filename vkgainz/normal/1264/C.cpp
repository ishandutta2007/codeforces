#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long MOD = 998244353;

long long inv(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

long long den = inv(100);

vector<long long> pref, f;

long long eval(int l, int r) {
     // find f[l...r]
     long long ans = f[r - 1];
     if (l - 2 >= 0) ans -= f[l - 2];
     ans *= inv(pref[r]);
     ans %= MOD;
     return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    pref.resize(n + 1), f.resize(n + 1);
    f[0] = 1LL, pref[0] = 1LL;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] * den % MOD;
        pref[i] *= p[i - 1];
        pref[i] %= MOD;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + pref[i];
        f[i] %= MOD;
    }
    set<int> covered;
    covered.insert(1);
    covered.insert(n + 1);
    long long ans = eval(1, n);
    while (q--) {
        int u; cin >> u;
        if (covered.count(u)) {
            int upp = *(covered.upper_bound(u));
            int low = *(--covered.lower_bound(u));
            ans += eval(low, upp - 1);
            ans -= eval(low, u - 1) + eval(u, upp - 1);
            covered.erase(u);
        }
        else {
            int upp = *(covered.upper_bound(u));
            int low = *(--covered.upper_bound(u));
            ans -= eval(low, upp - 1);
            ans += eval(low, u - 1) + eval(u, upp - 1);
            covered.insert(u);
        }
        ans %= MOD;
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
}