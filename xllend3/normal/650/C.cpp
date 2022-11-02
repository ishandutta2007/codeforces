/*
Date: 2016/03/07 16:49:14 Monday
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
#define pt(i,j) ((i-1)*n+j)
const int N=1111111,M=111111;
int l,m,n,t,C,tot;
int a[N],f[N],rd[N],ans[N];
pii tmp[N];
vector<int>E[N];
int getf(int x){if(x==f[x])return x;return f[x]=getf(f[x]);}
void add(int x,int y){E[x].pb(y);rd[y]++;
//printf("%d %d\n",x,y);
}
queue<int>Q;
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("C.in","r",stdin);//freopen("C.out","w",stdout);
#endif
	scanf("%d%d",&m,&n);rep(i,1,m){
		rep(j,1,n)scanf("%d",&t),a[++tot]=t;
	}
	rep(i,1,tot)f[i]=i;
	rep(i,1,m){
		rep(j,1,n)tmp[j]=mp(a[pt(i,j)],j);sort(tmp+1,tmp+1+n);
		rep(k,2,n)if(tmp[k].X==tmp[k-1].X)f[getf(pt(i,tmp[k].Y))]=getf(pt(i,tmp[k-1].Y));
	}
	rep(i,1,n){
		rep(j,1,m)tmp[j]=mp(a[pt(j,i)],j);sort(tmp+1,tmp+1+m);
		rep(k,2,m)if(tmp[k].X==tmp[k-1].X)f[getf(pt(tmp[k].Y,i))]=getf(pt(tmp[k-1].Y,i));
	}
	rep(i,1,m){
		rep(j,1,n)tmp[j]=mp(a[pt(i,j)],j);sort(tmp+1,tmp+1+n);
		int lst=getf(pt(i,tmp[1].Y));
		rep(k,2,n)if(lst&&tmp[k].X!=tmp[k-1].X)add(lst,getf(pt(i,tmp[k].Y))),lst=getf(pt(i,tmp[k].Y));
	}
	rep(i,1,n){
		rep(j,1,m)tmp[j]=mp(a[pt(j,i)],j);sort(tmp+1,tmp+1+m);
		int lst=getf(pt(tmp[1].Y,i));
		rep(k,2,m)if(lst&&tmp[k].X!=tmp[k-1].X)add(lst,getf(pt(tmp[k].Y,i))),lst=getf(pt(tmp[k].Y,i));
	}
	rep(i,1,tot)if(!rd[i])Q.push(i);
	while(Q.size()){
		int k=Q.front();Q.pop();
		for(int x:E[k]){MAX(ans[x],ans[k]+1);if(--rd[x]==0)Q.push(x);}
	}
	rep(i,1,m){rep(j,1,n)printf("%d ",ans[getf(pt(i,j))]+1);puts("");}
	return 0;
}