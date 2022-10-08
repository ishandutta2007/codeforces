#pragma optimize("unroll-loops,no-stack-protector")
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define ALL(a) a.begin(),a.end()
#define lowbit(x) ((x)&-(x))
#define dec minus_down
using namespace std;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int>pii;
typedef vector<int>VI;
typedef long long i64;
typedef long long ll;
typedef double ld;
namespace io{
	struct eof{eof(){}};
	const int L=(1<<21)|5;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,qu[55];int f,qr;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>inline void gi(I&x){
		for(f=1,c=gc();(c<'0'||c>'9')&&(c!=EOF);c=gc())if(c=='-')f=-1;
 		if(c==EOF)throw eof();
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)qu[++qr]=x%10+'0',x/=10;while(qr)putc(qu[qr--]);
	}
#if __cplusplus < 201103L
	// do nothing
#else
	struct StringReader{
		function<bool(char)>chk;
		StringReader(){chk=[&](char c){return c<='z'&&c>='a';};}
		StringReader(function<bool(char)>func){chk=func;}
		inline char read(){for(c=gc();!chk(c);c=gc());return c;}
		inline void gs(char*s){for(c=gc();!chk(c);c=gc());for(;chk(c);c=gc())*s++=c;*s=0;}
		string readString(){string s;for(c=gc();!chk(c);c=gc());for(;chk(c);c=gc())s+=c;return s;}
	};
