/*
Date: 2014/10/29 07:44:05 Wednesday
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
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x7fffffff;
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

const int N=111111,M=3111111;
int l,m,n,t,C,a[N],x,y,tot,pt[N];
vector<pii>vec[N];
struct SEG{int lc,rc,v,rev,sz;}T[M];
#define L(x) T[x].lc
#define R(x) T[x].rc
void push(int x){
	if(T[x].rev)
		T[L(x)].rev^=1,T[R(x)].rev^=1,T[x].v=T[x].sz-T[x].v,T[x].rev=0;
}
void upd(int x){
	push(L(x));push(R(x));
	T[x].v=T[L(x)].v+T[R(x)].v;
	T[x].sz=T[L(x)].sz+T[R(x)].sz;
}
int creat(int l,int r){
	T[++tot].sz=1;if(l==r)return tot;
	int mid=l+r>>1,tmp=tot;L(tmp)=creat(l,mid);R(tmp)=creat(mid+1,r);
	upd(tmp);return tmp;
}
void flip(int p,int L,int R,int l,int r){
	//printf("%d %d %d %d %d\n",p,L,R,l,r);
	if(l==L&&r==R){T[p].rev^=1;push(p);return;}push(p);
	int mid=L+R>>1;if(l<=mid)flip(L(p),L,mid,l,min(r,mid));
	if(r>mid)flip(R(p),mid+1,R,max(l,mid+1),r);upd(p);
}
int ask(int p,int L,int R,int l,int r){
	if(l>r)return 0;
	push(p);
	if(l==L&&r==R)return T[p].v;
	int mid=L+R>>1,ans=0;
	if(l<=mid)ans+=ask(L(p),L,mid,l,min(r,mid));
	if(r>mid)ans+=ask(R(p),mid+1,R,max(l,mid+1),r);
	upd(p);
	return ans;
}
int main()
{
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("CF283E.in","r",stdin);//freopen("CF283E.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&a[i]);sort(a+1,a+1+n);a[n+1]=inf;
	rep(i,1,m){
		scanf("%d%d",&x,&y),x=lower_bound(a+1,a+1+n,x)-a,y=upper_bound(a+1,a+2+n,y)-a-1;
		if(x>y)continue;vec[x].pb(mp(x,y)),vec[y+1].pb(mp(x,y));
	}
	ll ans=1ll*n*(n-1)*(n-2)/6;
	creat(1,n);
	rep(i,1,n){
		rep(_,0,SZ(vec[i])-1)flip(1,1,n,vec[i][_].X,vec[i][_].Y);
		//for(pii x:vec[i])flip(1,1,n,x.X,x.Y);
		int tmp=i-1-ask(1,1,n,1,i-1)+ask(1,1,n,i+1,n);
		ans-=1ll*tmp*(tmp-1)/2;
		//printf("%d\n",i);rep(i,1,n)printf("%d %d\n",i,ask(1,1,n,i,i));
	}printf("%I64d\n",ans);
	return 0;
}