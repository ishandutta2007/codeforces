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
using vvi = vector<vi>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int solve()
{
    int n, m; cin >> n >> m;
    vector<string> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
        ans += a[i][m - 1] != 'D';
    for (int j = 0; j < m - 1; ++j)
        ans += a[n - 1][j] != 'R';

    return ans;
}

int main()
{ _
    int t; cin >> t;

    while (t--)
        cout << solve() << endl;

    exit(0);
}