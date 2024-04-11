// Problem: E.  
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
using uint = uint32_t;
const int mod = 998244353;
namespace math {
const int L = 1<<20, A = 1<<20, B = 32, G = 3;

#define INLINE inline __attribute__ (( always_inline ))
struct mint {
	uint32_t v;
	template<class T = int>
	mint(T x = 0) {
		x %= mod;
		if(x < 0) x += mod;
		v = x;
	}
	mint operator-() const {
		return mint(v ? mod-v : 0);
	}
	mint &operator*=(const mint &r) {
		v = v*1ll*r.v%mod;
		return *this;
	}
	mint &operator+=(const mint &r) {
		v = v+r.v>=mod ? (v+r.v-mod) : (v+r.v);
		return *this;
	}
	mint &operator-=(const mint &r) { 
		return *this += -r;
	}
	mint &operator/=(const mint &r) {
		return *this *= r.inv();
	}
	friend mint operator+(mint a, const mint &b) {
		return a += b;
	}
	friend mint operator-(mint a, const mint &b) {
		return a -= b;
	}
	friend mint operator*(mint a, const mint &b) {
		return a *= b;
	}
	friend mint operator/(mint a, const mint &b) {
		return a /= b;
	}
	
	template<class T = int>
	mint pow(T p) const {
		mint res = 1, cur = *this;
		while(p) {
			if(p&1) res = res*cur;
			cur = cur*cur, p>>=1;
		}
		return res;
	}
	mint inv() const {
		return mint(*this).pow(mod-2);
	}
	
	friend bool operator==(const mint &a, const mint &b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mint &a, const mint &b) {
		return !(a == b);
	}
	
	friend istream& operator>>(istream &is, mint &m) {
		ll v;
		is >> v;
		m = mint(v);
		return is;
	}
	friend ostream& operator<<(ostream &os, const mint &m) {
		os << m.v; 
		return os;
	}
};

mint fact[A], inum[A], ifact[A];
void calc_inum() {
	inum[1] = 1;
	for(int i = 2; i < A; i++) inum[i] = -inum[mod%i]*(mod/i);
}
void calc_combi() {
	if(0 == inum[1]) calc_inum();
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < A; i++) fact[i] = fact[i-1]*i;
	for(int i = 1; i < A; i++) ifact[i] = ifact[i-1]*inum[i];
}

mint nck(int n, int k) {
	if(0 == fact[0]) calc_combi();
	if(k > n || k < 0) return 0;
	return fact[n]*ifact[k]*ifact[n-k];
}

uint W[L], WI[L];
INLINE void calc_roots() {
	W[0] = 1;
	int g = mint(G).pow((mod-1)/L).v;
	int i;
	for(i = 1; i < L/2; i++) W[i] = W[i-1]*1ull*g%mod;
	for(int x = 2; x < L; x*=2) {
		for(int y = 0; y < L/2; y+=x)
			W[i++] = W[y];
	}
	for(i = 0; i < L; i++) {
		WI[i] = (uint64_t(W[i])<<B)/mod;
	}
}
INLINE void _ntt(int N, vector<mint> &a) {//normal poly -> bit-rev dft | internally [0; 2*mod)
	int pos = 0;
	for(int l = L/2; l != N/2; l/=2)
		pos += l;
	for(int l = N/2; l; l/=2) {
		for(int x = 0; x < N; x+=2*l) {
			for(int j = pos, i = 0; i < l; i++, j++) {
				uint u = a[x+i].v+a[x+l+i].v;
				if(u >= 2*mod) u -= 2*mod;
				uint v = a[x+i].v-a[x+l+i].v+2*mod;
				uint Q = (v*1ull*WI[j])>>B;
				v = v*W[j] - Q*mod;
				a[x+i].v = u, a[x+l+i].v = v;
			}
		}
		pos += l;
	}
	for(int i = 0; i < N; i++) if(a[i].v >= mod) a[i].v -= mod;
}

INLINE void _ntt_inv(int N, vector<mint> &a) {//bit-rev dft -> normal poly | internally [0; 4*mod)
	int pos = L-2;
	for(int l = 1; l < N; l*=2) {
		for(int x = 0; x < N; x += 2*l) {
			for(int j = pos, i = 0; i < l; i++, j++) {
				uint u = a[x+i].v, v = a[x+l+i].v;
				uint Q = (WI[j]*1ull*v)>>B;
				if(u >= 2*mod) u -= 2*mod;
				v = v*W[j] - Q*mod;
				a[x+i].v = u+v, a[x+l+i].v = u-v+2*mod;
			}
		}
		pos -= 2*l;
	}
	reverse(1 + all(a));
	mint x = mint((mod+1)/2).pow(__lg(N));
	for(auto &i : a) i *= x;//takes care of 2*mod
}
template<bool inv>
INLINE void ntt(int n, vector<mint> &a) {//don't forget about reverse order
	if(W[0] == 0) calc_roots();
	if(!inv) _ntt(n, a);
	else _ntt_inv(n, a);
}


