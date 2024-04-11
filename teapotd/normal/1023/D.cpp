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


int n, q;
Vi pattern;

void check() {
	Vi sim(n);
	int high = -1;

	rep(i, 1, q+1) {
		int beg = n+1, end = 0;

		rep(j, 0, n) if (pattern[j] == i) {
			beg = min(beg, j);
			end = max(end, j+1);
		}

		rep(j, beg, end) sim[j] = i;
		if (beg < end) high = i;
	}

	deb(pattern);
	deb(sim);
	assert(high == q);
	rep(i, 0, n) assert(pattern[i] == sim[i] && sim[i] != 0);
}

void nope() {
	cout << "NO\n";
	//assert(0);
	exit(0);
}

void run() {
	cin >> n >> q;
	pattern.resize(n);

	vector<Pii> inters(q+1, {-1, -1});
	int high = 0;

	rep(i, 0, n) {
		auto& p = pattern[i];
		cin >> p;
		if (inters[p].x < 0) inters[p].x = i;
		inters[p].y = i;
		high = max(high, p);
	}

	if (high != q && inters[0].x < 0) nope();

	int last = -1;
	rep(i, 0, q) if (inters[q-i].x < 0) {
		last = q-i;
		break;
	}
	
	if (last == -1) {
		rep(i, 0, n) if (pattern[i] != 0) {
			last = pattern[i];
			break;
		}
	}

	if (inters[q].x < 0) {
		rep(i, 0, n) if (pattern[i] == 0) {
			pattern[i] = q;
			break;
		}
	}

	set<int> open;

	rep(i, 0, n) {
		int& p = pattern[i];
		//deb(i, p, open, pattern);

		if (!open.empty()) {
			if (p == 0) {
				p = *open.rbegin();
			}
			else if (*open.rbegin() > p) nope();
		} else if (p == 0) {
			p = last;
		}

		if (inters[p].x == i) {
			open.insert(p);
		}
		if (inters[p].y == i) {
			open.erase(p);
		}
		last = p;
	}

#ifdef LOC
	check();
#endif

	cout << "YES\n";
	each(c, pattern) cout << c << ' ';
	cout << endl;
}