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

using vec2 = pair<ll, ll>;

ll cross(vec2 a, vec2 b) {
	return a.x*b.y - a.y*b.x;
}

void run() {
	int n; cin >> n;
	vector<vec2> points(n);

	each(p, points) cin >> p.x >> p.y;
	sort(all(points), [](vec2 l, vec2 r) { return mp(l.y, l.x) < mp(r.y, r.x); });

	vector<pair<vec2, Pii>> segs;

	rep(i, 0, n) rep(j, i+1, n) {
		vec2 p = points[j], q = points[i];
		p.x -= q.x; p.y -= q.y;

		if (p.y < 0 || (p.y == 0 && p.x < 0)) {
			p.x = -p.x; p.y = -p.y;
			segs.pb({ p, {j,i} });
		} else {
			segs.pb({ p, {i,j} });
		}
	}

	sort(all(segs), [](pair<vec2, Pii> l, pair<vec2, Pii> r) {
		return cross(l.x, r.x) > 0;
	});

	Vi pos(n);
	iota(all(pos), 0);

	ll ans = 0;

	each(seg, segs) {
		assert(pos[seg.y.x]+1 == pos[seg.y.y]);
		ll k = pos[seg.y.x];
		ans += k*(k-1)/2 * (n-k-2)*(n-k-3)/2;

		swap(pos[seg.y.x], pos[seg.y.y]);
		swap(points[seg.y.x], points[seg.y.y]);
	}

	cout << ans << endl;
}