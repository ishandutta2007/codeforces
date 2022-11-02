/*
Date: 2014/11/24 08:47:17 Monday
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
int l,m,n,t,C,r;
ll sum[9],f[N][4],pos[N],sg[N];
ll calc(ll x,ll y){
    return (m+m-x-y)*(y-x+1)/2%mod;
}
int main()
{
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF273E.in","r",stdin);freopen("CF273E.out","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    pos[1]=2;l=r=t=1;rep(x,2,m){
        //printf("%d %d %d %d\n",pos[l],pos[r],pos[x-1],sg[x-1]);
        if(pos[x-1]>=m)break;ll p=pos[x-1]+1;
        if(pos[l]<p/3)l++;
        if(pos[r]<p-p/3)r++;
        pos[x]=min(pos[l]*3+2,pos[r]*3/2);
        rep(i,0,2)if(i!=sg[l]&&i!=sg[r]){sg[x]=i;break;}
        if(sg[x]==sg[x-1])pos[x-1]=pos[x],x--;
        t=x;
    }MIN(pos[t],ll(m-1));
    rep(i,1,t)sum[sg[i]]=(sum[sg[i]]+calc(pos[i-1]+1,pos[i]))%mod;
    //printf("%lld %lld %lld\n",sum[0],sum[1],sum[2]);
    f[0][0]=1;
    rep(i,1,n)rep(j,0,3)rep(k,0,3)f[i][j]=(f[i][j]+f[i-1][k]*sum[k^j])%mod;
    printf("%I64d\n",(f[n][1]+f[n][2]+f[n][3])%mod);
    return 0;
}