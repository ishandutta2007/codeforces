#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx")
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

constexpr ll MOD = 1000000007;

struct Zp {
	ll x;
	Zp(ll a = 0) { x=a%MOD; if (x<0) x+=MOD; }
	static Zp wrap(ll a){Zp t; t.x=a; return t;}

	Zp operator+(Zp r) const {
		ll a = x+r.x;
		return wrap(a >= MOD ? a-MOD : a);
	}

	Zp operator-(Zp r) const {
		ll a = x-r.x;
		return wrap(a < 0 ? a+MOD : a);
	}

	Zp operator*(Zp r) const {
		return wrap(x*r.x % MOD);
	}

	Zp operator/(Zp r) const {
		return wrap(x*r.inv().x % MOD);
	}

	Zp inv() const { return pow(MOD-2); }

	Zp pow(ll e) const {
		Zp t = wrap(1), m = *this;
		while (e) {
			if (e & 1) t *= m;
			e >>= 1;
			m *= m;
		}
		return t;
	}

	Zp& operator+=(Zp r){ return *this=*this+r; }
	Zp& operator-=(Zp r){ return *this=*this-r; }
	Zp& operator*=(Zp r){ return *this=*this*r; }
	Zp& operator/=(Zp r){ return *this=*this/r; }
	Zp operator-() const { return wrap(MOD-x); }

	DBP(x);
};

// ---

int n;
string original;
int prefs[205];
Zp dp0[205][205], dp1[205][205];

int moves[205][2];

int getPref(int j, char chr) {
	while (j >= 0 && chr != original[j]) j = prefs[j];
	return j+1;
}

void run() {
	cin >> n >> original;
	n *= 2;

	prefs[0] = -1;
	rep(i, 1, sz(original)+1) {
		prefs[i] = getPref(prefs[i-1], original[i-1]);
	}

	rep(i, 0, sz(original)+1) {
		moves[i][0] = getPref(i, '(');
		moves[i][1] = getPref(i, ')');
	}

	dp0[0][0] = 1;

	rep(i, 1, n+1) {
		memset(dp1, 0, sizeof(dp1));

		rep(k, 0, sz(original)) rep(l, 0, n/2+2) {
			dp1[moves[k][0]][l+1] += dp0[k][l];
			if (l > 0) {
				dp1[moves[k][1]][l-1] += dp0[k][l];
			}
		}

		swap(dp1, dp0);
	}

	Zp ret = Zp(n/2+1).inv();
	rep(i, n/2+1, n+1) ret *= i;
	rep(i, 2, n/2+1) ret /= i;
	rep(k, 0, sz(original)) ret -= dp0[k][0];

	cout << ret.x << endl;
}