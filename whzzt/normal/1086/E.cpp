//#pragma GCC diagnostic error "-std=c++11"
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
template<class T>int ctz(T a){return sizeof(T)>4?__builtin_ctzll(a):__builtin_ctz(a);}
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
inline void inc(int&x,i64 y){x=(x+y)%P;}
inline void dec(int&x,int y){x-=y;x>=0?:x+=P;}
inline void dec(int&x,i64 y){x-=y%P;x>=0?:x+=P;}
template<class T>inline int sgn(T x){return (x>0)-(x<0);}
inline int fpow(int a,int t){return fpow(a,t,P);}
const int N=2005;
int n,a[N][N],T[N][N],res,fac[N],us[N],ds[N];
struct bit{
	int sum[N];
	void add(int x,int v){while(x<=n)sum[x]+=v,x+=lowbit(x);}
	int get(int x){int r=0;while(x)r+=sum[x],x-=lowbit(x);return r;}
	int get(int l,int r){return get(r)-get(l-1);}
	void to_zero(int x){
		int v=get(x,x);
		if(!v) return;
		add(x,-v);
	}
	void clear(){memset(sum,0,sizeof(sum));}
}f1,f2;
int main(){
	int i,j;
	scan(n);
	for(i=1;i<=n;i++)read(a[i]+1,a[i]+n+1);
	for(i=fac[0]=1;i<=n;i++)fac[i]=(i64)fac[i-1]*i%mod;
	for(i=0;i<=n;i++){
		T[i][0]=fac[i];
		for(j=1;j<=i;j++)T[i][j]=(T[i][j-1]-T[i-1][j-1]+mod)%mod;
	}
	f1.clear();
	for(j=1;j<=n;j++)f1.add(j,1);
	for(j=1;j<=n;j++)f1.add(a[1][j],-1),inc(res,(i64)f1.get(a[1][j])*fac[n-j]);
	for(i=2;i<=n;i++){
		res=(i64)res*T[n][n]%mod;
		for(j=1;j<=n;j++)us[a[i-1][j]]=j,ds[a[i][j]]=j;
		f1.clear(),f2.clear();
		for(j=1;j<=n;j++)f1.add(j,1),f2.add(j,1);
		for(j=1;j<=n;j++){
			f2.to_zero(a[i-1][j]);
			int sm=f1.get(a[i][j]-1);
			int tm=f2.get(a[i][j]-1);
			int am=f2.get(n);
			if(a[i][j]>a[i-1][j]&&f1.get(a[i-1][j],a[i-1][j]))--sm;
			inc(res,(i64)(sm-tm)*T[n-j][am]);
			if(am>0)inc(res,(i64)tm*T[n-j][am-1]);
			f1.add(a[i][j],-1),f2.to_zero(a[i][j]);
		}
	}
	printf("%d\n",res);
}