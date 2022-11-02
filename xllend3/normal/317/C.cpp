/*
Date: 2014/09/26 07:47:24 Friday
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

const int N=333,M=222222;
int l,m,n,t,C,a[N],b[N],dis[N][N],v;
int X[M],Y[M],D[M],tot;
void print(int x,int y,int k){if(k){X[++tot]=x;Y[tot]=y;D[tot]=k;a[x]-=k;a[y]+=k;}}
void mov(int x,int y,int k){
    if(dis[x][y]==1)print(x,y,k);
    else{
        int p;rep(i,1,n)if(dis[i][y]==1&&dis[x][i]+1==dis[x][y])p=i;
        if(a[p]>k){
            print(p,y,k);mov(x,p,k);
        }else{
            int t=a[p];print(p,y,t);
            mov(x,p,k);print(p,y,k-t);
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&v,&m);rep(i,1,n)scanf("%d",&a[i]);rep(i,1,n)scanf("%d",&b[i]);
    rep(i,1,n)rep(j,1,n)dis[i][j]=n+1;
    rep(i,1,m)scanf("%d%d",&l,&t),dis[l][t]=dis[t][l]=1;
    rep(k,1,n)rep(i,1,n)rep(j,1,n)MIN(dis[i][j],dis[i][k]+dis[k][j]);
    rep(i,1,n)rep(j,1,n)if(dis[i][j]<n&&a[i]>b[i]&&a[j]<b[j])mov(i,j,min(a[i]-b[i],b[j]-a[j]));
    rep(i,1,n)if(a[i]!=b[i]){puts("NO");return 0;}
    printf("%d\n",tot);
    rep(i,1,tot)printf("%d %d %d\n",X[i],Y[i],D[i]);
    return 0;
}