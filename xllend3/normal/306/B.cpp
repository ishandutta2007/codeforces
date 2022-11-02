/*
Date: 2014/09/28 07:29:00 Sunday
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
int l,m,n,t,C,cnt;
struct zcc{int x,y,p,ans;}a[N];
inline bool cmp(const zcc &a,const zcc &b){return a.x<b.x;}
inline bool cmpp(const zcc &a,const zcc &b){return a.p<b.p;}
int main()
{
    scanf("%d%d",&m,&n);rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y),a[i].y+=a[i].x,a[i].p=i,a[i].ans=1;
    sort(a+1,a+1+n,cmp);
    int i=0,rgt=a[1].x;while(i<=n){
        MAX(rgt,a[i].x);int tmp=max(rgt,a[i].y),pos=i++;
        while(i<=n&&a[i].x<=rgt){if(a[i].y>tmp)tmp=a[i].y,pos=i;++i;}
        if(a[pos].y>rgt)a[pos].ans=0;rgt=tmp;
    }
    sort(a+1,a+1+n,cmpp);rep(i,1,n)if(a[i].ans)++cnt;printf("%d\n",cnt);
    int bo=0;rep(i,1,n)if(a[i].ans){
        if(bo)printf(" ");printf("%d",i);bo=1;
    }puts("");
    return 0;
}