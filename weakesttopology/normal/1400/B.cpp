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

ll solve()
{
    ll p, f; cin >> p >> f;
    ll cts, ctw; cin >> cts >> ctw;
    ll ws, ww; cin >> ws >> ww;

    if (p < f) swap(p, f);
    if (ws > ww) swap(ws, ww), swap(cts, ctw);

    vector a(cts + 1, 0LL), b(cts + 1, 0LL);

    for (int x = 0; x <= cts; ++x)
        if (x * ws <= p) a[x] = min(ctw, (p - x * ws) / ww);
    for (int x = 0; x <= cts; ++x)
        if (x * ws <= f) b[x] = min(ctw, (f - x * ws) / ww);

    ll ans = 0;
    for (int x = 0; x <= cts; ++x)
    {
        if (x * ws > p) continue;
        ll y = min(cts - x, f / ws);
        ans = max(ans, x + y + min(ctw, a[x] + b[y]));
    }
    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}