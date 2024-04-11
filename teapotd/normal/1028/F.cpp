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

ll dist(Pii p) {
	return ll(p.x)*p.x + ll(p.y)*p.y;
}

Pii norm(Pii p) {
	int g = __gcd(p.x, p.y);
	return { p.x/g, p.y/g };
}

Pii sym(Pii p, Pii q) {
	int dx = p.x+q.x, dy = p.y+q.y;
	return norm({ dx, dy });
}

void run() {
	int nQueries;
	cin >> nQueries;

	map<ll, set<Pii>> points;
	map<Pii, int> lines;
	int total = 0;

	while (nQueries--) {
		int t;
		Pii p;
		cin >> t >> p.x >> p.y;

		if (t == 1) {
			auto& vec = points[dist(p)];
			each(q, vec) lines[sym(p, q)] += 2;
			lines[norm(p)]++;
			vec.insert(p);
			total++;
		} else if (t == 2) {
			auto& vec = points[dist(p)];
			vec.erase(p);
			each(q, vec) lines[sym(p, q)] -= 2;
			lines[norm(p)]--;
			total--;
		} else if (t == 3) {
			cout << total-lines[norm(p)] << '\n';
		} else {
			assert(0);
		}
	}
}