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

ll solve()
{
    ll p, q; cin >> p >> q;

    if (p % q) return p;

    vector f(0, pair(0LL, 0));

    for (ll x = 2, r = q; true; ++x)
    {
        if (x * x > r)
        {
            if (r > 1) f.emplace_back(r, 1);
            break;
        }
        if (r % x == 0)
        {
            f.emplace_back(x, 0);
            while (r % x == 0) ++f.back().second, r /= x;
        }
    }

    ll ans = 0LL;

    for (auto [pr, e] : f)
    {
        ll r = p;
        while (r % pr == 0) r /= pr;

        for (int i = 0; i < e - 1; ++i) r *= pr;

        ans = max(ans, r);
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}