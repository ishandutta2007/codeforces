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

int main()
{ _
    int n, d, m; cin >> n >> d >> m;
    vector big(0, 0LL), small(0, 0LL);
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        if (a > m) big.push_back(a);
        else small.push_back(a);
    }

    sort(all(big)), reverse(all(big));
    sort(all(small));

    for (int i = 1; i < sz(big); ++i)
        big[i] += big[i - 1];
    for (int i = 1; i < sz(small); ++i)
        small[i] += small[i - 1];

    if (sz(big) == 0)
    {
        cout << small.back() << endl;
        exit(0);
    }

    if (sz(small) == 0)
    {
        cout << big[(n + d) / (d + 1) - 1] << endl;
        exit(0);
    }

    ll ans = small.back() + big[0];
    for (int i = 0; i < min(sz(big), (n + d) / (d + 1)); ++i)
    {
        ll sum = big[i] + small.back();
        int num_small = i * d - (sz(big) - (i + 1));
        if (num_small > 0)
            sum -= small[num_small - 1];
        ans = max(ans, sum);
    }

    cout << ans << endl;

    exit(0);
}