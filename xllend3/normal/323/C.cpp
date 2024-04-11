/*
Date: 2014/10/14 14:13:42 Tuesday
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

const int N=1111111,M=31111111;
int l,m,n,t,C,a[N],b[N],c[N],lans,l1,r1,l2,r2,tot,root[N];
struct EDGE {int l,r,s;}e[M];
int creat(int l,int r){
    if(l>r)return 0;e[++tot].s=0;int k=tot;if(l==r)return k;
    e[k].l=creat(l,(l+r)/2);e[k].r=creat((l+r)/2+1,r);return k;
}
int mdf(int root,int x,int L,int R){
    int k=++tot;e[k]=e[root];++e[k].s;if(L==x&&R==x)return k;
    int mid=L+R>>1;if(x<=mid)e[k].l=mdf(e[root].l,x,L,mid);else e[k].r=mdf(e[root].r,x,mid+1,R);
    return k;
}
int que(int x,int y,int l,int r,int L,int R){
	if(l==L&&r==R)return e[y].s-e[x].s;
	int mid=L+R>>1,ans=0;
	if(l<=mid)ans+=que(e[x].l,e[y].l,l,min(mid,r),L,mid);
	if(r>mid)ans+=que(e[x].r,e[y].r,max(mid+1,l),r,mid+1,R);
	return ans;
}
int f(int x){return (x-1+lans)%n+1;}
int main()
{
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);rep(i,1,n)scanf("%d",&b[i]),c[b[i]]=i;
	rep(i,1,n)a[i]=c[a[i]];
	root[0]=creat(1,n);rep(i,1,n)root[i]=mdf(root[i-1],a[i],1,n);
	scanf("%d",&C);rep(_,1,C){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		l=l1;l1=min(f(l),f(r1));r1=max(f(l),f(r1));
		l=l2;l2=min(f(l),f(r2));r2=max(f(l),f(r2));
		printf("%d\n",lans=que(root[l1-1],root[r1],l2,r2,1,n));lans++;
	}
	//rep(i,1,n)printf("%d ",a[i]);puts("");
	//printf("%d %d %d %d\n",l1,r1,l2,r2);
	return 0;
}