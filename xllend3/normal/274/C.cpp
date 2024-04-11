/*
Date: 2014/12/30 07:37:24 Tuesday
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

const int N=111111,M=111111;
int l,m,n,t,C;
pff a[N];
pff calc(pff p0,pff p1,pff p2){
	lf a1=p1.X-p0.X,b1=p1.Y-p0.Y,c1=(sqr(a1)+sqr(b1))/2;
	lf a2=p2.X-p0.X,b2=p2.Y-p0.Y,c2=(sqr(a2)+sqr(b2))/2;
	lf d=a1*b2-a2*b1;
	return mp(p0.X+(c1*b2-c2*b1)/d,p0.Y+(a1*c2-a2*c1)/d);
}
lf dis(pff a,pff b){return sqrt(sqr(a.X-b.X)+sqr(a.Y-b.Y));}
lf dis2(int x,int y){return sqr(a[x].X-a[y].X)+sqr(a[x].Y-a[y].Y);}
set<pff>S;
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("CF274C.in","r",stdin);//freopen("CF274C.out","w",stdout);
#endif
	scanf("%d",&n);rep(i,1,n)scanf("%lf%lf",&a[i].X,&a[i].Y),S.insert(a[i]);
	lf ans=0;
	rep(i,1,n)rep(j,i+1,n)rep(k,j+1,n)
		if(dis2(i,j)+dis2(j,k)>dis2(i,k)+eps&&dis2(i,j)+dis2(i,k)>dis2(j,k)+eps&&dis2(i,k)+dis2(j,k)>dis2(i,j)+eps){
			pff cen=calc(a[i],a[j],a[k]);lf t=1e30;
			rep(_,1,n)MIN(t,dis(cen,a[_]));if(t+eps>dis(cen,a[i]))MAX(ans,t);
	}
	rep(i,1,n)rep(j,1,n)if(i!=j)rep(k,1,n)if(i!=k
	&&j!=k){
		if(abs(dis2(i,k)+dis2(j,k)-dis2(i,j))>eps)continue;
		pff al=mp(a[i].X+a[j].X-a[k].X,a[i].Y+a[j].Y-a[k].Y);
		if(S.find(al)==S.end())continue;
		pff cen=mp((a[i].X+a[j].X)/2,(a[i].Y+a[j].Y)/2);lf t=1e30;
		rep(_,1,n)MIN(t,dis(cen,a[_]));if(t+eps>dis(cen,a[i]))MAX(ans,t);
	}if(ans==0){puts("-1");return 0;}
	printf("%.9lf\n",ans);
	return 0;
}