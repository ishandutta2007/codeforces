#pragma optimize("unroll-loops,no-stack-protector")
#include<bits/stdc++.h>
#define pb emplace_back
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
const int N=5e5+5;
int n,up[N],dn[N],tmax[2][N],tz[N];
vector<int> adj[N],kk[N];
void push(){ for(int o:{0,1}) for(int v=n,i=o;v>=1;--v) while(i<=tmax[o][v]) tz[i]=v,i+=2; }
void update(int o,int r,int v){ chkmax(tmax[o][v],r); }
void dfs1(int u,int fa){ for(int v:adj[u]) if(v!=fa) dfs1(v,u),chkmax(dn[u],dn[v]+1); }
void dfs2(int u,int fa){
	if(fa) kk[u].pb(up[u]);
	for(int v:adj[u]) if(v!=fa) kk[u].pb(dn[v]+1);
	sort(kk[u].begin(),kk[u].end());
	reverse(kk[u].begin(),kk[u].end());
	int len=max(up[u],dn[u]),mx=0,sl=0;
	for(int v:adj[u]) if(v!=fa&&dn[v]+1==len) mx=v;
	if(mx) sl=up[u];
	for(int v:adj[u]) if(v!=fa&&v!=mx) chkmax(sl,dn[v]+1);
	for(int v:adj[u]) if(v!=fa) up[v]=(v==mx?sl:len)+1,dfs2(v,u);
}
void update(vector<int> r){
	if(r.size()==1) return;
	update(0,r[0]+r[1],2),update(1,r[0]+r[1],2);
	for(int i=0;i<r.size();++i) update(0,2*r[i],i+1),update(1,2*r[i]-1,i+1);
	r.pb(0);
	for(int i=1;i<r.size();++i) if(r[i-1]>r[i]) update(1,2*r[i]+1,i+1);
}
vector<int> st[N];
void update(int u,int v){
	auto &fu=kk[u],&fv=kk[v];
	if(fu.size()==1||fv.size()==1) return;
	int n=fu.size(),m=fv.size();
	if(n<m){
		while(st[v].size()<n) st[v].pb(0);
		for(int i=0;i<n;++i) chkmax(st[v][i],fu[i]);
	}else{
		while(st[u].size()<m) st[u].pb(0);
		for(int i=0;i<m;++i) chkmax(st[u][i],fv[i]);
	}
}
int main(){
	scan(n);
	for(int i=1;i<n;++i){
		int u,v;
		scan(u,v);
		adj[u].pb(v),adj[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	update(0,n,1),update(1,n,1);
	if(n>=2) update(1,1,2);
	for(int i=1;i<=n;++i) update(kk[i]);
	vector<int> Q(n);
	for(int i=0;i<n;++i) Q[i]=i+1;
	sort(Q.begin(),Q.end(),[&](int x,int y){ return adj[x].size()>adj[y].size(); });
	for(int u:Q) for(int v:adj[u]) update(u,v);
	for(int u=1;u<=n;++u){
		int S=(int)st[u].size()+(int)kk[u].size()-2;
		vector<int> a=st[u];
		for(int v:kk[u]) a.pb(v);
		sort(a.begin(),a.end());
		for(int i=0,j=0;i<S;++i) if(j<a[i]) update(0,2*a[i],S-i),j=a[i];
	}
	push();
	for(int k=1;k<=n;++k) print(tz[k]),putc(" \n"[k==n]);
}