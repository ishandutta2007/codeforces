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


constexpr int MOD = 998244353; 

struct Zp {
	int x;

	Zp(ll a = 0) {
		x = int(a % MOD);
		if (x < 0) x += MOD;
	}

	Zp operator+(Zp r) const {
		Zp y; y.x = x+r.x;
		if (y.x >= MOD) y.x -= MOD;
		return y;
	}

	Zp operator-(Zp r) const {
		Zp y; y.x = x-r.x;
		if (y.x < 0) y.x += MOD;
		return y;
	}

	Zp operator*(Zp r) const {
		Zp y; y.x = int(ll(x)*r.x % MOD);
		return y;
	}

	Zp operator/(Zp r) const {
		Zp y; y.x = int(ll(x)*r.inv().x % MOD);
		return y;
	}

	Zp operator-() const {
		Zp y; y.x = MOD-x; return y;
	}

	Zp inv() const { return pow(MOD-2); }

	Zp pow(int e) const {
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

constexpr int ROOT = 646; // order = 1<<20

using Vfft = vector<Zp>;
Vfft bases;

void initFFT(int n) { // n must be power of 2
	if (sz(bases) != n+1) bases.resize(n+1, 1);
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
		Zp mult = Zp(1)/n;
		each(x, buf) x *= mult;
	}
}

// ---

using Poly = Vfft;

Poly tmp;

struct PolyPair {
	Poly W, Q;

	void merge(PolyPair& r) {
		int s = sz(Q)+sz(r.Q);
		s = max(s, sz(Q)+sz(r.W));
		s = max(s, sz(W));

		int n = 1;
		while (n < s) n *= 2;

		if (ll(sz(Q)+sz(r.W))*sz(Q) < 5000) {
			tmp.assign(n, 0);
			rep(i, 0, sz(r.W)) rep(j, 0, sz(Q)) tmp[i+j] += r.W[i]*Q[j];
			r.W.swap(tmp);

			tmp.assign(n, 0);
			rep(i, 0, sz(Q)) rep(j, 0, sz(r.Q)) tmp[i+j] += Q[i]*r.Q[j];
			Q.swap(tmp);
		} else {
			Q.resize(n);
			W.resize(n);
			r.Q.resize(n);
			r.W.resize(n);

			initFFT(n);
			fft<1>(Q);
			fft<1>(r.Q);
			fft<1>(r.W);

			rep(i, 0, n) r.W[i] *= Q[i];
			rep(i, 0, n) Q[i] *= r.Q[i];

			fft<-1>(Q);
			fft<-1>(r.W);
		}

		if (sz(W) < sz(r.W)) W.swap(r.W);
		rep(i, 0, sz(r.W)) W[i] += r.W[i];

		Poly().swap(r.W);
		Poly().swap(r.Q);

		while (!W.empty() && W.back().x == 0) W.pop_back();
		while (!Q.empty() && Q.back().x == 0) Q.pop_back();
	}
};

struct Vert {
	Vi E;
	int parent, size, depth, chain, chainPos;
};

struct Chain {
	Vi verts;
};

vector<Vert> G;
vector<Chain> chains;

void hld(int i, int parent = -1, int d = 0) {
	int h = -1;
	G[i].parent = parent;
	G[i].depth = d;
	G[i].size = 1;

	each(e, G[i].E) if (e != parent) {
		hld(e, i, d+1);
		G[i].size += G[e].size;
		if (h < 0 || G[h].size < G[e].size) h = e;
	}

	if (h < 0) {
		h = sz(chains);
		chains.emplace_back();
	} else {
		h = G[h].chain;
	}
	chains[h].verts.pb(i);
	G[i].chain = h;

	if (parent < 0) {
		each(p, chains) {
			reverse(all(p.verts));
			rep(j, 0, sz(p.verts))
				G[p.verts[j]].chainPos = j;
		}
	}
}

void mergePairs(vector<PolyPair>& polys, int begin, int end) {
	if (begin+1 >= end) return;

	int mid = (begin+end) / 2;
	mergePairs(polys, begin, mid);
	mergePairs(polys, mid, end);
	polys[begin].merge(polys[mid]);
}

void compute(Poly& out, int root) {
	auto& chain = chains[G[root].chain];

	vector<PolyPair> polys(sz(chain.verts));

	rep(i, 0, sz(chain.verts)) {
		int v = chain.verts[i];
		int next = (i+1 < sz(chain.verts) ? chain.verts[i+1] : -1);
		bool ok = false;

		each(e, G[v].E) if (e != G[v].parent && e != next) {
			polys[i].W.pb(1);
			compute(polys[i].Q, e);
			polys[i].Q.insert(polys[i].Q.begin(), 0);
			ok = true;
			break;
		}

		if (ok) continue;

		if (next == -1) {
			polys[i].W.pb(1);
			polys[i].W.pb(1);
		} else {
			polys[i].W.pb(1);
			polys[i].Q.pb(0);
			polys[i].Q.pb(1);
		}
	}

	mergePairs(polys, 0, sz(polys));
	out.swap(polys[0].W);
}

void run() {
	int n;
	ll x;
	cin >> n >> x;
	G.resize(n);

	rep(i, 1, n) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].E.pb(b);
		G[b].E.pb(a);
	}

	hld(0);
	Poly poly;
	compute(poly, 0);

	Zp ans = 0, mult = 1, up = x;

	rep(i, 1, sz(poly)) {
		ans += mult*poly[i];
		up += 1;
		mult = mult * up / i;
	}

	cout << ans.x << endl;
}