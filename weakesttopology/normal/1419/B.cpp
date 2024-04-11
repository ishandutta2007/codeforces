#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll pa(ll n) { return n * (n + 1) / 2; }

ll solve()
{
    ll x; cin >> x;

    int ans = 0;

    for (ll n = 1; pa(n) <= x && pa(n) >= pa(n - 1); n = (n << 1) | 1)
        ++ans, x -= pa(n);

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}