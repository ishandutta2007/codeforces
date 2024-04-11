/*
Date: 2014/06/01 20:35:28 Sunday
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
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define dep(i,a,n) for (int i = a; i >= n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define eps 1e-8
#define lowbit(x) (x&(-x))
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
/*inline void read(int &x){
    char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar());
    for(x=0;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-48;
}*/
inline void read(int &x)
{
   char ch;bool f=0;int a=0;
   while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
   if(ch!='-')a*=10,a+=ch-'0';else f=1;
   while(((ch=getchar())>='0')&&(ch<='9'))a*=10,a+=ch-'0';
   if(f)a=-a;x=a;
}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=111111,M=111111;
int l,m,n,t,v[N],f[N],sz[N];
struct zcc{int l,r,v,x,u;}a[N];
inline bool cmp(const zcc &a,const zcc &b){return a.v<b.v;}
int getf(int x){if(x==f[x])return x;return f[x]=getf(f[x]);}
lf ans;
int main()
{
    scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&v[i]);
    rep(i,1,m)scanf("%d%d",&a[i].l,&a[i].r),a[i].v=min(v[a[i].l],v[a[i].r]),a[i].x=i;
    sort(a+1,a+1+m,cmp);
    rep(i,1,n)f[i]=i,sz[i]=1;
    dep(i,m,1)if(getf(a[i].l)!=getf(a[i].r))f[getf(a[i].l)]=getf(a[i].r);else a[i].u=1;
    rep(i,1,n)f[i]=i,sz[i]=1;
    dep(i,m,1)if(!a[i].u){
        int x=getf(a[i].l),y=getf(a[i].r);
        ans+=1.0*sz[y]*sz[x]*a[i].v;
        //printf("%d %d\n",sz[y]*sz[x],a[i].v);
        f[x]=y;sz[y]+=sz[x];
    }
    //printf("%.9lf\n",ans);
    printf("%.9lf\n",ans/n/(n-1)*2);
    return 0;
}