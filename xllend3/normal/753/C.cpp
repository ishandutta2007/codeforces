/*
Date: 2016/12/29 17:11:19 Thursday
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x3f3f3f3f;
const int mo=1000000007;
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
template<class T1,class T2>inline void gn(T1&r,T2&s){gn(r),gn(s);}
template<class T1,class T2,class T3>inline void gn(T1&r,T2&s,T3&t){gn(r),gn(s),gn(t);}
template<class T1,class T2,class T3,class T4>inline void gn(T1&r,T2&s,T3&t,T4&u){gn(r),gn(s),gn(t),gn(u);}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mo;for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}
ll powmod(ll a,ll b,ll mo) {ll res=1;a%=mo;for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=111111,M=111111;
int l,m,n,t,C,hid;
vector<int>ans;
int diff(int x){
	int a[11];rep(i,0,9)a[i]=0;
	rep(_,1,4)a[x%10]++,x/=10;
	rep(i,0,9)if(a[i]>1)return 0;
	return 1;
}
pii f(int x,int y){
	int a[11],b[11],A[9],B[9];rep(i,0,9)a[i]=b[i]=0;
	rep(_,1,4)a[A[_]=x%10]++,x/=10;
	rep(_,1,4)b[B[_]=y%10]++,y/=10;
	pii ans=mp(0,0);
	rep(i,1,4)if(A[i]==B[i])++ans.X,--ans.Y;
	rep(i,0,9)if(a[i]&&b[i])++ans.Y;
	return ans;
}
int calc(int x){
	int a[9][9],mx=0;
	rep(i,0,4)rep(j,0,4)a[i][j]=0;
	for(auto i:ans){
		pii p=f(i,x);
		a[p.X][p.Y]++;
	}
	rep(i,0,4)rep(j,0,4)MAX(mx,a[i][j]);
	return mx;
}
int main(){
#ifdef LOCAL
	freopen("B.in","r",stdin);//freopen("B.out","w",stdout);
	srand(unsigned(time(NULL)));
	do{hid=rand()%10000;}while(!diff(hid));
	printf("%d\n",hid);
#endif
	rep(i,0,9999)if(diff(i))ans.pb(i);
	int g;
	while(SZ(ans)>1){
		int mx=inf,ps=0;
		rep(_,0,min(SZ(ans)-1,100)){
			int p=calc(ans[_]);
			if(p<mx)mx=p,ps=_;
			if(mx<p&&mx<p/2)break;
		}
		printf("%04d\n",g=ans[ps]);
		fflush(stdout);
		int p,q;
#ifdef LOCAL
		tie(p,q)=f(hid,g);
		printf("%d %d\n",p,q);
#else
		scanf("%d%d",&p,&q);
#endif
		vector<int>tmp=ans;
		ans.clear();
		for(auto x:tmp)if(f(x,g)==mp(p,q))ans.pb(x);
	}
	if(g!=ans[0])printf("%04d\n",ans[0]);
	fflush(stdout);
	return 0;
}