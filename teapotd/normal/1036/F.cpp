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
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

constexpr int mobius[] = {
	0,1,-1,-1,0,-1,1,-1,0,0,1,-1,0,-1,1,1,0,-1,0,-1,0,
	1,1,-1,0,0,1,0,0,-1,-1,-1,0,1,1,1,0,-1,1,1,0,-1,
	-1,-1,0,0,1,-1,0,0,0,1,0,-1,0,1,0,1,1,-1,0,-1,1,0,
	0,1,-1,-1,0,1,-1,-1,0,-1,1,0,0,1,-1
};

ll safeMult(ll x, ll y) {
	if (x > (1<<30) && y > (1<<30)) {
		return 1LL<<60;
	}

	if (x < y) swap(x, y);

	if ((x>>30)*y > (1<<30)) {
		return 1LL<<60;
	}
	return x*y;
}

ll pow(ll m, ll e) {
	ll t = 1;
	while (e) {
		if (e & 1) t = safeMult(t, m);
		e >>= 1;
		m = safeMult(m, m);
	}
	return t;
}

ll base(ll n, ll e, ll hint) {
	ll begin = 1, end = hint;

	while (begin+1 < end) {
		ll mid = (begin+end) / 2;
		if (pow(mid, e) <= n) {
			begin = mid;
		} else {
			end = mid;
		}
	}
	return begin;
}

void run() {
	int q; cin >> q;

	while (q--) {
		ll n; cin >> n;
		ll ans = n-1, hint = n+1;

		for (int i = 2;; i++) {
			ll x = base(n, i, hint);
			hint = x+1;
			if (x <= 1) break;
			ans += (x-1) * mobius[i];
		}

		cout << ans << endl;
	}
}