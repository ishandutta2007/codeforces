#pragma GCC diagnostic error "-std=c++11"
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
const int P=1e9+7;
inline void inc(int&x,int y){x+=y;x<P?:x-=P;}
inline void inc(int&x,u64 y){x=(x+y)%P;}
inline void dec(int&x,int y){x-=y;x>=0?:x+=P;}
inline void dec(int&x,u64 y){x-=y%P;x>=0?:x+=P;}
template<class T>inline int sgn(T x){return (x>0)-(x<0);}
inline int fpow(int a,int t){return fpow(a,t,P);}
const int N=205,M=5;
int T,n,m;
int f[N][N][M][M];
pii g[N][N][M][M];
void init(){
	int i,j;
	int a,b,c,d;
	vector<pii>win1,win2;
	vector<pii>win3,win4;
	for(i=0;i<=200;i++)for(j=0;j<=200;j++){
		if((abs(i-j)==2&&max(i,j)>=25)||(abs(i-j)>2&&max(i,j)==25)){
			(i>j?win1:win2).emplace_back(i,j);
		}
		if((abs(i-j)==2&&max(i,j)>=15)||(abs(i-j)>2&&max(i,j)==15)){
			(i>j?win3:win4).emplace_back(i,j);
		}
	}
	memset(f,0xaa,sizeof(f));
	f[0][0][0][0]=0;
	for(a=0;a<=200;a++)for(b=0;b<=200;b++)for(c=0;c<=2;c++)for(d=0;d<=2;d++){
		if(f[a][b][c][d]<-200)continue;
		vector<pii> &o1=c+d==4?win3:win1;
		vector<pii> &o2=c+d==4?win4:win2;
		for(auto it:o1){
			if(a+it.fi>200||b+it.se>200)continue;
			if(chkmax(f[a+it.fi][b+it.se][c+1][d],f[a][b][c][d]+it.fi-it.se)){
				g[a+it.fi][b+it.se][c+1][d]=it;
			}
		}
		for(auto it:o2){
			if(a+it.fi>200||b+it.se>200)continue;
			if(chkmax(f[a+it.fi][b+it.se][c][d+1],f[a][b][c][d])){
				g[a+it.fi][b+it.se][c][d+1]=it;
			}
		}
	}
}
void solve(int n,int m,int a,int b){
	printf("%d:%d\n",a,b);
	int u,v;
	bool which_is_last=a>b;
	vector<pii>games;
	while(n>0||m>0){
		tie(u,v)=g[n][m][a][b];
		games.emplace_back(u,v);
		n-=u,m-=v,a-=u>v,b-=u<v;
	}
	reverse(games.begin(),games.end());
	for(auto it:games)printf("%d:%d ",it.fi,it.se);
	puts("");
}
void solve(){
	int i,j;
	scan(n,m);
	for(j=0;j<=2;j++)if(f[n][m][3][j]!=0xaaaaaaaa)return solve(n,m,3,j);
	for(i=2;i>=0;i--)if(f[n][m][i][3]!=0xaaaaaaaa)return solve(n,m,i,3);
	puts("Impossible");
}
int main(){
	init();
	for(scan(T);T;--T)solve();
}