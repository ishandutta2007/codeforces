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

void run() {
	ll n; cin >> n;
	vector<ll> growth[2];

	each(a, growth) {
		a.resize(n);
		each(x, a) cin >> x;
	}

	ll pref = 0;
	rep(i, 0, n) {
		if (i % 2) {
			pref += (i*2+1) * growth[0][i];
			pref += i*2 * growth[1][i];
		} else {
			pref += i*2 * growth[0][i];
			pref += (i*2+1) * growth[1][i];
		}
	}

	ll fromUp = 0, fromDown = 0;
	ll best = pref, add = 0;

	for (ll i = n-1; i >= 0; i--) {
		deb(fromUp, fromDown, pref, best, add);

		if (i % 2) {
			best = max(best, pref + fromUp);
			pref -= growth[0][i]*(i*2+1) + growth[1][i]*(i*2);
		} else {
			best = max(best, pref + fromDown);
			pref -= growth[0][i]*(i*2) + growth[1][i]*(i*2+1);
		}

		fromUp += growth[0][i]*(i*2) + growth[1][i]*(n*2-1) - add;
		fromDown += growth[1][i]*(i*2) + growth[0][i]*(n*2-1) - add;
		add += growth[0][i] + growth[1][i];
	}

	best = max(best, fromUp);

	cout << best << endl;
}