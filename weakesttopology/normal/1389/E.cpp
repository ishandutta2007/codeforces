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

ll solve(ll N, ll q)
{
    if (N < q) return 0;
    ll x = (N + 1) / q, r = N - q * x + 1;

    ll ans = q * x * (x - 1) / 2 + x * r + solve(N - q * x, q);

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        ll m, d, w; cin >> m >> d >> w;

        ll ans = solve(min(m, d) - 1, w / gcd(w, d - 1));
        cout << ans << endl;
    }


    exit(0);
}