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
    ll a, b, c, d; cin >> a >> b >> c >> d;

    if (a > b * c) return -1;

    auto f = [&](ll t)
    {
        ll damage = t * a - (t - 1) * c * b;

        ll r = t - 1, l = max((t * d - c + 1 + d - 1) / d, 1LL);

        if (c > d && l <= r)
        {
            damage += b * (c - t * d) * (r - l + 1);
            damage += b * d * (r * (r + 1) - (l - 1) * l) / 2;
        }

        return damage;
    };

    ll t = 1;

    for (ll z = 1e6; z; z >>= 1) while (f(t + z) > f(t + z - 1)) t += z;

    return f(t);
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}