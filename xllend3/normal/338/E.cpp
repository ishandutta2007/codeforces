/*
Date: 2014/11/19 14:57:13 Wednesday
Author: xllend3
*/
/*
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
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
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
const int inf=0x3fffffff;
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

const int N=151111,M=16111111;
int l,m,n,t,C,tot,rt,b[N];
struct Node{int lc,rc,m,bj;}a[M];
void push(int x){
	if(!x)return;if(!a[x].lc)a[x].lc=++tot;if(!a[x].rc)a[x].rc=++tot;
	a[x].m+=a[x].bj;a[a[x].lc].bj+=a[x].bj;a[a[x].rc].bj+=a[x].bj;a[x].bj=0;
}
void upd(int x){
	if(!x)return;if(!a[x].lc)a[x].lc=++tot;if(!a[x].rc)a[x].rc=++tot;
	push(x);push(a[x].lc);push(a[x].rc);
	if(a[x].lc||a[x].rc)a[x].m=min(a[a[x].lc].m,a[a[x].rc].m);
}
void add(int &x,int L,int R,int l,int r,int k){
	push(x);
	if(!x)x=++tot;
	if(l==L&&r==R){
		a[x].bj+=k;upd(x);
	//if(R<=10)printf("%d %d %d\n",L,R,a[x].m);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid)add(a[x].lc,L,mid,l,min(mid,r),k);
	if(r>mid)add(a[x].rc,mid+1,R,max(mid+1,l),r,k);
	upd(x);
	//if(R<=10)printf("%d %d %d\n",L,R,a[x].m);
}
int main()
{
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("CF338E.in","r",stdin);//freopen("CF338E.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&t);
	rep(i,1,m)scanf("%d",&l),add(rt,0,inf,0,max(0,t-l),-1);
	rep(i,1,n)scanf("%d",&b[i]);
	rep(i,1,m-1)add(rt,0,inf,0,b[i],1);
	int ans=0;
	rep(i,m,n){
		//printf("%d\n",a[rt].m);
		add(rt,0,inf,0,b[i],1);
		if(a[rt].m>=0)++ans;
		//printf("%d\n",a[rt].m);
		add(rt,0,inf,0,b[i-m+1],-1);
	}printf("%d\n",ans);
	return 0;
}