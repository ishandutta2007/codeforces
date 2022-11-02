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

constexpr int LOG_N = 17;

struct Vert {
	vector<Pii> E;
	array<array<Pii, LOG_N+1>, 3> jump;
	array<Pii, 3> last;
	array<int, 3> len, size = {0, 0, 0};
	array<Zp, 3> f;
};

vector<Vert> G;

int h(int n) {
	if (n<0 || n%2) return 0;
	if (n == 0) return 1;
	return n/2;
}

bool g(int L, int k) {
	return L > k && (L-k)%2;
}

Pii son(int v, int p, int d) {
	for (int i = LOG_N; i >= 0; i--) {
		int j = 1 << i;
		if (j <= d) {
			tie(v, p) = G[v].jump[p][i];
			d -= j;
		}
	}
	return {v, p};
}

int countChildren(int v, int p) {
	return sz(G[v].E) - (p < sz(G[v].E));
}

void getChildren(int v, int p, Pii& x, Pii& y) {
	x = y = {-1, -1};
	rep(i, 0, sz(G[v].E)) if (i != p) {
		(x.x == -1 ? x : y) = G[v].E[i];
	}
}

void compute(int v, int p) {
	if (G[v].size[p] > 0) return;

	auto& jump = G[v].jump[p];
	Pii& u = G[v].last[p] = {v, p};
	int& size = G[v].size[p] = 1;
	int& len = G[v].len[p] = 1;
	Zp& f = G[v].f[p] = 0;

	int nChildren = 0;
	Pii lastChild;

	rep(i, 0, sz(G[v].E)) if (i != p) {
		Pii e = G[v].E[i];
		compute(e.x, e.y);
		size += G[e.x].size[e.y];
		lastChild = e;
		nChildren++;
	}

	if (nChildren == 1) {
		len += G[lastChild.x].len[lastChild.y];
		u = G[lastChild.x].last[lastChild.y];
		jump[0] = lastChild;

		rep(i, 1, LOG_N+1) {
			jump[i] = jump[i-1];
			if (jump[i].x != -1) {
				jump[i] = G[jump[i].x].jump[jump[i].y][i-1];
			}
		}
	} else {
		fill(all(jump), mp(-1, -1));
	}

	if (size % 2) return;

	Pii x, y;
	getChildren(u.x, u.y, x, y);

	if (y.x == -1) {
		f = h(len);
		return;
	}

	int l1 = G[x.x].len[x.y], l2 = G[y.x].len[y.y];
	Pii lx = G[x.x].last[x.y], ly = G[y.x].last[y.y];

	bool chain1 = (countChildren(lx.x, lx.y) == 0);
	bool chain2 = (countChildren(ly.x, ly.y) == 0);

	if (chain1 && chain2) {
		if (l1 > 1 && g(len, l1-1)) f += G[y.x].f[y.y];
		if (l2 > 1 && g(len, l2-1)) f += G[x.x].f[x.y];
		if (g(len-1, l1)) f += G[y.x].f[y.y];
		if (g(len-1, l2)) f += G[x.x].f[x.y];

		if (g(len, 0)) {
			f += h(G[u.x].size[u.y] - 2*min(l1+1, l2));
			f += h(G[u.x].size[u.y] - 2*min(l1, l2+1));
		}
		return;
	}

	if (chain2) {
		swap(x, y);
		swap(l1, l2);
		swap(lx, ly);
		swap(chain1, chain2);
	}

	if (!chain1) {
		if (y.x == ly.x) {
			swap(x, y);
			swap(l1, l2);
			swap(lx, ly);
			swap(chain1, chain2);
		}

		if (x.x != lx.x) return;

		Pii a, b;
		getChildren(x.x, x.y, a, b);

		int l3 = G[a.x].len[a.y], l4 = G[b.x].len[b.y];
		Pii la = G[a.x].last[a.y], lb = G[b.x].last[b.y];

		if (countChildren(la.x, la.y) > 0 || countChildren(lb.x, lb.y)) {
			return;
		}

		if (l4 < l2 && g(len, l3)) {
			Pii an = son(y.x, y.y, l4);
			f += G[an.x].f[an.y];
		}
		if (l3 < l2 && g(len, l4)) {
			Pii an = son(y.x, y.y, l3);
			f += G[an.x].f[an.y];
		}
		return;
	}

	if (l2 > 1) {
		if (l1 > 1 && g(len, l1-1)) f += G[y.x].f[y.y];
		if (g(len-1, l1)) f += G[y.x].f[y.y];

		if (g(len, 0)) {
			if (l1 < l2+1) {
				Pii a = son(y.x, y.y, l1-1);
				f += G[a.x].f[a.y];
			}
			if (l1+1 < l2) {
				Pii a = son(y.x, y.y, l1+1);
				f += G[a.x].f[a.y];
			}
		}
		return;
	}

	Pii z, w;
	getChildren(y.x, y.y, z, w);

	l2 = G[z.x].len[z.y];
	int l3 = G[w.x].len[w.y];
	Pii lz = G[z.x].last[z.y], lw = G[w.x].last[w.y];

	chain1 = (countChildren(lz.x, lz.y) == 0);
	chain2 = (countChildren(lw.x, lw.y) == 0);

	if (chain2) {
		swap(z, w);
		swap(l2, l3);
		swap(lz, lw);
		swap(chain1, chain2);
	}

	if (!chain1) return;

	if (g(len, l1-1)) f += G[y.x].f[y.y];
	if (g(len-1, l1)) f += G[y.x].f[y.y];

	if (chain2) {
		if (g(len, l2)) f += h(G[x.x].size[x.y] + G[w.x].size[w.y] - 2*min(l1, l3));
		if (g(len, l3)) f += h(G[x.x].size[x.y] + G[z.x].size[z.y] - 2*min(l1, l2));
	} else if (l1 < l3 && g(len, l2)) {
		Pii a = son(w.x, w.y, l1);
		f += G[a.x].f[a.y];
	}
}

void printRooted(int v, int p = 2) {
	deb(v+1, p+1, G[v].f[p]);

	rep(i, 0, sz(G[v].E)) if (i != p) {
		Pii e = G[v].E[i];
		printRooted(e.x, e.y);
	}
}

void run() {
	int n; cin >> n;
	G.resize(2*n);

	rep(i, 0, 2*n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		G[a].E.pb({ b, sz(G[b].E) });
		G[b].E.pb({ a, sz(G[a].E)-1 });
	}

	each(v, G) {
		if (sz(v.E) > 3) {
			cout << 0 << endl;
			return;
		}
	}

	Zp ans = 0;

	rep(i, 0, sz(G)) {
		if (sz(G[i].E) <= 2) {
			compute(i, 2);
			ans += G[i].f[2];
		}
		//deb(G[i].f[2]);
	}

	//printRooted(8);

	cout << ans.x << endl;
}