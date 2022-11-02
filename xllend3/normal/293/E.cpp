/*
Date: 2014/10/26 20:13:11 Sunday
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

const int N=222222,M=111111;
int l,m,n,t,dis[N],max1,max2,d[N],dd[N],b[N],M1,M2,s1[N],s2[N],k,ini[N],icnt,sz[N],msz[N];
int vtot,L,W;
ll ans;
pii pt[N];
vector<pii>a[N];
queue<int>Q;
struct zcc{int x,y,z;}opr[N];
inline bool cmp(const zcc &a,const zcc &b){return a.x<b.x||a.x==b.x&&a.z<b.z;}
int T[N];
void modi(int x,int k){for(int i=x;i<=L+1;i+=i&-i)T[i]+=k;}
int ask(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=T[i];return ans;}
void dfs(int x,int f){
    sz[x]=1;msz[x]=0;ini[++icnt]=x;
    rep(i,0,a[x].size()-1){
        if(b[a[x][i].X]||a[x][i].X==f)continue;
        dfs(a[x][i].X,x);sz[x]+=sz[a[x][i].X];msz[x]=max(msz[x],sz[a[x][i].X]);
    }
}
void dfs2(int x,int l,int dep,int f){
    if(b[x])return;pt[++vtot]=mp(l,dep);
    rep(i,0,a[x].size()-1)if(a[x][i].X!=f)dfs2(a[x][i].X,l+a[x][i].Y,dep+1,x);
}
int find(int x){
    icnt=0;dfs(x,0);if(icnt==0)return 0;
    int min1=n,min2;rep(i,1,icnt){
        msz[ini[i]]=max(msz[ini[i]],icnt-1-sz[ini[i]]);
        if(msz[ini[i]]<min1)min1=msz[ini[i]],min2=i;
    }return ini[min2];
}
void p(vector<int>x){printf(" %d ",x.size());rep(i,0,x.size()-1)printf("%d ",x[i]);puts("");}
ll calc(){
    ll ans=0;
    /*
    rep(i,1,vtot)opr[i]=zcc{pt[i].X,pt[i].Y,0},opr[i+vtot]=zcc{W-pt[i].X,L-pt[i].Y,1};
    vtot*=2;sort(opr+1,opr+1+vtot,cmp);
    //rep(i,1,vtot)printf("(%d,%d,%d)\n",opr[i].x,opr[i].y,opr[i].z);puts("");
    rep(i,1,vtot){
        if(opr[i].z==0){
            if(opr[i].y<=L)modi(opr[i].y+1,1);
        }else{
            if(opr[i].y<0||opr[i].y>L)continue;
            ans+=ask(opr[i].y+1);
        }
    }
    rep(i,1,vtot)if(opr[i].z==0)if(opr[i].y<=L)modi(opr[i].y+1,-1);
    int lans=ans;ans=0;vtot/=2;
    */
    sort(pt+1,pt+vtot+1);
    //rep(i,1,vtot)printf("(%d,%d)\n",pt[i].X,pt[i].Y);puts("");
    int j=vtot;
    rep(i,1,vtot){
        while(j>=1&&W-pt[j].X<pt[i].X){
            if(pt[j].Y>=0&&pt[j].Y<=L)ans+=ask(L-pt[j].Y+1);--j;
        }
        if(pt[i].Y<=L)modi(pt[i].Y+1,1);
    }
    dep(p,j,1)if(pt[p].Y>=0&&pt[p].Y<=L)ans+=ask(L-pt[p].Y+1);
    rep(i,1,vtot)if(pt[i].Y<=L)modi(pt[i].Y+1,-1);
    //printf("%d %d\n",lans,ans);
    return ans;
}
void cut(int x){
    b[x]=1;
    vtot=1;pt[1]=mp(0,0);rep(i,0,a[x].size()-1)if(!b[a[x][i].X])dfs2(a[x][i].X,a[x][i].Y,1,x);ans+=calc();
    //printf("%d %d\n",x,ans);
    rep(i,0,a[x].size()-1)if(!b[a[x][i].X]){vtot=0;dfs2(a[x][i].X,a[x][i].Y,1,x);ans-=calc();}
    ans--;
    //printf("%d %d\n",x,ans);
    rep(i,0,a[x].size()-1)if(!b[a[x][i].X])cut(find(a[x][i].X));
}
int main()
{
    read(n,L,W);
    rep(i,2,n)read(l,t),a[i].pb(mp(l,t)),a[l].pb(mp(i,t));
    cut(find(1));
    printf("%lld\n",ans/2);
    return 0;
}