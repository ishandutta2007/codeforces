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

const int N = 100005, S = 300, T = N / S + 5;

int n, m, s, w, c, pos, bl[N], lp[N], rp[N], num;
pi p[N];
ll ret, sum;

int bcnt[T], back[N], peo[N], qu[T][S + 5], ql[T], cur[T];

bool better (int i, int j, int k) {
	// i < j < k
	ll k1 = i, b1 = (ll)i * back[i];
	ll k2 = j, b2 = (ll)j * back[j];
	ll k3 = k, b3 = (ll)k * back[k];
	return (b1 - b2) * (k3 - k2) >= (b2 - b3) * (k2 - k1);
}
void rebuild (int id) {
	int *q = qu[id], &l = ql[id];
	while (l) q[l --] = 0;
	fo (i, lp[id], rp[id]) {
		while (l > 1 && better (q[l - 1], q[l], i)) q[l --] = 0;
		q[++ l] = i;
	}
	cur[id] = 1;
}
ll Get (int i, int x) { return (ll)i * (back[i] + x); }
void maintain (int id) {
	int *q = qu[id], &l = ql[id], &p = cur[id], x = bcnt[id];
	while (p < l && Get (q[p], x) < Get (q[p + 1], x)) p ++;
}

void ext (int u) {
	peo[u] ++;
	fd (i, bl[u] - 1, 0) bcnt[i] ++;
	fd (i, u, lp[bl[u]]) back[i] ++;
	rebuild (bl[u]);
	fd (i, bl[u], 0) maintain (i);
}

int main () {
	gi (n), gi (w);
	fo (i, 1, n) gi (p[i].se), gi (p[i].fi), m = max (m, p[i].fi + 1), s = max (s, p[i].se);
	sort (p + 1, p + n + 1);
	fo (i, 0, s) bl[i] = i / S;
	fo (i, 0, s) rp[bl[i]] = i; fd (i, s, 0) lp[bl[i]] = i;
	fo (i, 0, bl[s]) rebuild (i), maintain (i);
	for (c = 0, pos = 1; c <= m; c ++) {
		while (pos <= n && c > p[pos].fi) ext (p[pos ++].se);
		ret = -1;
		fo (i, 0, bl[s]) {
			auto now = Get (qu[i][cur[i]], bcnt[i]);
			if (now > ret) ret = now, num = qu[i][cur[i]];
		}
		ret += (ll)(n - pos + 1) * c * w;
		print (ret); putc (' '); print (num); putc ('\n');
	}
	io :: flush();
	return 0;
}