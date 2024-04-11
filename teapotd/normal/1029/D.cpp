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

const size_t HXOR = mt19937_64(time(0))();
template<class T> struct SafeHash {
	size_t operator()(const T& x) const {
		return hash<T>()(x ^ T(HXOR));
	}
};

unordered_map<int, int, SafeHash<int>> mods[10];

int len(int x) {
	int m = 10;
	for (int i = 1;; i++) {
		if (x < m) return i;
		m *= 10;
	}
}

void run() {
	int n, k; cin >> n >> k;

	Vi elems(n);
	ll ans = 0;

	each(e, elems) {
		cin >> e;

		uint64_t m = e;
		rep(i, 0, 10) {
			m *= 10;
			mods[i][int(m%k)]++;
		}

		ll tmp = 10;
		while (tmp <= e) tmp *= 10;
		uint64_t cand = uint64_t(e)*tmp + e;
		if (cand%k == 0) ans--;
	}

	each(e, elems) {
		int m = e%k;
		if (m > 0) m = k-m;
		ans += mods[len(e)-1][m];
	}

	cout << ans << endl;
}