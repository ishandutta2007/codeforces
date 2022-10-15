#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const ll MOD = 998244353LL;

ll power(ll x, int p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1) res = (res * x) % MOD;
        p >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main()
{ _
    int n, k; cin >> n >> k;

    vector E(0, pair(0, 0));
    for (int i = 0; i < n; ++i)
    {
        int l, r; cin >> l >> r;
        E.emplace_back(l, 1);
        E.emplace_back(r + 1, -1);
    }
    sort(all(E));

    vector f(n + 1, 1LL), inv(n + 1, 1LL);
    for (int i = 1; i <= n; ++i)
        f[i] = (i * f[i - 1]) % MOD, inv[i] = power(f[i], MOD - 2);

    auto C = [&f, &inv](int n, int k)
    {
        return (f[n] * inv[k] % MOD) * inv[n - k] % MOD;
    };

    int ct = 0;
    ll ans = 0;

    for (auto [__, b] : E)
    {
        if (b == 1 && ct >= k - 1) ans = (ans + C(ct, k - 1)) % MOD;
        ct += b;
    }

    cout << ans << endl;

    exit(0);
}