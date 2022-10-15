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
    ll res = 1; x = x % MOD;
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
    int n, m; cin >> n >> m;
    vector d(n, 0LL);
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
    }
    sort(all(d));

    auto prefix = d; prefix[0] %= MOD;
    for (int i = 1; i < n; ++i)
         prefix[i] = (prefix[i] + prefix[i - 1]) % MOD;

    auto query = [&prefix](int l, int r)
    {
        if (r < l) return 0LL;
        if (l == 0) return prefix[r];
        return (prefix[r] - prefix[l - 1] + MOD) % MOD;
    };

    for (int j = 0; j < m; ++j)
    {
        ll a, b; cin >> a >> b;

        int k = distance(d.begin(), lower_bound(all(d), b));

        int x = n - k;

        ll strong = (query(k, n - 1) * max(0LL, x - a) % MOD) * power(x, MOD - 2) % MOD;
        ll weak = (query(0, k - 1) * max(0LL, x + 1 - a) % MOD) * power(x + 1, MOD - 2) % MOD;
        ll ans = (strong + weak) % MOD;

        cout << ans << endl;
    }

    exit(0);
}