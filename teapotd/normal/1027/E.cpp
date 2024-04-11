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

constexpr ll MOD = 998244353;

struct Zp {
	ll x;
	Zp(ll a = 0) {
		if (a < 0) a = a%MOD + MOD;
		else if (a >= MOD*2) a %= MOD;
		else if (a >= MOD) a -= MOD;
		x = a;
	}

	Zp operator+(Zp r) const{ return x+r.x; }
	Zp operator-(Zp r) const{ return x-r.x+MOD; }
	Zp operator*(Zp r) const{ return x*r.x; }
	Zp operator/(Zp r) const{return x*r.inv().x;}
	Zp operator-()     const{ return MOD-x; }

	Zp inv() const { return pow(MOD-2); }

	Zp pow(ll e) const {
		Zp t = 1, m = *this;
		while (e) {
			if (e & 1) t *= m;
			e >>= 1; m *= m;
		}
		return t;
	}

	#define OP(c) Zp& operator c##=(Zp r){ \
		return *this=*this c r; }
	OP(+)OP(-)OP(*)OP(/)
	void print() { cerr << x; }
};

// ---

constexpr int MAX_N = 501;

Zp dp[MAX_N][MAX_N];
Zp without[MAX_N];

void run() {
	int n, k; cin >> n >> k;

	rep(i, 1, n+1) {
		each(x, dp[0]) x = 0;
		dp[0][0] = 1;

		rep(d, 1, n+1) {
			dp[d][0] = 0;
			rep(s, 1, i) dp[d][s] = dp[d-1][s-1];
			rep(j, 0, i) dp[d][1] += dp[d-1][j];
		}

		rep(j, 0, i) {
			without[i] += dp[n][j];
		}
	}

	Zp ans = 0;
	Zp total = Zp(2).pow(n);
	without[n+1] = total;

	rep(i, 1, min(n+1, k+1)) {
		int hei = (k+i-1) / i;
		if (hei > n) hei = n+1;

		Zp with1 = total - without[i];
		Zp with2 = total - without[i+1];
		Zp exact = with1-with2;
		ans += exact * without[hei];
	}

	ans /= 2;
	cout << ans.x << endl;
}