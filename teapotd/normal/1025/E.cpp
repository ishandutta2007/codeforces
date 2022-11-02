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

using Op = pair<Pii, Pii>;

void moveX(vector<Op>& ops, Pii& pos, int to) {
	while (pos.x != to) {
		if (pos.x < to) {
			ops.pb({ pos, {pos.x+1, pos.y} });
			pos.x++;
		} else {
			ops.pb({ pos, {pos.x-1, pos.y} });
			pos.x--;
		}
	}
}

void moveY(vector<Op>& ops, Pii& pos, int to) {
	while (pos.y != to) {
		if (pos.y < to) {
			ops.pb({ pos, {pos.x, pos.y+1} });
			pos.y++;
		} else {
			ops.pb({ pos, {pos.x, pos.y-1} });
			pos.y--;
		}
	}
}

vector<Op> compute(int count) {
	vector<Pii> pos(count);
	vector<Op> ops;

	each(p, pos) cin >> p.x >> p.y;

	Vi sorted(count);
	iota(all(sorted), 0);
	sort(all(sorted), [&](int l, int r) { return pos[l].x < pos[r].x; });

	bool cont = true;
	while (cont) {
		cont = false;

		rep(j, 1, count+1) {
			auto& p = pos[sorted[j-1]];
			if (p.x == j) continue;
			cont = true;

			int minX = min(j, p.x), maxX = max(j, p.x);
			bool ok = true;

			each(q, pos) if (&q != &p) {
				if (p.y == q.y && q.x >= minX && q.x <= maxX) {
					ok = false;
					break;
				}
			}

			if (ok) moveX(ops, p, j);
		}
	}

	rep(i, 0, count) moveY(ops, pos[i], i+1);
	rep(i, 0, count) moveX(ops, pos[i], i+1);
	return ops;
}

void run() {
	int n, m; cin >> n >> m;
	auto first = compute(m);
	auto second = compute(m);

	reverse(all(second));
	cout << sz(first)+sz(second) << '\n';
	each(e, first)  cout << e.x.x << ' ' << e.x.y << ' ' << e.y.x << ' ' << e.y.y << '\n';
	each(e, second) cout << e.y.x << ' ' << e.y.y << ' ' << e.x.x << ' ' << e.x.y << '\n';
}