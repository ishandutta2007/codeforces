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

auto sieve(int N)
{
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

int main()
{ _
    constexpr int N = 1e6, emax = 20;
    auto [lp, pr] = sieve(N);

    int t; cin >> t;

    constexpr ll mod = 1e9 + 7;

    vector<ll> f(N + emax, 1), inv(N + emax, 1);
    for (int e = 1; e < N + emax; ++e)
    {
        f[e] = e * f[e - 1] % mod;
        inv[e] = modpow(f[e], mod - 2, mod);
    }

    while (t--)
    {
        int x, y; cin >> x >> y;

        ll ans = 1LL;

        while (x > 1)
        {
            int p = lp[x], e = 0;
            while (x % p == 0) x /= p, e += 1;

            ans = ans * f[e + y - 1] % mod;
            ans = ans * inv[e] % mod;
            ans = ans * inv[y - 1] % mod;
        }

        ans = ans * modpow(2, y - 1, mod) % mod;

        cout << ans << endl;
    }


    exit(0);
}