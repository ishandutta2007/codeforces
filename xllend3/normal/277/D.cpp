/*
Date: 2014/10/22 08:23:06 Wednesday
Author: xllend3
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
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
using namespace std;
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

const int N=111111,M=111111,P=1000000;
int l,m,n,t,C;
//x->y:(1-f[x])*f[y]*t[x]+(1-f[y])*(t[x]+t[y])
//y->x:(1-f[y])*f[x]*t[y]+(1-f[x])*(t[x]+t[y])
struct zcc{ll sc1,sc2,ti1,ti2,f;lf tmp;
void read(){scanf("%lld%lld%lld%lld%lf",&sc1,&sc2,&ti1,&ti2,&tmp);f=ll(tmp*P+0.5);}
}a[N];
inline bool cmp(const zcc &a,const zcc &b){return ll(P-a.f)*b.f*a.ti2+ll(P-b.f)*(a.ti2+b.ti2)*P
	<ll(P-b.f)*a.f*b.ti2+ll(P-a.f)*(a.ti2+b.ti2)*P;}
pair<ll,lf> f[N];
int main()
{
	scanf("%d%d",&n,&m);rep(i,1,n)a[i].read();sort(a+1,a+1+n,cmp);
	rep(i,1,n){
		dep(j,m,0){
			if(j+a[i].ti1<=m)
				MAX(f[j+a[i].ti1],mp(f[j].X+a[i].sc1*P,f[j].Y-a[i].ti1));
			if(j+a[i].ti1+a[i].ti2<=m)
				MAX(f[j+a[i].ti1+a[i].ti2],mp(f[j].X+a[i].sc1*P+a[i].sc2*(P-a[i].f)
					,f[j].Y*(a[i].tmp)-(j+a[i].ti2)*(1-a[i].tmp)-a[i].ti1));
		}
		//rep(i,0,m)printf("%d %.10lf %.10lf\n",i,1.0*f[i].X/P,-f[i].Y);
	}
	lf ans=-f[m].Y;rep(i,0,m)if(f[i].X==f[m].X)MIN(ans,-f[i].Y);
	printf("%.10lf %.10lf\n",1.0*f[m].X/P,ans);
	return 0;
}