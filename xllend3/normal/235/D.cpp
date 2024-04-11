/*
Date: 2014/09/24 11:45:45 Wednesday
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

const int N=111111,M=111111;
int l,m,n,t,C,ctot;
int vis[N],cir[N],pt[N],dis[N],fa[N][22];
vector<int>a[N];
int dfs(int x,int f){
    if(vis[x])return x;vis[x]=1;int t;
    rep(i,0,SZ(a[x])-1)if(a[x][i]!=f){
        if(t=dfs(a[x][i],x)){
            cir[++ctot]=x;
            if(x==t)return 0;
            return t;
        }
    }else f=0;
    return 0;
}
void dfs(int x){
    rep(i,0,SZ(a[x])-1)if(!pt[a[x][i]]){
        dis[a[x][i]]=dis[x]+1;pt[a[x][i]]=pt[x];fa[a[x][i]][0]=x;
        dfs(a[x][i]);
    }
}
int lca(int x,int y){
    if(dis[x]>dis[y])swap(x,y);
    dep(i,20,0)if(fa[y][i]&&dis[fa[y][i]]>=dis[x])y=fa[y][i];
    if(x==y)return x;
    dep(i,20,0)if(fa[y][i]!=fa[x][i])y=fa[y][i],x=fa[x][i];
    return fa[y][0];
}
int main()
{
    scanf("%d",&n);rep(i,1,n)scanf("%d%d",&l,&t),++l,++t,a[l].pb(t),a[t].pb(l);
    dfs(1,0);
    rep(i,1,ctot)pt[cir[i]]=i;
    rep(i,1,ctot)dfs(cir[i]);
    rep(i,1,20)rep(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
    lf ans=0;
    //rep(i,1,n)printf("%d %d\n",dis[i],pt[i]);
    rep(i,1,n)rep(j,1,n)if(i!=j){
        if(pt[i]==pt[j]){
            int p=dis[i]+dis[j]-2*dis[lca(i,j)]+1;
            ans+=1.0/p;
        }else{
            int p1=dis[i]+dis[j],p2=abs(pt[i]-pt[j]),p3=ctot-abs(pt[i]-pt[j]);
            //printf("%d %d %d %d %d %.9lf\n",i,j,p1,p2,p3,ans);
            ans+=1.0/(p1+p2+1)+1.0/(p1+p3+1)-1.0/(p1+p2+p3);
        }
    }printf("%.9lf\n",ans+n);
    return 0;
}