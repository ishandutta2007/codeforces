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

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

const ll MOD = 1e9 + 7;

ll solve()
{
    ll p, k; cin >> p >> k;

    ll x = 1;
    for (int i = 0; i < p - 1; ++i)
        x = (x * p) % MOD;

    if (k == 0) return x;
    if (k == 1) return (x * p) % MOD;

    int subgroup_order = 1;
    for (ll h = k; h != 1; h = (h * k) % p, ++subgroup_order);

    ll ans = 1;
    for (int i = 0; i < (p - 1) / subgroup_order; ++i)
        ans = (ans * p) % MOD;

    return ans;
}

int main()
{ _
    cout << solve() << endl;
    exit(0);
}