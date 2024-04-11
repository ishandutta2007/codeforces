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
    while (p)
    {
        if (p & 1) res = res * x % mod;
        x = x * x % mod, p >>= 1;
    }
    return res;
}

int main()
{ _
    int n; cin >> n;

    const ll mod = 998244353LL;

    ll inv = modpow(2, mod - 2, mod);

    ll even = 0LL, odd = 1LL, ans = 0LL;

    for (int x = 1; x <= n; ++x)
    {
        ans = inv * odd % mod;

        even = ((even * inv % mod) * inv % mod + ans) % mod;

        swap(even, odd);

        // for (int y = 0; 2 * y + 1 <= x; ++y)
        //     f[x] = (f[x] + pow[2 * y + 1] * f[x - (2 * y + 1)] % mod) % mod;
    }

    cout << ans << endl;

    exit(0);
}