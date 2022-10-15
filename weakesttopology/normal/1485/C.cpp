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
    ll x, y;
    cin >> x >> y;

    ll res = 0;

    ll b = 1;

    while (b <= y && b - 1 < x / (b + 1))
    {
        res += b - 1;
        ++b;
    }

    while (b <= y)
    {
        ll k = x / (b + 1);

        if (k == 0) break;

        ll bnxt = x / (x / (b + 1)) - 1;

        res += k * (min(y, bnxt) - b + 1);
        b = bnxt + 1;
    }

    return res;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}