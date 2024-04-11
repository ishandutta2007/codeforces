/*
Date: 2014/10/28 08:14:20 Tuesday
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

const int N=11111,M=111111;
int l,m,n,t,C,x,y;
int a[5][N],b[5][N],ma[N];
int f[N][8];
int calc(){
    CLR(f);
    f[1][0]=1;
    rep(i,1,n)rep(j,0,7)if(f[i][j]&&((ma[i]&j)==0)){
        //printf("%d %d %d\n",i,j,f[i][j]);
        rep(k,0,7)if(((k^7)&(ma[i]|j))==(ma[i]|j)){
            int tmp=(k^7)^(ma[i]|j);
            if(tmp==0||tmp==3||tmp==6)f[i+1][k]=(f[i+1][k]+f[i][j])%mod;
        }
    }
    return f[n+1][0];
}
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("CF342D.in","r",stdin);//freopen("CF342D.out","w",stdout);
#endif
    scanf("%d",&n);rep(i,0,4)rep(j,0,n+1)a[i][j]=1;
    rep(i,1,3)rep(j,1,n){
        for(t=getchar();t<=32;t=getchar());
        if(t=='.')a[i][j]=0;
        else if(t=='O')x=i,y=j,a[i][j]=1;
        else a[i][j]=1;
    }
    ll ans=0;
    rep(mask,1,15){
        b[x-1][y]=b[x-2][y]=mask&1;
        b[x+1][y]=b[x+2][y]=mask&2;
        b[x][y-1]=b[x][y-2]=mask&4;
        b[x][y+1]=b[x][y+2]=mask&8;
        int bo=0;rep(i,0,4)rep(j,0,n+1)if(a[i][j]&&b[i][j])bo=1;
        if(bo)continue;
        rep(i,1,n)ma[i]=(a[1][i]||b[1][i])+(a[2][i]||b[2][i])*2+(a[3][i]||b[3][i])*4;
        //rep(i,1,n)printf("%d %d\n",i,ma[i]);
        if(((mask&1)+!!(mask&2)+!!(mask&4)+!!(mask&8))&1)ans+=calc();else ans-=calc();
    }
    printf("%I64d\n",(ans%mod+mod)%mod);
    return 0;
}