#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

constexpr ll INF = 1e13;
constexpr int MAX_N = 6000;

ll elems[MAX_N], dp[3][MAX_N][2];

void run() {
	int n; cin >> n;
	rep(i, 0, n) cin >> elems[i+1];
	elems[0] = elems[n+1] = -1;

	int maxK = (n+1)/2;

	rep(k, 0, n) rep(x, 0, 2) dp[0][k][x] = dp[1][k][x] = INF;

	dp[0][0][0] = 0;
	dp[1][0][0] = 0;
	dp[1][1][1] = max(0ll, elems[2]-elems[1]+1);

	deb(span(dp[0], maxK+1, 2));
	deb(span(dp[1], maxK+1, 2));

	rep(i, 2, n+1) {
		auto &dp0 = dp[(i-2)%3], &dp1 = dp[(i-1)%3], &dp2 = dp[i%3];

		rep(k, 0, maxK+1) {
			dp2[k][0] = min(dp1[k][0], dp1[k][1]);
		}

		dp2[0][1] = INF;

		rep(k, 1, maxK+1) {
			ll add = max(0ll, elems[i+1]-elems[i]+1);
			ll one = dp0[k-1][0] + max(0ll, elems[i-1]-elems[i]+1);
			ll two = dp0[k-1][1] + max(0ll, min(elems[i-1], elems[i-2]-1) - elems[i] + 1);
			dp2[k][1] = min(one, two) + add;
		}

		deb(span(dp2, maxK+1, 2));
	}

	rep(k, 1, maxK+1) {
		auto& arr = dp[n%3][k];
		cout << min(arr[0], arr[1]) << ' ';
	}
	cout << endl;
}