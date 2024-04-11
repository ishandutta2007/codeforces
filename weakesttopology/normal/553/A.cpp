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

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

int main()
{ _
    int k; cin >> k;

    constexpr ll mod = 1e9 + 7, maxsum = 1000;

    vector<ll> f(maxsum + 1, 1), inv(maxsum + 1, 1LL);

    for (int x = 1; x <= maxsum; ++x)
    {
        f[x] = x * f[x - 1] % mod;
        inv[x] = modpow(f[x], mod - 2, mod);
    }

    ll sum = 0LL, res = 1LL;

    for (int j = 0; j < k; ++j)
    {
        ll ct; cin >> ct;

        res = ((res * f[sum + ct - 1] % mod) * inv[sum] % mod) * inv[ct - 1] % mod;

        sum += ct;
    }

    cout << res << endl;

    exit(0);
}