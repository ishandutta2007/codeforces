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

ll delay(ll k, ll R, ll x, ll y)
{
    if (k <= R - y) return 0LL;
    else return (k - (R - y) + (x - 1)) / x;
}

int main()
{ _
    ll k, L, R, t, x, y; cin >> k >> L >> R >> t >> x >> y;

    if (y <= x)
    {
        ll delta = delay(k, R, x, y);

        ll J = k - delta * x;

        ll maxt = J >= L ?
            (x != y ? delta + (J - L) / (x - y) : LINF) :
            (k - L + x - 1) / x;

        string ans = maxt >= t ? "Yes" : "No";

        cout << ans << endl;

        exit(0);
    }

    vector memo(x, -1LL);

    function<ll(ll)> solve = [&](ll k)
    {
        ll& res = memo[k % x];

        if (res != -1) return res;
        else res = LINF;

        ll delta = delay(k, R, x, y);

        res = (k - delta * x >= L) ?
            delta + 1 + solve(k - delta * x + (y - x)) : (k - L) / x;

        res = min(res, LINF);

        return res;
    };

    string ans = solve(k) >= t ? "Yes" : "No";

    cout << ans << endl;

    exit(0);
}