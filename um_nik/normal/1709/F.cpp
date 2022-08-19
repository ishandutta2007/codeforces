#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const uint MOD = 998244353;
template<uint mod = MOD> struct mint { // 1000000007  1000000009
	uint x;

	mint() : x(0) {}
	mint(ll _x) {
		_x %= mod;
		if (_x < 0) _x += mod;
		x = _x;
	}

	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = (ull)x * a.x % mod;
		return *this;
	}
	mint pow(ll pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		uint t = x;
		uint res = 1;
		while(t != 1) {
			uint z = mod / t;
			res = (ull)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}

	bool sqrt(mint &res) const {
		if (mod == 2 || x == 0) {
			res = *this;
			return true;
		}
		if (pow((mod - 1) / 2) != 1) return false;
		if (mod % 4 == 3) {
			res = pow((mod + 1) / 4);
			return true;
		}
		int pw = (mod - 1) / 2;
		int K = 30;
		while((1 << K) > pw) K--;
		while(true) {
			mint t = myRand(mod);
			mint a = 0, b = 0, c = 1;
			for (int k = K; k >= 0; k--) {
				a = b * b;
				b = b * c * 2;
				c = c * c + a * *this;
				if (((pw >> k) & 1) == 0) continue;
				a = b;
				b = b * t + c;
				c = c * t + a * *this;
			}
			if (b == 0) continue;
			c -= 1;
			c *= mint() - b.inv();
			if (c * c == *this) {
				res = c;
				return true;
			}
		}
		assert(false);
	}

	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
};
template<uint mod = MOD> struct Factorials {
	using Mint = mint<mod>;
	vector<Mint> f, fi;

	Factorials() : f(), fi() {}
	Factorials(int n) {
		n += 10;
		f = vector<Mint>(n);
		fi = vector<Mint>(n);
		f[0] = 1;
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] * i;
		fi[n - 1] = f[n - 1].inv();
		for (int i = n - 1; i > 0; i--)
			fi[i - 1] = fi[i] * i;
	}

	Mint C(int n, int k) {
		if (k < 0 || k > n) return 0;
		return f[n] * fi[k] * fi[n - k];
	}
};
template<uint mod = MOD> struct Powers {
	using Mint = mint<mod>;
	vector<Mint> p, pi;

	Powers() : p(), pi() {}
	Powers(int n, Mint x) {
		n += 10;
		if (x == 0) {
			p = vector<Mint>(n);
			p[0] = 1;
		} else {
			p = vector<Mint>(n);
			pi = vector<Mint>(n);
			p[0] = pi[0] = 1;
			Mint xi = x.inv();
			for (int i = 1; i < n; i++) {
				p[i] = p[i - 1] * x;
				pi[i] = pi[i - 1] * xi;
			}
		}
	}

	Mint pow(int n) {
		if (n >= 0)
			return p[n];
		else
			return pi[-n];
	}
};
template<uint mod = MOD> struct Inverses {
	using Mint = mint<mod>;
	vector<Mint> ii;

	Inverses() : ii() {}
	Inverses(int n) {
		n += 10;
		ii = vector<Mint>(n);
		ii[1] = 1;
		for (int x = 2; x < n; x++)
			ii[x] = Mint() - ii[mod % x] * (mod / x);
	}

	Mint inv(Mint x) {
		assert(x != 0);
		uint t = x.x;
		uint res = 1;
		while(t >= (int)ii.size()) {
			uint z = mod / t;
			res = (ull)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return ii[t] * res;
	}
};
using Mint = mint<>;

const int LOG = 20; // CHECK!!!!
Powers W;
vector<int> binRev;
void initFFT() {
	binRev = vector<int>((1 << LOG) + 3, 0);
	Mint w = 2;
	while(true) {
		Mint x = w;
		for (int i = 1; i < LOG; i++)
			x *= x;
		if (x == -1) break;
		w += 1;
	}
	W = Powers(1 << LOG, w);
	for (int mask = 1; mask < (1 << LOG); mask++) {
		binRev[mask] = (binRev[mask >> 1] >> 1) ^ ((mask & 1) << (LOG - 1));
	}
}

template<unsigned mod = MOD> struct Poly {
	using Mint = mint<mod>;
	vector<Mint> a;

	Poly() : a() {}
	Poly(vector<Mint> _a) {
		a = _a;
		while(!a.empty() && a.back() == 0) a.pop_back();
	}

	void print(int n = -1) {
		if (n == -1) n = (int)a.size();
		for (int i = 0; i < n; i++)
			printf("%u ", at(i).x);
		printf("\n");
	}
	void eprint() {
		eprintf("[");
		for (int i = 0; i < (int)a.size(); i++)
			eprintf("%u ", a[i].x);
		eprintf("]\n");
	}

	static void fft(vector<Mint> &A) {
		int L = (int)A.size();
		assert((L & (L - 1)) == 0);
		int k = 0;
		while((1 << k) < L) k++;
		for (int i = 0; i < L; i++) {
			int x = binRev[i] >> (LOG - k);
			if (i < x) swap(A[i], A[x]);
		}
		for (int lvl = 0; lvl < k; lvl++) {
			int len = 1 << lvl;
			for (int st = 0; st < L; st += (len << 1))
				for (int i = 0; i < len; i++) {
					Mint x = A[st + i], y = A[st + len + i] * W.pow(i << (LOG - 1 - lvl));
					A[st + i] = x + y;
					A[st + len + i] = x - y;
				}
		}
	}

	Mint& operator [] (const int i) {
		assert(0 <= i && i <= deg()); 
		return a[i];
	}
	Mint at(const int i) const {
		if (i < 0 || i > deg()) return 0;
		return a[i];
	}
	int deg() const { // deg of polynomial 0 is -1
		return (int)a.size() - 1;
	}
	Mint eval(const Mint &x) const {
		Mint res = 0;
		for (int i = deg(); i >= 0; i--)
			res = res * x + a[i];
		return res;
	}
	Poly substr(const int &l, const int &r) const {
		vector<Mint> f(r - l);
		for (int i = l; i < r; i++)
			f[i - l] = at(i);
		return f;
	}

	Poly& operator += (const Poly &A) {
		if (deg() < A.deg()) a.resize(A.a.size());
		for (int i = 0; i <= A.deg(); i++)
			a[i] += A.a[i];
		while(!a.empty() && a.back() == 0) a.pop_back();
		return *this;
	}
	Poly& operator -= (const Poly &A) {
		if (deg() < A.deg()) a.resize(A.a.size());
		for (int i = 0; i <= A.deg(); i++)
			a[i] -= A.a[i];
		while(!a.empty() && a.back() == 0) a.pop_back();
		return *this;
	}
	Poly& operator *= (const Mint &k) {
		if (k == 0) a.clear();
		for (Mint &x : a) x *= k;
		return *this;
	}
	Poly& operator /= (const Mint &k) {
		Mint ki = k.inv();
		for (Mint &x : a) x *= ki;
		return *this;
	}
	Poly operator + (const Poly &A) const {
		return Poly(*this) += A;
	}
	Poly operator - (const Poly &A) const {
		return Poly(*this) -= A;
	}
	Poly operator * (const Mint &k) const {
		return Poly(*this) *= k;
	}
	Poly operator / (const Mint &k) const {
		return Poly(*this) /= k;
	}
	
	Poly& operator *= (const Poly &A) {
		if (a.empty() || A.a.empty()) {
			a.clear();
			return *this;
		}
		int nd = deg() + A.deg();
		
		if (deg() < LOG || A.deg() < LOG) {
			vector<Mint> res(nd + 1, 0);
			for (int i = 0; i <= deg(); i++)
				for (int j = 0; j <= A.deg(); j++)
					res[i + j] += a[i] * A.a[j];
			return *this = Poly(res);
		}
		
		int k = 0;
		while((1 << k) <= nd) k++;
		int L = 1 << k;
		vector<Mint> f = a, g = A.a;
		f.resize(L, 0);
		g.resize(L, 0);
		fft(f);
		fft(g);
		for (int i = 0; i < L; i++)
			f[i] *= g[i];
		fft(f);
		reverse(f.begin() + 1, f.end());
		return *this = (Poly(f) / L);
	}
	Poly operator * (const Poly &A) const {
		return Poly(*this) *= A;
	}

	Poly inv(int n) const {
		assert(deg() >= 0 && at(0) != 0);
		if (n <= 0) return Poly();
		vector<Mint> res(n);
		res[0] = a[0].inv();
		vector<Mint> f, g;
		for (int L = 1; L < n; L <<= 1) {
			f = vector<Mint>(2 * L);
			g = vector<Mint>(2 * L);
			for (int i = 0; i < 2 * L && i <= deg(); i++)
				f[i] = a[i];
			for (int i = 0; i < L; i++)
				g[i] = res[i];
			fft(f);
			fft(g);
			for (int i = 0; i < 2 * L; i++)
				f[i] *= g[i];
			fft(f);
			reverse(f.begin() + 1, f.end());
			for (int i = 0; i < L; i++)
				f[i] = 0;
			for (int i = L; i < 2 * L; i++)
				f[i] = Mint() - f[i];
			fft(f);
			for (int i = 0; i < 2 * L; i++)
				f[i] *= g[i];
			fft(f);
			reverse(f.begin() + 1, f.end());
			Mint Li = Mint(2 * L).inv();
			Li *= Li;
			for (int i = L; i < 2 * L && i < n; i++)
				res[i] = f[i] * Li;
		}
		return res;
	}

	static vector<Mint> div_stupid(vector<Mint> A, vector<Mint> B) {
		int n = (int)A.size(), m = (int)B.size();
		Mint Bi = B.back().inv();
		for (auto &x : B) x *= Bi;
		vector<Mint> C(n - m + 1);
		for (int i = n; i >= m; i--) {
			C[i - m] = A[i - 1] * Bi;
			for (int j = 0; j < m; j++)
				A[i - m + j] -= B[j] * A[i - 1];
		}
		return C;
	}
	Poly& operator /= (const Poly &A) {
		int d1 = deg(), d2 = A.deg();
		assert(d2 >= 0);
		if (d1 < d2) return *this = Poly();
		if (d2 < 4 * LOG || d1 - d2 < 4 * LOG)
			return *this = div_stupid(a, A.a);
		vector<Mint> f = a, g = A.a;
		reverse(all(f));
		reverse(all(g));
		Poly H = Poly(vector<Mint>(f.begin(), f.begin() + d1 - d2 + 1)) * Poly(g).inv(d1 - d2 + 1);
		vector<Mint> t = vector<Mint>(H.a.begin(), H.a.begin() + d1 - d2 + 1);
		reverse(all(t));
		return *this = t;
	}
	Poly operator / (const Poly &A) const {
		return Poly(*this) /= A;
	}
	Poly& operator %= (const Poly &A) {
		assert(A.deg() >= 0);
		if (deg() < A.deg()) return *this;
		return *this -= A * (*this / A);
	}
	Poly operator % (const Poly &A) const {
		return Poly(*this) %= A;
	}

	Poly derivate() const {
		int n = deg();
		if (n <= 0) return Poly();
		vector<Mint> f(n);
		for (int i = 0; i < n; i++)
			f[i] = a[i + 1] * (i + 1);
		return f;
	}
	Poly integrate() const {
		int n = deg();
		if (n < 0) return Poly();
		n += 2;
		vector<Mint> f(n);
		Inverses I = Inverses(n);
		for (int i = 1; i < n; i++)
			f[i] = a[i - 1] * I.inv(i);
		return f;
	}
	Poly log(int n) const {
		if (n <= 1) return Poly();
		assert(deg() >= 0 && at(0) == 1);
		return (derivate() * inv(n)).substr(0, n - 1).integrate();
	}
	Poly exp(int n) const {
		if (n <= 0) return Poly();
		if (deg() < 0) return Poly({1});
		assert(at(0) == 0);
		vector<Mint> res(n);
		res[0] = 1;
		vector<Mint> f, g;
		for (int L = 1; L < n; L <<= 1) {
			f = vector<Mint>(2 * L);
			g = vector<Mint>(2 * L);
			Poly LG = Poly(vector<Mint>(res.begin(), res.begin() + L)).log(2 * L);
			for (int i = 0; i < L; i++)
				assert(at(i) == LG.at(i));
			for (int i = 0; i < L; i++) {
				f[i] = res[i];
				g[i] = at(L + i) - LG.at(L + i);
			}
			fft(f);
			fft(g);
			for (int i = 0; i < 2 * L; i++)
				f[i] *= g[i];
			fft(f);
			reverse(f.begin() + 1, f.end());
			Mint Li = Mint(2 * L).inv();
			for (int i = L; i < 2 * L && i < n; i++)
				res[i] = f[i - L] * Li;
		}
		return res;
	}
	Poly sqr(int n) const {
		return (*this * *this).substr(0, n);
	}
	Poly pow_(Mint k, int n) const { // k can be non-negative rational (k = 1/2 is sqrt), but assert(a[0] == 1);
		if (deg() < 0 || n <= 0) return Poly();
		return (log(n) * k).exp(n);
	}
	Poly pow(ll k, int n) const { // k is non-negative integer
		if (n <= 0) return Poly();
		if (k == 0) return Poly({1});
		if (k == 1) return substr(0, n);
		if (k == 2) return sqr(n);
		if (k < LOG) {
			Poly cur = substr(0, n);
			Poly res = Poly({1});
			while(k) {
				if (k & 1) res = (res * cur).substr(0, n);
				cur = cur.sqr(n);
				k >>= 1;
			}
			return res;
		}
		int z = 0;
		while(z * k < n && at(z) == 0) z++;
		if (z * k >= n) return Poly();
		Poly A = substr(z, z + n - z * k);
		Mint cf = A[0].pow(k);
		A /= A[0];
		A = A.pow_(k, n - z * k) * cf;
		return A.substr(-z * k, n - z * k);
	}
	Poly sqrt_(int n) const {
		if (deg() < 0 || n <= 0) return Poly();
		assert(at(0) == 1);
//		return pow_(Mint(2).inv(), n);
		vector<Mint> res(n);
		res[0] = 1;
		vector<Mint> f, g;
		for (int L = 1; L < n; L <<= 1) {
			f = vector<Mint>(2 * L);
			g = vector<Mint>(2 * L);
			for (int i = 0; i < L; i++)
				f[i] = res[i];
			fft(f);
			for (int i = 0; i < 2 * L; i++)
				f[i] *= f[i];
			fft(f);
			reverse(f.begin() + 1, f.end());
			Mint Li = Mint(2 * L).inv();
			for (int i = 0; i < 2 * L; i++)
				f[i] *= Li;
			for (int i = 0; i < 2 * L; i++)
				f[i] = at(i) - f[i];
			for (int i = 0; i < L; i++)
				assert(f[i] == 0);
			for (int i = 0; i < L; i++) {
				f[i] = f[i + L];
				f[i + L] = 0;
			}
			Poly Q = Poly(vector<Mint>(res.begin(), res.begin() + L)).inv(L);
			for (int i = 0; i < L; i++)
				g[i] = Q.at(i);
			fft(f);
			fft(g);
			for (int i = 0; i < 2 * L; i++)
				f[i] *= g[i];
			fft(f);
			reverse(f.begin() + 1, f.end());
			Li /= 2;
			for (int i = L; i < 2 * L && i < n; i++)
				res[i] = f[i - L] * Li;
		}
		return res;
	}
	bool sqrt(int n, Poly &R) const {
		if (deg() < 0) {
			R = Poly();
			return true;
		}
		if (at(0) == 1) {
			R = sqrt_(n);
			return true;
		}
		int z = 0;
		while(at(z) == 0) z++;
		if (z & 1) return false;
		Poly A = substr(z, n + z / 2);
		Mint cf;
		if (!A[0].sqrt(cf)) return false;
		A /= A[0];
		A = A.sqrt_(n - z / 2) * cf;
		R = A.substr(-z / 2, n - z / 2);
		return true;
	}

	static Poly multiply_all(vector<Poly> polys) {
		if (polys.empty()) return Poly({1});
		set<pii> setik;
		for (int i = 0; i < (int)polys.size(); i++)
			setik.insert(mp(polys[i].deg(), i));
		while((int)setik.size() > 1) {
			int p = setik.begin()->second;
			setik.erase(setik.begin());
			int q = setik.begin()->second;
			setik.erase(setik.begin());
			polys[p] *= polys[q];
			setik.insert(mp(polys[p].deg(), p));
		}
		return polys[setik.begin()->second];
	}
	static Poly given_roots(const vector<Mint> &xs) {
		int n = (int)xs.size();
		vector<Poly> polys(n);
		for (int i = 0; i < n; i++)
			polys[i] = Poly({Mint() - xs[i], 1});
		return multiply_all(polys);
	}

	vector<Mint> multipoint(const vector<Mint> &xs) const {
		int n = (int)xs.size();
		if (n == 0) return {};
		if (n == 1) return {eval(xs[0])};
		int L = n;
		while(L & (L - 1)) L++;
		vector<Poly> tree(2 * L);
		for (int i = 0; i < n; i++)
			tree[L + i] = Poly({Mint() - xs[i], 1});
		for (int i = n; i < L; i++)
			tree[L + i] = Poly({1});
		for (int i = L - 1; i > 0; i--)
			tree[i] = tree[2 * i] * tree[2 * i + 1];
		tree[1] = *this % tree[1];
		for (int i = 2; i < L + n; i++)
			tree[i] = tree[i / 2] % tree[i];
		vector<Mint> res(n);
		for (int i = 0; i < n; i++)
			res[i] = tree[L + i].at(0);
		return res;
	}
	static pair<Poly, Poly> interpolate_(const vector<pair<Mint, Mint>> &vals, int l, int r) {
		if (r - l == 1) return mp(Poly({vals[l].second}), Poly({Mint() - vals[l].first, 1}));
		int m = (l + r) / 2;
		auto L = interpolate_(vals, l, m), R = interpolate_(vals, m, r);
		return mp(L.first * R.second + R.first * L.second, L.second * R.second);

	}
	static Poly interpolate(vector<pair<Mint, Mint>> vals) {
		if (vals.empty()) return Poly();
		int n = (int)vals.size();
		vector<Mint> xs(n);
		for (int i = 0; i < n; i++)
			xs[i] = vals[i].first;
		Poly P = given_roots(xs);
		P = P.derivate();
		vector<Mint> cf = P.multipoint(xs);
		for (int i = 0; i < n; i++)
			vals[i].second /= cf[i];
		return interpolate_(vals, 0, (int)vals.size()).first;
	}
	Poly x_k_mod_this(ll k) const { // x^k % P
		Poly res = Poly({1});
		int t = 0;
		while((1LL << t) <= k) t++;
		for (int i = t - 1; i >= 0; i--) {
			res *= res;
			if ((k >> i) & 1) res = res.substr(-1, res.deg() + 1);
			res %= *this;
		}
		return res;
	}

	vector<Mint> chirp_z(Mint z, int n) const { // eval at [z^0, z^1, ..., z^(n-1)]
		int m = deg();
		if (m < 0 || n == 0) return vector<Mint>(n);
		if (z == 0) {
			vector<Mint> res(n, at(0));
			res[0] = eval(1);
			return res;
		}
		Mint zi = z.inv();
		vector<Mint> Z(n + m, 1), Zi(max(m + 1, n), 1);
		Mint w = 1, wi = 1;
		for (int i = 1; i < (int)Z.size(); i++) {
			Z[i] = Z[i - 1] * w;
			w *= z;
		}
		for (int i = 1; i < (int)Zi.size(); i++) {
			Zi[i] = Zi[i - 1] * wi;
			wi *= zi;
		}
		vector<Mint> f(m + 1);
		for (int i = 0; i <= m; i++)
			f[i] = at(i) * Zi[i];
		reverse(all(Z));
		Poly C = Poly(f) * Z;
		vector<Mint> res(n);
		for (int k = 0; k < n; k++)
			res[k] = C.at(n + m - 1 - k) * Zi[k];
		return res;
	}

	Poly shift_c(Mint c) const { // P(x + c)
		int n = deg();
		if (n < 0) return Poly();
		Factorials F(n);
		Powers P(n, c);
		vector<Mint> f(n + 1), g(n + 1);
		for (int i = 0; i <= n; i++) {
			f[i] = at(i) * F.f[i];
			g[i] = P.pow(i) * F.fi[i];
		}
		reverse(all(g));
		Poly C = Poly(f) * g;
		for (int i = 0; i <= n; i++)
			f[i] = C.at(n + i) * F.fi[i];
		return f;
	}
};

template<uint mod = MOD>
vector<mint<mod>> BerlekampMassey(vector<mint<mod>> x) {
    using Mint = mint<mod>;
    vector<Mint> ls, cur;
    int lf;
    Mint ld;
    for (int i = 0; i < (int)x.size(); i++) {
        Mint t = 0;
        for (int j = 0; j < (int)cur.size(); j++)
            t += cur[j] * x[i - j - 1];
        if (t == x[i]) continue;
        if (cur.empty()) {
            cur.resize(i + 1);
            lf = i;
            ld = t - x[i];
            continue;
        }
        Mint k = (t - x[i]) / ld;
        vector<Mint> c(i - lf - 1);
        c.push_back(k);
        for (auto t : ls) {
            c.push_back(Mint() - t * k);
        }
        if (c.size() < cur.size()) c.resize(cur.size());
        for (int j = 0; j < (int)cur.size(); j++)
            c[j] += cur[j];
        if (i - lf + (int)ls.size() >= (int)cur.size()) {
            ls = cur;
            lf = i;
            ld = t - x[i];
        }
        cur = c;
    }
    return cur;
}

// CALL initFFT() and CHECK LOG

const int N = 200200;
int n, k, f;
Mint a[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	initFFT();

	scanf("%d%d%d", &n, &k, &f);
	for (int i = 0; i <= k; i++)
		a[i] = 1;
	n--;
	while(n--) {
		vector<Mint> b(k + 1, 0);
		for (int i = 0; i <= k; i++)
			b[i] = a[i];
		Poly<> C = Poly<>(b) * Poly<>(b);
		Mint sum = 0;
		for (int i = C.deg(); i >= 0; i--) {
			sum += C.at(i);
			if (i <= k) {
				a[i] = sum;
				a[i] += C.at(i) * (k - i);
			}
		}
	}
	vector<Mint> b(k + 1, 0);
	for (int i = 0; i <= k; i++)
		b[i] = a[i];
	Poly<> C = Poly<>(b) * Poly<>(b);
	printf("%u\n", C.at(f).x);
	return 0;
}