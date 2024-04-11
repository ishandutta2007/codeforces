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

double val(ll a, ll b) {
	ll u = a+b;
	return double(u*u) / double(a*b);
}

void solve() {
	int n; cin >> n;
	Vi elems(n);
	each(e, elems) cin >> e;
	sort(all(elems));

	vector<pair<int, bool>> avail;

	int i = 0;
	while (i < n) {
		int j = 1;
		while (i+1 < n && elems[i+1] == elems[i]) j++, i++;

		if (j >= 2) {
			avail.pb({elems[i], j >= 4});
		}
		i++;
	}

	double ans = INT_MAX;
	Pii parts;

	for (i = 0; i < sz(avail); i++) {
		if (avail[i].y) {
			double alt = val(avail[i].x, avail[i].x);
			if (alt < ans) {
				ans = alt;
				parts = {avail[i].x, avail[i].x};
			}
		}
		
		if (i > 0) {
			double alt = val(avail[i-1].x, avail[i].x);
			if (alt < ans) {
				ans = alt;
				parts = {avail[i-1].x, avail[i].x};
			}
		}
		
		if (i+1 < sz(avail)) {
			double alt = val(avail[i+1].x, avail[i].x);
			if (alt < ans) {
				ans = alt;
				parts = {avail[i+1].x, avail[i].x};
			}
		}
	}

	cout << parts.x << ' ' << parts.x << ' ' << parts.y << ' ' << parts.y << '\n';
}

void run() {
	int n; cin >> n;
	while (n--) solve();
}