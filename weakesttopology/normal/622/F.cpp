#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// given that p(i) = y[i] for i = 0, ..., n - 1, finds p(x)

ll interpolate(ll x, const vector<ll>& y, ll mod)
{
    const int n = size(y);

    vector<ll> inv(n, 1), finv(n, 1);

    for (int i = 2; i < n; ++i)
    {
        inv[i] = -(mod / i) * inv[mod % i] % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }

    vector<ll> prefix(n, 1), suffix(n, 1);

    for (int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] * (x - (i - 1)) % mod;
    for (int i = n - 2; i >= 0; --i)
        suffix[i] = suffix[i + 1] * (x - (i + 1)) % mod;

    ll res = 0LL;

    for (int i = 0, sgn = (n % 2 ? +1 : -1); i < n; ++i, sgn *= -1)
    {
        ll coef = prefix[i] * suffix[i] % mod;
        (coef *= sgn * finv[i] * finv[n - 1 - i] % mod) %= mod;
        (res += y[i] * coef) %= mod;
    }

    return (res + mod) % mod;
}

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

int main()
{ _
    const ll mod = 1e9 + 7;

    ll n; cin >> n;
    int k; cin >> k;

    vector<ll> y(k + 2, 0);

    for (int x = 1; x <= k + 1; ++x)
        y[x] = (modpow(x, k, mod) + y[x - 1]) % mod;

    ll ans = interpolate(n, y, mod);

    cout << ans << endl;

    exit(0);
}