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

constexpr ll MOD = 1e9+7;

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

vector<Zp> pointCovers, counts;

void run() {
	int n, k; cin >> n >> k;
	Vi seq(n);
	each(x, seq) cin >> x;

	Vi prev(n), next(n);
	prev[0] = -1;
	next.back() = n;

	rep(i, 1, n) {
		int j = i-1;
		while (j >= 0 && seq[j] <= seq[i]) j = prev[j];
		prev[i] = j;
	}

	for (int i = n-2; i >= 0; i--) {
		int j = i+1;
		while (j < n && seq[j] < seq[i]) j = next[j];
		next[i] = j;
	}

	pointCovers.resize(n+5);
	rep(i, k, sz(pointCovers)) {
		pointCovers[i] = pointCovers[i-1];
		if ((i-k)%(k-1) == 0) {
			pointCovers[i] += i;
		}
	}

	counts.resize(n+5);
	rep(i, k, sz(counts)) {
		counts[i] = counts[i-1];
		if ((i-k)%(k-1) == 0) {
			counts[i] += 1;
		}
	}

	Zp ans = 0;

	rep(i, 0, n) {
		ll elem = seq[i];
		int pos = i-prev[i]-1;
		int len = next[i]-prev[i]-1;
		pos = min(pos, len-pos-1);

		if (len < k) continue;

		int a = pos+1;
		int b = len-pos;
		Zp inters = 0;

		if (a > 0) inters += pointCovers[a];
		if (b > a) inters += (counts[b]-counts[a]) * (pos+1);

		if (b < len) {
			int minX = (b-1) / (k-1);
			int maxX = (len-k) / (k-1);

			if (minX <= maxX) {
				inters += ll(len-k+1) * (maxX-minX+1);

				Zp prog = ll(maxX)*(maxX+1)/2 - ll(minX-1)*(minX)/2;
				inters -= prog*(k-1);
			}
		}

		ans += inters*elem;
	}

	cout << ans.x << endl;
}