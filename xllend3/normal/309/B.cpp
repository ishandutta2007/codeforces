/*
Date: 2014/11/18 08:06:26 Tuesday
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

const int N=1111111,M=111111;
int l,m,n,t,C,r,c;
int a[N],nxt[N],bz[N][22],sum[N];
string s[N];
int calc(int x){
    int y=x;
    dep(i,20,0)if(r&(1<<i))y=bz[y][i]+1;
    return y-x;
}
void print(int x){
    int y=x,wid=0;
    dep(i,20,0)if(r&(1<<i))y=bz[y][i]+1;
    rep(i,x,min(y-1,n)){
        if(wid+a[i]>c)wid=0,puts("");
        if(wid!=0)putchar(' ');printf("%s",s[i].c_str());
        wid+=a[i];
    }
}
int main()
{
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF309B.in","r",stdin);//freopen("CF309B.out","w",stdout);
#endif
    scanf("%d%d%d",&n,&r,&c);++c;
    rep(i,1,n)cin>>s[i],a[i]=SZ(s[i])+1,sum[i]=sum[i-1]+a[i];
    rep(i,1,n){if(sum[i]>c)break;nxt[1]=i;}bz[1][0]=nxt[1];
    rep(i,2,n){
        nxt[i]=nxt[i-1];while(sum[nxt[i]]-sum[i-1]<=c&&nxt[i]<=n)++nxt[i];--nxt[i];bz[i][0]=nxt[i];
    }bz[n+1][0]=n;
    rep(j,1,20)rep(i,1,n+1)bz[i][j]=bz[bz[i][j-1]+1][j-1];
    int ans=0,pos=0;
    //rep(i,1,n)printf("%d %d\n",i,calc(i));
    rep(i,1,n)if(calc(i)>ans)ans=calc(i),pos=i;
    print(pos);
    return 0;
}