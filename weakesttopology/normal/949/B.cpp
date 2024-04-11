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

ll solve(ll x, ll n)
{
    if (x % 2) return (x + 1) / 2;

    return n / 2 + solve(x / 2 + (n % 2), n / 2 + (n % 2));
}

int main()
{ _
    ll n; cin >> n;
    int q; cin >> q;

    for (int z = 0; z < q; ++z)
    {
        ll x; cin >> x;

        cout << solve(x, n) << endl;
    }

    exit(0);
}