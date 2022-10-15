#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n, h, m, k; cin >> n >> h >> m >> k;

	m /= 2;

	vi T;

    vi H(n), M(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> H[i] >> M[i];

		M[i] %= m;

		T.pb((M[i] + 1) % m);
		T.pb((M[i] + k) % m);
    }
	T.pb(0);

	sort(ALL(T));
	T.erase(unique(ALL(T)), T.end());

	int L = SZ(T);

	map<int, int> pos;
	for (int z = 0; z < L; ++z)
		pos[T[z]] = z;

	vll dp(L, 0);
	for (int i = 0; i < n; ++i)
	{
		if (m - k <= M[i] && M[i] < m - 1)
		{
			dp[pos[(M[i] + 1) % m]] += 1;
			dp[pos[0]] += 1;
			dp[pos[(M[i] + k) % m]] += -1;
		}
		else
			dp[pos[(M[i] + 1) % m]] += 1, dp[pos[(M[i] + k) % m]] += -1;
	}

	int t = 0;
	for (int z = 1; z < L; ++z)
	{
		dp[z] += dp[z - 1];
		if (dp[z] < dp[t])
			t = z;
	}

	vi ans;
	for (int i = 0; i < n; ++i)
		if ((M[i] + 1 <= T[t] && T[t] <= M[i] + k - 1) || (M[i] + 1 <= m + T[t] && m + T[t] <= M[i] + k - 1))
			ans.pb(i);

	assert(dp[t] == SZ(ans));

	cout << dp[t] << " " << T[t] << endl;
	for (auto i : ans)
		cout << i + 1 << " ";
	cout << endl;

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/