/*
Date: 2014/10/08 09:29:25 Wednesday
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
int l,m,n,t,C,dcnt,isdc;
int a[N],p[N],b[N];
struct zcc{int x,y,ans,num;}q[N];
inline bool cmpy(const zcc &a,const zcc &b){return a.y<b.y;}
inline bool cmpnum(const zcc &a,const zcc &b){return a.num<b.num;}
struct BIT{
    int a[N];
    void modi(int x,int k){for(int i=x;i<=n;i+=i&-i)a[i]+=k;}
    int que(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=a[i];return ans;}
}A,B;
int main()
{
    scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]),p[i]=b[a[i]],b[a[i]]=i;
    scanf("%d",&m);rep(i,1,m)scanf("%d%d",&q[i].x,&q[i].y),q[i].num=i;
    sort(q+1,q+1+m,cmpy);
    CLR(b);int pt=1;
    rep(i,1,n){
        A.modi(p[i]+1,1);A.modi(i+1,-1);
        if(p[p[i]]&&i-p[i]!=p[i]-p[p[i]])B.modi(b[a[i]]+1,1),B.modi(p[p[i]]+1,-1),b[a[i]]=p[p[i]];
        while(q[pt].y==i){
            q[pt].ans=A.que(q[pt].x);
            q[pt].ans+=q[pt].ans==B.que(q[pt].x);
            ++pt;
        }
    }
    sort(q+1,q+1+m,cmpnum);
    rep(i,1,m)printf("%d\n",q[i].ans);
    return 0;
}