struct poly : vector<mint> {
	template<class... Args>
	explicit poly(Args... args) : vector<mint>(args...) {}
	poly(initializer_list<mint> il) : vector<mint>(il.begin(), il.end()) {}
	poly &trim(int k) {// mod x^k
		if(size() > k) {
			erase(begin()+k, end());
			shrink_to_fit();
		}
		return *this;
	}
	poly &trim() {//remove heading zeroes
		int k = 0;
		while(k < size() && (*this)[size()-k-1] == 0) k++;
		trim(size()-k);
		return *this;
	}
	poly low(int k) const {//get first k coefficients
		k = min(k, (int)size());
		poly res;
		for(int i = 0; i < k; i++) res.push_back((*this)[i]);
		return res;
	}
	friend poly operator*(poly a, const poly &b) {
		poly res = b;
		int n = a.size()+b.size()-1;
		while(n&(n-1)) n += n&-n;
		a.resize(n);
		res.resize(n);
		ntt<0>(n, a);
		ntt<0>(n, res);
		for(int i = 0; i < n; i++) res[i] *= a[i];
		ntt<1>(n, res);
		res.trim();//remove ?
		return res;
	}
	poly &operator*=(const poly &b) {
		return (*this) = (*this)*b;
	}
	
	template<class T>
	poly &operator*=(const T &x) {
		for(auto &i : *this) i *= x;
		return *this;
	}
	poly &operator+=(const poly &x) {
		if(size() < x.size()) resize(x.size());
		for(int i = 0; i < min(size(), x.size()); i++) (*this)[i] += x[i];
		return *this;
	}
	poly &operator-=(const poly &x) {
		if(size() < x.size()) resize(x.size());
		for(int i = 0; i < min(size(), x.size()); i++) (*this)[i] -= x[i];
		return *this;
	}
	
	template<class T> friend poly operator*(poly p, const T &x) { return p *= x; }
	template<class T> friend poly operator*(const T &x, poly p) { return p *= x; }
	friend poly operator+(poly p, const poly &x) { return p += x; }
	friend poly operator-(poly p, const poly &x) { return p -= x; }
	
	poly inv(int N) {//first n coefficients of P^-1
		assert((*this)[0].v);
		poly R {(*this)[0].inv()};
		R.reserve(2*N);
		for(int len = 2; len/2 < N; len*=2) {//R' = R(2 - RT)
			poly T = low(len);
			T.resize(2*len);ntt<0>(2*len, T);
			R.resize(2*len);ntt<0>(2*len, R);
			for(int i = 0; i < 2*len; i++) R[i] = R[i]*(2 - R[i]*T[i]);
			ntt<1>(2*len, R);
			R.trim(len);
		}
		return R.trim(N);
	}
	poly &derive() {
		for(int i = 0; i+1 < size(); i++) {
			(*this)[i] = (*this)[i+1]*(i+1);
		}
		pop_back();
		return *this;
	}
	
	poly derivative() { return poly(*this).derive(); }
	poly &integrate() {
		if(0 == inum[1]) calc_inum();
		push_back(0);
		for(int i = size(); i-- > 1;) {
			(*this)[i] = (*this)[i-1] * inum[i];
		}
		(*this)[0] = 0;
		return *this;
	}
	poly integral() { return poly(*this).integrate(); }
	
	poly ln(int N) {//first n coefficients of ln(P) = P'/P
		return (low(N+1).derivative() * inv(N)).trim(N-1).integrate().trim(N);
	}
	poly exp(int N) {//first n coefficients of exp(P), quite slow
		poly R{1};
		for(int len = 2; len/2 < N; len*=2) {
			R = (R*(poly{1}+low(len)-R.ln(len))).trim(len);
		}
		return R.trim(N);
	}
};
}
using namespace math;
int main() {
	cin.tie(0)->sync_with_stdio(0);
#define int ll
	multitest([&](){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n), G(n);
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		for(int f,t,i = 0; i < m; i++) {
			cin >> f >> t;
			f--,t--;
			g[t].push_back(f);
			G[f].push_back(t);
		}
		vector<array<mint, 2>> dp(n);
		vector<int> vis(n);
		auto dfs = [&](auto self, int v) -> array<mint, 2> {//{cnt, sum}
			if(vis[v]) return dp[v];
			vis[v] = 1;
			dp[v] = {a[v], 0};
			for(auto i : g[v]) {
				
				auto t = self(self, i);
				dp[v][0] += t[0];
				dp[v][1] += t[1];
			}
			return dp[v];
		};
		int r = 0;
		while(G[r].size()) r++;
		mint ans = dfs(dfs, r)[0];
		for(int sim = 0; sim <= n; sim++) {
			ll sm = 0;
			for(auto i : a) sm |= i;
			if(!sm) break;
			ans += a[r] == 0;
			vector<int> na = a;
			for(int i = 0; i < n; i++) {
				if(a[i]) {
					for(auto x : G[i])
						na[x] = min(na[x], 3*n)+1;
					na[i]--;
				}
			}
			a = na;
			// for(auto i : a) cout << i << " "; cout << endl;
		}
		cout << ans << '\n';
	});
	
}