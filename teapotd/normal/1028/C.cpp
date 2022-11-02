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

struct Rect {
	int a, b, c, d;
};

vector<Rect> rects;

Rect isect(Rect x, Rect y) {
	return { max(x.a, y.a), max(x.b, y.b), min(x.c, y.c), min(x.d, y.d) };
}

void solve(int b, int e, Rect part) {
	if (b >= e) return;

	if (b+1 == e) {
		if (part.a <= part.c && part.b <= part.d) {
			cout << part.a << ' ' << part.b << endl;
			exit(0);
		}
		return;
	}

	Rect left = part, right = part;
	int m = (b+e) / 2;

	rep(i, b, m) left = isect(left, rects[i]);
	rep(i, m, e) right = isect(right, rects[i]);

	solve(b, m, right);
	solve(m, e, left);
}

void run() {
	int n; cin >> n;
	rects.resize(n);

	each(r, rects) cin >> r.a >> r.b >> r.c >> r.d;

	solve(0, n, { INT_MIN, INT_MIN, INT_MAX, INT_MAX });
}