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

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

vector<Vi> G, post;
vector<Pii> dp;
Vi ans;

void postOrder(int v, int p) {
	Vi children;
	each(e, G[v]) if (e != p) {
		postOrder(e, v);
		children.pb(sz(post)-1);
	}
	post.pb(move(children));
}

int f(int k) {
	if (ans[k-1] >= 0) return ans[k-1];

	rep(i, 0, sz(post)) {
		int sum = 0, m1 = 0, m2 = 0;

		each(e, post[i]) {
			int len = dp[e].y;
			sum += dp[e].x;
			if (len >= m1) {
				m2 = m1;
				m1 = len;
			} else if (len > m2) {
				m2 = len;
			}
		}

		if (m1+m2+1 >= k) {
			dp[i] = { sum+1, 0 };
		} else {
			dp[i] = { sum, m1+1 };
		}
	}

	return ans[k-1] = dp.back().x;
}

void solve(int b, int e) {
	if (f(b) == f(e-1)) {
		rep(i, b, e) ans[i-1] = f(b);
	} else {
		int m = (b+e) / 2;
		solve(b, m);
		solve(m, e);
	}
}

void run() {
	int n; cin >> n;
	G.resize(n);
	ans.resize(n, -1);

	rep(i, 1, n) {
		int a, b; cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}

	postOrder(0, -1);
	dp.resize(sz(post));

	int naive = int(sqrt(n * log2(n)));
	rep(i, 1, naive) f(i);

	solve(naive, n+1);
	each(x, ans) cout << x << '\n';
}