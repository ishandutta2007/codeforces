#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_];
#define SZ(X) (int)X.size()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// </template>

int main()
{ _
	int n; cin >> n;
	vi p(n); READ(p);

	vi K(n); K[0] = 0;
	for (int i = 1; i < n; ++i)
		K[i] = i ^ K[i - 1];

	int ans = accumulate(ALL(p), 0, [](int a, int b){ return a ^ b; });

	for (int j = 1; j <= n; ++j)
		ans ^= (((n / j) % 2) * K[j - 1]) ^ K[n % j];

	cout << ans << endl;

    exit(0);
}

/*
 * INT_MAX      = 2^31 - 1  ~  2 * 1e09
 * LLONG_MAX    = 2^63 - 1  ~  9 * 1e18
 * ULLONG_MAX   = 2^64 - 1  ~ 18 * 1e18
 *
 * DBL_MAX ~ 1.79769e+308
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
*/