#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef pair<ll*,ll*> pst;
typedef pair<pst,int> psti;
typedef vector<int> VI;
typedef vector<VI> VII;

namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#ifdef whzzt
		#define gc() getchar()
	#else
		#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	#endif
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c<'a'||c>'z';c=gc());
		for(l=0;c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void ps(const char*s){
		fo(i,0,strlen(s)-1)putc(s[i]);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

const int N = 200005, L = 2000005;

int n, m, sum[L], opt[L], ri[L], l, r;
struct node {
	ll t, x, y;
	node () {t = x = y = 0;}
	void read () {
		ll a, b;
		gi (t); gi (a); gi (b);
		if (((a + b) ^ t) & 1) puts ("NO"), exit (0);
		x = (a + b + t) / 2; y = (a - b + t) / 2;
		if (x < 0 || y < 0) puts ("NO"), exit (0);
	}
	bool operator < (const node &a) const { return t % m < a.t % m; }
} p[N];

void Assert (bool f) { if (!f) puts ("NO"), exit (0); }
void check (ll b1, ll k1, ll b2, ll k2, int &l, int &r) {
	// b1 - i * k1 <= b2 - i * k2
	if (k1 == k2) {
		Assert (b1 <= b2);
		return ;
	}
	ll v;
	if (k1 < k2) {
		// i <= (b2 - b1) / (k2 - k1)
		v = (b2 - b1) / (k2 - k1);
		if (r > v) {
			Assert (l <= v);
			r = v;
		}
	} else {
		// i >= (b1 - b2) / (k1 - k2)
		v = (b1 - b2 + k1 - k2 - 1) / (k1 - k2);
		if (l < v) {
			Assert (r >= v);
			l = v;
		}
	}
}
void check (ll b1, ll k1, ll b2, ll k2, ll s, int &l, int &r) {
	// b1 - i * k1 <= b2 - i * k2
	check (b1, k1, b2, k2, l, r);
	// b1 - i * k1 + s >= b2 - i * k2
	check (b2, k2, b1 + s, k1, l, r);
}

void solve () {
	l = 0; r = m;
	check (p[1].x, p[1].t / m, p[1].t % m, 0, l, r);
	check (0, 0, p[1].x, p[1].t / m, l, r);
	check (p[n].x, p[n].t / m, 0, -1, l, r);
	check (-(m - p[n].t % m), -1, p[n].x, p[n].t / m, l, r);
	fo (i, 1, n - 1) check (p[i].x, p[i].t / m, p[i + 1].x, p[i + 1].t / m, p[i + 1].t % m - p[i].t % m, l, r);
	memset (sum, -1, (m + 1) << 2);
	fo (i, 1, n) sum[p[i].t % m] = p[i].x - p[i].t / m * l;
	sum[m] = ri[m] = l;
	fd (i, m - 1, 1) if (~sum[i]) ri[i] = sum[i]; else ri[i] = ri[i + 1];
	sum[0] = 0;
	fo (i, 1, m) sum[i] = sum[i - 1] + (sum[i - 1] < ri[i]);
	fd (i, m, 1) sum[i] -= sum[i - 1];
}

char str[5][5] = { "LD", "UR" };

int main () {
	gi (n); gi (m);
	fo (i, 1, n) p[i].read();
	sort (p + 1, p + n + 1);
	solve ();
	fo (i, 1, m) opt[i] = sum[i];
	fo (i, 1, n) swap (p[i].x, p[i].y);
	solve ();
	fo (i, 1, m) putc (str[opt[i]][sum[i]]);
	io :: flush();
	return 0;
}