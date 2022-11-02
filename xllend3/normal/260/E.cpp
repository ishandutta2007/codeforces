/*
Date: 2014/10/28 19:24:39 Tuesday
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

const int N=111111,M=3111111;
int l,m,n,t,C,Xtot,Ytot,num[10];
map<int,int>SX,SY;
struct EDGE {int a,b,l,r,s;} e[M];
struct zcc{int x,y;}a[N],b[N];
inline bool cmpx(const zcc &a,const zcc &b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
inline bool cmpy(const zcc &a,const zcc &b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
int tot,root[N];
int creat(int l,int r){
    if(l>r)return 0;e[++tot].a=l;e[tot].b=r;e[tot].s=0;int k=tot;if(l==r)return k;
    e[k].l=creat(l,(l+r)/2);e[k].r=creat((l+r)/2+1,r);return k;
}
int mdf(int root,int x){
    int k=++tot;e[k]=e[root];++e[k].s;if(e[root].a==x&&e[root].b==x)return k;
    int mid=(e[root].a+e[root].b)/2;if(x<=mid)e[k].l=mdf(e[root].l,x);else e[k].r=mdf(e[root].r,x);
    return k;
}
int ask(int x,int y,int t){
    if(e[x].a==e[x].b)return e[x].s-e[y].s;int mid=e[x].a+e[x].b>>1;
    if(t<=mid)return ask(e[x].l,e[y].l,t);return ask(e[x].r,e[y].r,t)+e[e[x].l].s-e[e[y].l].s;
}
int que(int x,int y){return ask(root[SX[x]],root[0],SY[y]);}
int main()
{
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("CF260E.in","r",stdin);//freopen("CF260E.out","w",stdout);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y),SX[a[i].x]++,SY[a[i].y]++,b[i]=a[i];
	ALL(it,SX)it->Y=(Xtot+=it->Y);ALL(it,SY)it->Y=++Ytot;
	sort(a+1,a+1+n,cmpx);sort(b+1,b+1+n,cmpy);
	root[0]=creat(1,Ytot);
	rep(i,1,n)root[i]=mdf(root[i-1],SY[a[i].y]);
	rep(i,1,9)scanf("%d",&num[i]);sort(num+1,num+10);
	//rep(i,1,n)rep(j,1,n)printf("%d %d %d\n",a[i].x,b[j].y,que(a[i].x,b[j].y));
	//rep(i,1,n)printf("%d %d\n",a[i].x,SX[a[i].x]);
	//rep(i,1,n)printf("%d %d\n",b[i].y,SY[b[i].y]);
	do{
		//puts("orz");
		int X1=num[1]+num[2]+num[3];
		int X2=X1+num[4]+num[5]+num[6];
		int Y1=num[1]+num[4]+num[7];
		int Y2=Y1+num[2]+num[5]+num[8];
		if(a[X1+1].x==a[X1].x)continue;
		if(a[X2+1].x==a[X2].x)continue;
		if(b[Y1+1].y==b[Y1].y)continue;
		if(b[Y2+1].y==b[Y2].y)continue;
		//printf("%d %d %d %d\n",X1,X2,Y1,Y2);
		//printf("%.1lf %.1lf %.1lf %.1lf\n",a[X1].x+0.5,a[X2].x+0.5,b[Y1].y+0.5,b[Y2].y+0.5);
		if(que(a[X1].x,b[Y1].y)!=num[1])continue;
		if(que(a[X1].x,b[Y2].y)!=num[1]+num[2])continue;
		if(que(a[X2].x,b[Y1].y)!=num[1]+num[4])continue;
		if(que(a[X2].x,b[Y2].y)!=num[1]+num[2]+num[4]+num[5])continue;
		printf("%.1lf %.1lf\n%.1lf %.1lf\n",a[X1].x+0.5,a[X2].x+0.5,b[Y1].y+0.5,b[Y2].y+0.5);
		return 0;
	}while(next_permutation(num+1,num+10));
	puts("-1");
	return 0;
}