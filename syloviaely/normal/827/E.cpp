#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
const int FFT_MAXN=1048576;
struct cp{
	db a,b;
	cp operator+(const cp&y)const{return (cp){a+y.a,b+y.b};}
	cp operator-(const cp&y)const{return (cp){a-y.a,b-y.b};}
	cp operator*(const cp&y)const{return (cp){a*y.a-b*y.b,a*y.b+b*y.a};}
	cp operator!()const{return (cp){a,-b};};
}nw[FFT_MAXN+1];int bitrev[FFT_MAXN];
void dft(cp*a,int n,int flag=1){
	int d=0;while((1<<d)*n!=FFT_MAXN)d++;
	rep(i,0,n)if(i<(bitrev[i]>>d))swap(a[i],a[bitrev[i]>>d]);
	for (int l=2;l<=n;l<<=1){
		int del=FFT_MAXN/l*flag;
		for (int i=0;i<n;i+=l){
			cp *le=a+i,*ri=a+i+(l>>1),*w=flag==1?nw:nw+FFT_MAXN;
			rep(k,0,l>>1){
				cp ne=*ri**w;
				*ri=*le-ne,*le=*le+ne;
				le++,ri++,w+=del;
			}
		}
	}
	if(flag!=1)rep(i,0,n)a[i].a/=n,a[i].b/=n;
}
void fft_init(){
	int L=0;while((1<<L)!=FFT_MAXN)L++;
	bitrev[0]=0;rep(i,1,FFT_MAXN)bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(L-1));
	/*cp ste=(cp){cosl(2*pi/FFT_MAXN),sinl(2*pi/FFT_MAXN)};
	nw[0]=nw[FFT_MAXN]=(cp){1,0};
	rep(i,1,(FFT_MAXN>>1)+1)nw[i]=nw[i-1]*ste;
	rep(i,(FFT_MAXN>>1)+1,FFT_MAXN)nw[i]=!nw[FFT_MAXN-i];*/	//precision issue
	rep(i,0,FFT_MAXN+1)nw[i]=(cp){(db)cosl(2*pi/FFT_MAXN*i),(db)sinl(2*pi/FFT_MAXN*i)};	
}

void convo(db*a,int n,db*b,int m,db*c){
	if(n<=100 && m<=100 || min(n,m)<=5){
		static db tmp[FFT_MAXN];
		rep(i,0,n+m+1)tmp[i]=0.0;
		rep(i,0,n+1)rep(j,0,m+1)tmp[i+j]+=a[i]*b[j];
		rep(i,0,n+m+1)c[i]=tmp[i];
		return;
	}
	static cp f[FFT_MAXN>>1],g[FFT_MAXN>>1],t[FFT_MAXN>>1];
	int N=2;while(N<=n+m)N<<=1;
	rep(i,0,N)
		if(i&1){
			f[i>>1].b=(i<=n)?a[i]:0.0;
			g[i>>1].b=(i<=m)?b[i]:0.0;
		}else{
			f[i>>1].a=(i<=n)?a[i]:0.0;
			g[i>>1].a=(i<=m)?b[i]:0.0;
		}
	dft(f,N>>1);dft(g,N>>1);
	int del=FFT_MAXN/(N>>1);
	cp *w=nw;
	rep(i,0,N>>1){
		int j=i?(N>>1)-i:0;
		t[i]=((cp){4,0}*!(f[j]*g[j])-(!f[j]-f[i])*(!g[j]-g[i])*((cp){1,0}+*w))*(cp){0,0.25};
		w+=del;
	}
	dft(t,N>>1,-1);
	rep(i,0,n+m+1)c[i]=(i&1)?t[i>>1].a:t[i>>1].b;
}
char ch[510000];
double A[510000],B[510000],an[1010000];
long long x[510000];
int n;
vector<int>ans;
void solve(){
	scanf("%d",&n);
	scanf("%s",ch+1); 
//	n=500000;
//	for (int i=1;i<=n;i++) if (rand()&1) ch[i]='V'; else ch[i]='K'; 
	for (int i=0;i<n;i++) A[i]=B[i]=0;
	for (int i=1;i<=n;i++) if (ch[i]=='V') A[i-1]=1;
	for (int i=1;i<=n;i++) if (ch[i]=='K') B[n-i]=1;
	for (int i=0;i<=n*2;i++) an[i]=0;
	for (int i=0;i<=n;i++) x[i]=0;
//	for (int i=0;i<n;i++) cout<<(int)A[i].x; cout<<endl;
//	for (int i=0;i<n;i++) cout<<(int)B[i].x; cout<<endl;
//cout<<"asd"<<endl;
	convo(A,n-1,B,n-1,an);
//	cout<<"fa"<<endl;
	for (int i=0;i<=n*2;i++){
		long long K=floor(an[i]+0.5);
		if (K==0) continue;
		x[abs(i-n+1)]=1;
	}
	for (int i=n;i;i--)
		for (int j=i;j<=n;j+=i)
			x[i]|=x[j];
	ans.clear();
	for (int i=1;i<=n;i++) if (x[i]==0) ans.push_back(i);
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
}
int main(){
	fft_init();
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}