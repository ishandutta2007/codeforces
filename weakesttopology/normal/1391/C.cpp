#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

const ll MOD = (int)1e9 + 7;

ll power(ll x, int p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = (x * r) % MOD;
        p >>= 1;
        x = (x * x) % MOD;
    }
    return r;
}

int main()
{ _
    int n; cin >> n;

    vll f(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i)
    {
        f[i] = (i * f[i - 1]) % MOD;
        inv[i] = power(f[i], MOD - 2);
    }

    auto binom = [&f, &inv](int n, int k)
    {
        return (f[n] * inv[k] % MOD) * inv[n - k] % MOD;
    };

    ll ans = f[n];
    for (int i = 1; i <= n; ++i)
        ans = (ans - binom(n - 1, i - 1)) % MOD;
    ans = (ans + MOD) % MOD;

    cout << ans << endl;

    exit(0);
}