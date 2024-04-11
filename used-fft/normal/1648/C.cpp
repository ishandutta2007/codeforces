#include <bits/stdc++.h>
using namespace std;
#define int int64_t
 
const int Z = 2e5+5, M = 998244353LL;
 
struct fenwick{
	using T = int;
    vector<T> a; int n, p=1<<30; T s;
    fenwick(int N) : a(++(n=N)) {}
    fenwick& operator[](int i){ p = i; return *this; }
    void operator+=(T v){
        for(++p; p<n; p+=p&-p) (a[p] += v) %= M; }
    void operator=(T v){ operator+=(v - (*this)(p, p)); }
    T operator()(int i){
        for(s=0, ++i; i; i^=i&-i) s += a[i];
        return s % M; }
    T operator()(int l, int r){ return (*this)(r) - (*this)(l-1); }
    int lower_bound(T v){
        for(s=0, p=1<<21; p/=2; ) if(s+p<=n && a[s+p]<v) v -= a[s+=p];
        return s;
    }
} f(Z);
 
vector<int> F, invF;
 
 
int mod_pow(int x, int p){
	int r = 1; p += p;
	for(int y=x; p/=2; y=(y*y) % M)
		if(p & 1) r = (r*y) % M;
	return r;
}
int inv(int x) {
	return mod_pow(x, M-2);
}
int ncr(int a, int b){
	if(b < 0 || a < b) return 0;
	return (F[a] * ((invF[b] * invF[a-b]) % M)) % M;
}
 
void init(int MX) {
	F.resize(MX);
	invF.resize(MX);
	F[0] = 1;
	for(int i=1; i<MX; ++i){
		F[i] = (i * F[i-1]) % M;
	}
	invF[MX-1] = mod_pow(F[MX-1], M-2);
	for(int i=MX; --i; ){
		invF[i-1] = (i * invF[i]) % M;
	}
}
 
int cur = 1, ext = 1;
int cnt[Z], res;
 
inline void ml(int &v, const int &x) {
	(v *= x) %= M;
}
 
inline void dv(int &v, const int &x) {
	(v *= inv(x)) %= M;
}
 
void add(const int &v, const int &by) {
	ml(ext, F[cnt[v]]);
	cnt[v] += by;
	dv(ext, F[cnt[v]]);
 
	if(cnt[v]) {
		f[v] = F[cnt[v]] * inv(F[cnt[v] - 1]);
	} else {
		f[v] = 0;
	}
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
 
	int s[n], t[m];
	for(int &i : s) cin >> i;
	for(int &i : t) cin >> i;
 
	init(Z);
 
	for(int i = 1; i < 100; ++i) {
		assert((ncr(500, i) * inv(ncr(500, i))) % M == 1);
	}
 
	for(int &i : s) {
		add(i, 1);
	}
 
 	bool oh = 1;

	for(int i = 0; i < min(n, m); ++i) {
 
		res += ((f(0, t[i] - 1) * ext) % M) * F[n-i-1];
		res %= M;
 
		if(!cnt[t[i]]) {
			oh = 0;
			break;
		}
		add(t[i], -1);
	}
 
 
	// prefix case
	// handle 0
 
	if(n < m && oh) {
		++res;
		res %= M;
	}
 
 
	res %= M;
	res += M;
	res %= M;
	cout << res;
}