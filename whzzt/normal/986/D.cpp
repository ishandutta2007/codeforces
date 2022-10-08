#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector <int> VI;

namespace io {
	const int L = (1 << 21) + 1;
	char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, qu[55]; int f, qr;
#ifdef whzzt
	#define gc() getchar()
#else
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, L, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
#endif
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
	inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	template <class I>
	inline void gi (I & x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0', x /= 10;
		while (qr) putc (qu[qr --]);
	}
	struct IOC { ~ IOC () { flush (); } } _ioc_;
};
using io :: gi;
using io :: putc;
using io :: print;

const int N = 1050005, M = 4200005, L = 1500005, D = 10000;
const int pw10[] = {1, 10, 100, 1000, 10000};
static long double g = log(10) / log(3), PI = acos(-1);

namespace FFT{
	struct num{
		double r,i;
		num(){}
		num(double _r,double _i){r=_r,i=_i;}
		inline friend num operator+(num a,num b){return num(a.r+b.r,a.i+b.i);}
		inline friend num operator-(num a,num b){return num(a.r-b.r,a.i-b.i);}
		inline friend num operator*(num a,num b){return num(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
		inline friend num operator*(num a,double b){return num(a.r*b,a.i*b);}
		inline friend num operator/(num a,double b){return num(a.r/b,a.i/b);}
		inline num conj(){return num(r,-i);}
		inline num mult(){return num(-i,r);}
	};
	num pol[M],*ed=pol,*ww[23],*iww[23],*_w;
	num *nint(int len){num*r=ed;ed+=len;return r;}
	inline int fxt(int n){int l=1;while(l<=n)l<<=1;return l;}
	void init(int n){
		int i,j,k;
		for(i=j=1;j<=n;i++,j<<=1){
			ww[i]=nint(j),iww[i]=nint(j);
			for(k=0;k<j;k++){
				ww[i][k]=num(cos(PI/j*k),sin(PI/j*k));
				iww[i][k]=ww[i][k].conj();
			}
		}
	}
	void fft(num a[],int n,int dft){
		int i,j,k,l,c=0;num u,v;
		for(i=1,j=n>>1;i<n-1;i++){
			if(i<j)swap(a[i],a[j]);
			for(k=n>>1;(j^=k)<k;k>>=1);
		}
		for(l=2,c=1;l<=n;l<<=1,c++){
			if(dft==-1)_w=iww[c];else _w=ww[c];
			for(i=l>>1,j=0;j<n;j+=l)for(k=0;k<i;k++){
				u=a[j+k],v=a[j+k+i]*_w[k];
				a[j+k]=u+v,a[j+k+i]=u-v;
			}
		}
		if(dft==-1)for(int i=0;i<n;i++)a[i]=a[i]/n;
	}
}

struct hugeint{
	vector <ll> a;
	hugeint (int s = 0) { a.push_back (s), mt (); }
	ll & operator [] (int i) { return a[i]; }
	int read () {
		static char str[L];
		scanf ("%s", str);
		int n = strlen (str), i;
		a.resize ((n + 3) >> 2);
		long double cur = 0, e = 1;
		for (i = 0; i < n; i ++) {
			a[(n - i - 1) >> 2] += pw10[(n - i - 1) & 3] * (str[i] - '0');
			cur += (str[i] - '0') * e, e *= 0.1;
		}
		if (n == 1 && cur == 1) puts ("1"), exit(0);
		cur = log(cur) / log(3) + g * (n - 1);
		mt ();
		return cur - 2;
	}
	void mt () {
		int i;
		for (i = 0; i < a.size(); i ++) if (a[i] >= D) {
			if (i + 1 >= a.size()) a.pb (a[i] / D);
			else a[i + 1] += a[i] / D;
			a[i] %= D;
		}
		while (a.size() > 1 && *a.rbegin() == 0) a.pop_back ();
	}
	hugeint square () {
		using FFT :: num; using FFT :: fft; using FFT :: fxt;
		static num x[N];
		int i, m = fxt (a.size() << 1);
		memset (x, 0, m * sizeof(num));
		for (i = 0; i < a.size(); i ++) x[i] = num (a[i], 0);
		fft (x, m, 1); for (i = 0; i < m; i ++) x[i] = x[i] * x[i]; fft (x, m, -1);
		hugeint b; b.a.resize(m);
		for (i = 0; i < m; i ++) b[i] = x[i].r + 0.5;
		b.mt ();
		return b;
	}
	friend hugeint operator * (hugeint a, int b) {
		hugeint ret = a;
		for (ll &v : ret.a) v *= b;
		ret.mt ();
		return ret;
	}
	friend bool operator < (hugeint a, hugeint b) {
		if (a.a.size() != b.a.size()) return a.a.size() < b.a.size();
		int l = a.a.size() - 1;
		for (; l >= 0; l --) if (a[l] != b[l]) return a[l] < b[l];
		return false;
	}
	void print () {
		int l = a.size() - 1;
		printf ("%lld", a[l]);
		for (l --; l >= 0; l --) printf ("%4.4lld", a[l]);
		puts ("");
	}
} n, m;
int ret, k, dp[2333];

hugeint hugepow (int n) {
	if (n == 0) return hugeint(1);
	hugeint ret = hugepow(n >> 1).square();
	if (n & 1) ret = ret * 3;
	return ret;
}

int main () {
	FFT :: init (1 << 20);
	m = hugepow (ret = max (n.read(), 0)), ret *= 3;
//	n.print(); m.print();
	for (k = 1; m * k < n; k ++);
	int i;
	for (i = 2; i <= k; i ++) dp[i] = min (dp[(i + 1) / 2] + 2, dp[(i + 2) / 3] + 3);
	printf ("%d\n", dp[k] + ret);
	return 0;
}