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

using Factor = pair<ll, int>;

vector<Factor> modFactors, phiFactors;

ll modAdd(ll x, ll y, ll m) {
	x += y;
	return (x < m ? x : x-m);
}

ll modSub(ll x, ll y, ll m) {
	x -= y;
	return (x >= 0 ? x : x+m);
}

ll modMul(ll x, ll y, ll m) {
	ll t = 0;
	while (y) {
		if (y & 1) t = modAdd(t, x, m);
		y >>= 1;
		x = modAdd(x, x, m);
	}
	return t;
}

ll modPow(ll x, ll e, ll m) {
	ll t = 1;
	while (e) {
		if (e & 1) t = modMul(t, x, m);
		e >>= 1;
		x = modMul(x, x, m);
	}
	return t;
}

vector<Factor> factorize(ll n) {
	vector<Factor> ret;

	for (ll i = 2; i*i <= n; i++) {
		Factor tmp = {i, 0};
		while (n%i == 0) {
			n /= i;
			tmp.y++;
		}
		if (tmp.y > 0) ret.pb(tmp);
	}

	if (n != 1) {
		if (ret.empty() || ret.back().x != n) {
			ret.pb({n, 1});
		} else {
			ret.back().y++;
		}
	}
	return ret;
}

ll getPhi(ll n, vector<Factor>& factors) {
	each(p, factors) if (p.y > 0) n = n / p.x * (p.x-1);
	return n;
}

ll reduceOrder(ll x, ll m, ll order) {
	x %= m;
	each(f, phiFactors) {
		while (order%f.x == 0) {
			ll alt = order / f.x;
			if (modPow(x, alt, m) != 1) break;
			order = alt;
		}
	}
	return order;
}

ll solve(ll x, ll m, ll order, int i) {
	if (i >= sz(modFactors)) {
		if (m <= 1) return 0;
		order = reduceOrder(x, m, order);
		ll phi = getPhi(m, modFactors);
		return phi / order;
	}

	int power = modFactors[i].y;
	ll ret = solve(x, m, order, i+1);

	rep(j, 0, power) {
		modFactors[i].y--;
		m /= modFactors[i].x;
		ret += solve(x, m, order, i+1);
	}

	modFactors[i].y = power;
	return ret;
}

void run() {
	ll m, x; cin >> m >> x;

	modFactors = factorize(m);
	ll phi = getPhi(m, modFactors);
	phiFactors = factorize(phi);

	ll order = reduceOrder(x, m, phi);
	cout << solve(x, m, order, 0)+1 << endl;
}