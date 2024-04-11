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
    ll x, y, p, q; cin >> x >> y >> p >> q;

    if (p == 1 && q == 1)
    {
        return x == y ? 0 : -1;
    }
    if (p == 0)
    {
        return x == 0 ? 0 : -1;
    }

    auto check = [&](ll k)
    {
        ll b = k * q - y, a = p * k - x;
        return k * q >= y && k * p >= x && a <= b;
    };

    ll k = 0LL;

    for (ll z = 1e9; z; z >>= 1) while (not check(k + z)) k += z;

    k += 1;

    ll ans = k * q - y;

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}