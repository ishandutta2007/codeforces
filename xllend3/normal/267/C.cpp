/*
Date: 2015/01/06 10:55:18 Tuesday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
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
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=111,M=111111;
int l,m,n,t,C,x,y,z;
lf v[N][N];
struct zcc{int x,y,z;}a[M];
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("CF267C.in","r",stdin);//freopen("CF267C.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);rep(i,1,m){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		v[a[i].x][a[i].x]--;v[a[i].x][a[i].y]++;
		v[a[i].y][a[i].y]--;v[a[i].y][a[i].x]++;
	}rep(i,1,n)v[1][i]=v[n][i]=0;v[1][n+1]=1;v[1][1]=v[n][n]=1;
	rep(i,1,n){
		//rep(i,1,n){rep(j,1,n+1)printf("%.2lf ",v[i][j]);puts("");}puts("");
		rep(j,i+1,n)if(abs(v[j][i])>abs(v[i][i])){rep(k,i,n+1)swap(v[i][k],v[j][k]);}
		if(v[i][i]==0)continue;
		rep(j,i+1,n){
			rep(k,i+1,n+1)v[j][k]-=v[j][i]/v[i][i]*v[i][k];v[j][i]=0;
		}
	}
	dep(i,n,1){
		rep(j,i+1,n)v[i][n+1]-=v[i][j]*v[j][n+1],v[i][j]=0;
		if(v[i][i]==0)v[i][n+1]=0;else v[i][n+1]/=v[i][i];
	}
	//rep(i,1,n)printf("%d %.9lf\n",i,v[i][n+1]);
	lf ans=1e30;rep(i,1,m)MIN(ans,abs(1.0*a[i].z/(v[a[i].x][n+1]-v[a[i].y][n+1])));
	lf res=0;rep(i,1,m)if(a[i].x==1)res+=ans*(v[a[i].x][n+1]-v[a[i].y][n+1]);
		else if(a[i].y==1)res+=ans*(v[a[i].y][n+1]-v[a[i].x][n+1]);
	printf("%.9lf\n",res);
	rep(i,1,m)printf("%.9lf\n",ans*(v[a[i].x][n+1]-v[a[i].y][n+1]));
	return 0;
}