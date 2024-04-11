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

ll count(ll lim) {
	vector<Pii> pos;
	for (int i = 0; lim != 0; i++, lim /= 10) {
		if (lim%10) pos.pb({ i, lim%10 });
	}

	int ans = 0;
	reverse(all(pos));

	if (sz(pos) >= 1) {
		int x = pos[0].x, y = pos[0].y;
		ans += 1 + x*9 + x*(x-1)*81/2 + x*(x-1)*(x-2)*729/6;
		ans += (y-1) * (1 + x*9 + x*(x-1)*81/2);
	}

	if (sz(pos) >= 2) {
		int x = pos[1].x, y = pos[1].y;
		ans += 1 + x*9 + x*(x-1)*81/2;
		ans += (y-1) * (1 + x*9);
	}

	if (sz(pos) >= 3) {
		int x = pos[2].x, y = pos[2].y;
		ans += 1 + x*9;
		ans += y-1;
	}

	if (sz(pos) >= 4) {
		ans++;
	}
	return ans;
}

void run() {
	int q; cin >> q;

	while (q--) {
		ll L, R; cin >> L >> R;
		cout << count(R+1) - count(L) << '\n';
	}
}