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

Vi E[4][4];
Pii sums[4][4]; // even, odd
int uses[4][4];
ll best = 0;

void check() {
	ll alt = 0;

	rep(i, 0, 4) rep(j, 0, 4) {
		if (i == j) {
			if (uses[i][i]) {
				alt += max(sums[i][i].x, sums[i][i].y);
			}
		} else {
			if (uses[i][j] > sz(E[i][j])) {
				return;
			}
			if (uses[i][j] == 0) continue;
			
			if (uses[i][j] % 2) {
				alt += sums[i][j].y;
			} else {
				alt += sums[i][j].x;
			}
		}
	}

	best = max(best, alt);
}

void makePath(int v, int len) {
	uses[v][v]++;
	check();
	if (len > 0) {
		rep(c, 0, 4) if (c != v) {
			uses[min(v,c)][max(v,c)]++;
			makePath(c, len-1);
			uses[min(v,c)][max(v,c)]--;
		}
	}
	uses[v][v]--;
}

void run() {
	int n; cin >> n;

	rep(i, 0, n) {
		int a, v, b;
		cin >> a >> v >> b;
		a--; b--;
		if (a > b) swap(a, b);
		E[a][b].pb(v);
	}

	rep(i, 0, 4) rep(j, 0, 4) {
		sort(all(E[i][j]));

		rep(k, 0, sz(E[i][j])) {
			int e = E[i][j][k];

			if (k == 0) {
				if (sz(E[i][j]) % 2) {
					sums[i][j].y += e;
				} else {
					sums[i][j].x += e;
				}
			} else {
				sums[i][j].x += e;
				sums[i][j].y += e;
			}
		}
	}

	rep(i, 0, 4) {
		makePath(i, 13);
	}

	cout << best << endl;
}