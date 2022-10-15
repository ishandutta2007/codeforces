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

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n, k, z; cin >> n >> k >> z;
        vll a(n); read(a);
        vll sum(n); sum[0] = a[0];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + a[i];
        vll maxp(n, 0); maxp[0] = 0;
        for (int i = 1; i < n; ++i)
            maxp[i] = max(maxp[i - 1], a[i - 1] + a[i]);
        ll ans = sum[k];
        for (int i = 1; i <= z && k - 2 * i >= 0; ++i)
            ans = max(ans, sum[k - 2 * i] + i * maxp[k - 2 * i]);
        --k, --z;
        for (int i = 0; i <= z && k - 2 * i - 1 >= 0; ++i)
            ans = max(ans, sum[k - 2 * i] + i * maxp[k - 2 * i] + a[k - 2 * i - 1]);
        cout << ans << endl;
    }
    exit(0);
}