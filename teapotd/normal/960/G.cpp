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
constexpr ll ROOT = 646; // order = 1<<20

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

	// Use modInv below for composite modulus
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

using Vfft = vector<Zp>;
Vfft bases;

void initFFT(int n) { // n must be power of 2
	bases.resize(n+1, 1);
	auto b = Zp(ROOT).pow((1<<20) / n);
	rep(i, 1, n+1) bases[i] = b * bases[i-1];
}

template<int dir> // 1 for DFT, -1 for inverse
void fft(Vfft& buf) {
	int n = sz(buf), bits = 31-__builtin_clz(n);
	int i = (dir > 0 ? 0 : bits-1);

	for (; i >= 0 && i < bits; i += dir) {
		int shift = 1 << (bits-i-1);

		rep(j, 0, 1 << i) rep(k, 0, shift) {
			int a = (j << (bits-i)) | k;
			int b = a | shift;
			auto v1 = buf[a], v2 = buf[b];
			auto base = bases[(dir*(k<<i)) & (n-1)];

			if (dir > 0) {
				buf[b] = (v1 - v2) * base;
			} else {
				v2 = v2*base;
				buf[b] = v1 - v2;
			}
			buf[a] = v1 + v2;
		}
	}

	if (dir < 0) {
		Zp y = Zp(1) / n; // Or change to complex
		each(x, buf) x = x*y;
	}
}

// ---

using Poly = Vfft;

void multiply(Poly& dst, Poly& src) {
	int n = 1 << (uplg(sz(dst) + sz(src)));
	initFFT(n);
	dst.resize(n);
	src.resize(n);
	fft<1>(dst);
	fft<1>(src);
	rep(i, 0, n) dst[i] *= src[i];
	fft<-1>(dst);

	while (!dst.empty() && dst.back().x == 0) dst.pop_back();
}

Poly compute(int begin, int end, int n) {
	if (begin >= end) return {1};
	if (begin+1 == end) return {begin-n+1, 1};

	int mid = (begin+end) / 2;
	Poly a = compute(begin, mid, n);
	Poly b = compute(mid, end, n);
	multiply(a, b);
	return a;
}

Poly getStirling(int n) {
	Poly poly = compute(0, n, n);
	for (int i = (n+1)%2; i < sz(poly); i += 2) {
		poly[i] *= -1;
	}
	return poly;
}

void run() {
	int n, a, b;
	cin >> n >> a >> b;

	if (a <= 0 || b <= 0 || a+b-2 > n-1 || a+b-2 < 0) {
		cout << 0 << endl;
		return;
	}

	Zp ans = getStirling(n-1)[a+b-2];
	Zp div = 1;

	rep(i, 1, a+b-1) ans *= i;
	rep(i, 1, a) div *= i;
	rep(i, 1, b) div *= i;

	cout << (ans/div).x << endl;
	return;
}