#endif
	inline void ps(const char*s){int l=strlen(s),x;for(x=0;x<l;x++)putc(s[x]);}
	struct IOC{~IOC(){flush();}}ioc;
	inline double readld(){
		double x=0,y=1;
		for(c=gc();c<'0'||c>'9';c=gc())if(c=='-')y=-1;assert(c!='.');
		for(;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=y;assert(c!='e');
		if(c=='.')for(c=gc();c<='9'&&c>='0';c=gc())y*=0.1,x+=y*(c&15);
		return x;
	}
	inline void printld(double x,int y){
		if(x<0)putc('-'),x=-x;x+=.5*pow(.1,y);print((u64)x),putc('.');
		for(x-=(u64)x;y;--y)x*=10,putc((int)x+'0'),x-=(int)x;
	}
}using io::gi;using io::print;using io::putc;
template<class T>int ctz(T a){return sizeof(T)>2?__builtin_ctzll(a):__builtin_ctz(a);}
template<class T>inline T gcd(T a,T b){
	int shift=ctz(a|b);
	for(b>>=ctz(b),a>>=ctz(a);a;a-=b,a>>=ctz(a))if(a<b)swap(a,b);
	return b<<shift;
}
template<class T>void exgcd(T a,T b,T&x,T&y){
	if(!b)return (void)(x=1,y=0);
	exgcd(b,a%b,y,x),y-=a/b*x;
}
template<class T>T Inv(T a,T p){T x,y;exgcd(a,p,x,y);return (x%p+p)%p;}
inline int fpow(int a,int t,int p){static int r;for(r=1;t;a=(ll)a*a%p,t>>=1)if(t&1)r=(ll)r*a%p;return r;}
string to_string(string s){return '"'+s+'"';};
string to_string(const char*s){return to_string(string(s));}
string to_string(bool f){return f?"true":"false";}
template<class A,class B>string to_string(pair<A,B>p){return "("+to_string(p.fi)+", "+to_string(p.se)+")";}
template<class T>string to_string(T v){string s="{",e="";for(auto&x:v)s+=e+to_string(x),e=", ";s+="}";return s;}
void debug_out(){cerr<<endl;}template<class A,class...B>void debug_out(A x,B...y){cerr<<" "<<to_string(x),debug_out(y...);}
void scan(){}template<class A,class...B>void scan(A&a,B&...b){gi(a),scan(b...);}
template<class T>void read(T first,T last){for(;first!=last;++first)gi(*first);}
template<class T>void write(T first,T last){for(;first!=last;putc(++first==last?'\n':' '))print(*first);}
template<class T>void show(T x){print(x),putc('\n');}
template<class A,class...B>void show(A a,B...b){print(a),putc(' '),show(b...);}
template<class T>inline bool chkmin(T&a,T b){return b<a?a=b,true:false;}
template<class T>inline bool chkmax(T&a,T b){return a<b?a=b,true:false;}
template<class T>inline T abs(T x){return x<0?-x:x;}
const int P=998244353,mod=P;
inline void inc(int&x,int y){x+=y;x<P?:x-=P;}
inline void inc(int&x,u64 y){x=(x+y)%P;}
inline void dec(int&x,int y){x-=y;x>=0?:x+=P;}
inline void dec(int&x,u64 y){x-=y%P;x>=0?:x+=P;}
inline int add(int x,int y){return (x+=y)<mod?x:x-mod;}
inline int sub(int x,int y){return (x-=y)<0?x+mod:x;}
inline int mul(int x,int y){return i64(x)*y%mod;}
inline void addx(int&x,int y){(x+=y)<mod?:x-=mod;}
inline void subx(int&x,int y){(x-=y)>=0?:x+=mod;}
template<class T>inline int sgn(T x){return (x>0)-(x<0);}
inline int fpow(int a,i64 t){
	static const int fmod=mod-1;
	t%=fmod;if(t<0)t+=fmod;int r;
	for(r=1;t;t>>=1,a=mul(a,a))if(t&1)r=mul(r,a);
	return r;
}
const int N=2e5+5;
namespace fft {
	#define mms(a, n) memset(a, 0, sizeof(*a) * (n))
	#define mmp(a, b, n) memcpy(a, b, sizeof(*b) * (n))
	const int N = 533333, M = 1066666, P = ::P, g = 3, G = 30;
	inline int fxt(int x){ int l; for (l = 1; l <= x; l <<= 1); return l; }
	int pol[M << 1], *ed = pol, inv[N], fac[N], ifac[N], *ww[G], *iww[G], *_w;
	int *nint(int len){ ed += len; return ed - len; }
	void init(int n){
		int i, j, k, w, iw;
		for (i = j = 1; j <= n; ++i, j <<= 1) {
			ww[i] = nint(j), iww[i] = nint(j), ww[i][0] = iww[i][0] = 1;
			w = fpow(g, (P - 1) >> i), iw = fpow(w, P - 2);
			for (k = 1; k < j; k ++) ww[i][k] = (ll)ww[i][k - 1] * w % P, iww[i][k] = (ll)iww[i][k - 1] * iw % P;
		}
		inv[1] = 1;
		for (i = 2; i <= n; ++i) inv[i] = P - (ll)inv[P % i] * (P / i) % P;
		fac[0] = ifac[0] = 1;
		for (i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % P, ifac[i] = (ll)ifac[i - 1] * inv[i] % P;
	}
	void fft(int a[], int n, int dft){
		int i, j, k, l, c = 0, u, v;
		for (i = 1, j = n >> 1; i < n - 1; ++i) {
			if (i < j) swap (a[i], a[j]);
			for (k = n >> 1; (j ^= k) < k; k >>= 1);
		}
		for (l = 2, c = 1; l <= n; l <<= 1, c ++) {
			_w = dft == -1 ? iww[c] : ww[c];
			for (i = l >> 1, j = 0; j < n; j += l) for (k = 0; k < i; k ++) {
				u = a[j + k], v = (ll)a[j + k + i] * _w[k] % P;
				a[j + k] = (u + v) % P, a[j + k + i] = (u - v + P) % P;
			}
		}
		if (dft == -1) for (i = 0; i < n; ++i) a[i] = (ll)a[i] * inv[n] % P;
	}
	
	struct poly {
		vector<int> a;
		poly(){
			a.resize(1);
		}
		poly(int n, ...){
			va_list scan;
			va_start(scan, n);
			resize(n);
			for (int i = n; i >= 0; i --) a[i] = va_arg(scan, int);
			va_end(scan);
			maintain();
		}
		poly(vector<int> s){
			a = s;
			maintain();
		}
		inline int size(){
			return (int)a.size() - 1;
		}
		inline void resize(int n){
			a.resize(n + 1);
		}
		inline int & operator [] (int i) {
			return a[i];
		}
		inline void maintain(){
			int p;
			for (p = size(); p > 0 && !a[p]; --p);
			resize(p);
		}
		inline void in(int *b, int n){
			resize(n);
			for (int i = 0; i <= n; ++i) a[i] = b[i];
			maintain();
		}
		inline void op(int *b, int n){
			for (int i = 0; i <= n; ++i) b[i] = a[i];
		}
		inline poly ig(){
			poly r = *this;
			r.resize(r.size() + 1);
			for (int i = r.size(); i >= 1; i --) r[i] = (ll)r[i - 1] * fft::inv[i] % P;
			r[0] = 0;
			return r;
		}
		inline poly dg(){
			poly r = *this;
			for (int i = 1; i <= size(); ++i) r[i - 1] = (ll)r[i] * i % P;
			r[size()] = 0;
			r.maintain();
			return r;
		}
		inline poly rev(){
			poly b;
			b.resize(size());
			for (int i = 0; i <= size(); ++i) b[i] = a[size() - i];
			b.maintain();
			return b;
		}
		inline friend poly operator * (poly a, int b) {
			for (int i = 0; i <= a.size(); ++i) a[i] = (ll)a[i] * b % P;
			a.maintain();
			return a;
		}
		inline friend poly operator * (poly a, poly b) {
			poly c;
			c.resize(a.size() + b.size());
			if (min(a.size(), b.size()) < 31) {
				int i, j;
				for (i = 0; i <= a.size(); ++i) if (a[i]) for (j = 0; j <= b.size(); ++j) if (b[j])
					c[i + j] = (c[i + j] + (ll)a[i] * b[j]) % P;
				c.maintain();
				return c;
			}
			static int x[N], y[N], z[N];
			int n = fxt(a.size() + b.size()), i;
			mms(x, n), mms(y, n), a.op(x, a.size()), b.op(y, b.size());
			fft(x, n, 1), fft(y, n, 1);
			for (i = 0; i < n; ++i) z[i] = (ll)x[i] * y[i] % P;
			fft(z, n, -1);
			c.in(z, n - 1);
			return c;
		}
		inline friend poly operator + (poly a, poly b) {
			if (a.size() < b.size()) a.a.swap(b.a);
			for (int i = 0; i <= b.size(); ++i) a[i] = (a[i] + b[i]) % P;
			a.maintain();
			return a;
		}
		inline friend poly operator - (poly a, poly b) {
			if (a.size() < b.size()) a.resize(b.size());
			for (int i = 0; i <= b.size(); ++i) a[i] = (a[i] - b[i] + P) % P;
			a.maintain();
			return a;
		}
		inline friend poly operator / (poly a, poly b) {
			int n = a.size(), m = b.size();
			if (n < m) return poly(0, 0);
			poly c = a.rev() * b.rev().inv(n - m);
			c.resize(n - m);
			return c.rev();
		}
		inline friend poly operator % (poly a, poly b) { return a - a / b * b; }
		inline void gdb(){
			for (int i = size(); i >= 0; i --) {
				debug ("%d ", a[i]);
				if (i) debug ("x");
				if (i > 1) debug ("^%d", i);
				if (i) debug (" + ");
			}
			debug ("\n");
		}
		inline poly inv(int n);
		inline poly ln(int n);
		inline poly exp(int n);
	} ;
	void Inv(int a[], int r[], int n){
		if (n == 1) {
			*r = fpow(*a, P - 2);
			return ;
		}
		static int w1[N], w2[N], w3[N], w4[N];
		int d = (n + 1) >> 1, m = fxt(d * 2 + n - 3), i;
		Inv(a, w1, (n + 1) >> 1);
		mms(w2, m), mms(w3, m), mmp(w2, w1, d), mmp(w3, a, n);
		fft(w2, m, 1), fft(w3, m, 1);
		for (i = 0; i < m; ++i) w4[i] = ((2 * w2[i] - (ll)w2[i] * w2[i] % P * w3[i]) % P + P) % P;
		fft(w4, m, -1);
		mmp(r, w4, n);
	}
	inline poly poly :: inv(int n) {
		static int a[N], r[N]; poly c;
		mms(a, n + 1), op(a, size());
		Inv(a, r, n + 1), c.in(r, n);
		return c;
	}
	inline poly poly :: ln(int n) {
		poly a = this -> dg();
		poly b = this -> inv(n);
		poly c = (a * b).ig();
		c.resize(n), c.maintain();
		return c;
	}
	inline poly poly :: exp(int n) {
		if (n == 0) return poly (0, 1);
		poly u0 = this -> exp(n >> 1);
		// u = u0 - f(u0) / f'(u0) = u0 (1 - ln(u) + *this)
		poly u1 = poly(0, 1) - u0.ln(n);
		u1.resize(n);
		for (int i = 0; i <= min(n, size()); ++i) u1[i] = (u1[i] + this -> a[i]) % P;
		poly u = u0 * u1;
		u.resize(n), u.maintain();
		return u;
	}
	
	poly multiply(vector<int> x){
		int n = x.size(), i;
		vector<poly> T(n << 1);
		for (i = 0; i < n; ++i) T[n + i] = poly(1, 1, P - x[i]);
		for (--i; i; --i) T[i] = T[i << 1] * T[i << 1 | 1];
		return T[1];
	}
	vector<int> evaluate(poly f, vector<int> x){
		int n = x.size(), i;
		vector<poly> T(n << 1), D(n << 1);
		for (i = 0; i < n; ++i) T[n + i] = poly(1, 1, P - x[i]);
		for (--i; i; --i) T[i] = T[i << 1] * T[i << 1 | 1];
		D[1] = f % T[1];
		for (i = 2; i < n << 1; ++i) D[i] = D[i >> 1] % T[i];
		vector<int> res;
		for (i = 0; i < n; ++i) res.pb(D[i + n][0]);
		return res;
	}
	vector<int> cloudtour(vector<int> x, vector<int> c){
		int n = x.size(), m, i, j;
		vector<poly> T(n << 1), F(n << 1);
		for (i = 0; i < n; ++i) T[n + i] = poly(1, 1, P - x[i]);
		for (--i; i; --i) T[i] = T[i << 1] * T[i << 1 | 1];
		F[1] = c;
		for (i = 2; i < n << 1; ++i) {
			m = T[i ^ 1].size();
			F[i] = T[i ^ 1].rev() * F[i >> 1];
			for (j = 0; j + m <= F[i].size(); ++j) F[i][j] = F[i][j + m];
			if (F[i].size() > T[i].size()) F[i].resize(T[i].size());
			F[i].maintain();
		}
		vector<int> res;
		for (i = 0; i < n; ++i) res.pb(F[i + n][0]);
		return res;
	}
}
using fft::poly;
int n,h[N],k,m,ret;
poly f,g;
poly power(poly a,int t){
	if(t==0) return poly(0,1);
	poly h=power(a,t>>1);
	h=h*h;
	if(t&1) h=h*a;
	return h;
}
int main(){
	fft::init(1 << 19);
	scan(n,k);
	read(h+1,h+n+1);
	for(int i=1;i<=n;++i) if(h[i]!=h[i%n+1]) m++;
	f=poly(2,1,k-2,1);
	g=power(f,m);
	for(int i=m+1;i<=g.size();++i) ret=add(ret,g[i]);
	ret=mul(ret,fpow(k,n-m));
	print(ret),putc('\n');
}