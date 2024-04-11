/*
Date: 2014/06/19 12:48:12 Thursday
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
int l,m,n,t,b[N],ans,tot;
struct zcc{int a,b;}a[N];
inline bool cmp1(const zcc &a,const zcc &b){return a.b-a.a*10000<b.b-b.a*10000;}
inline bool cmp2(const zcc &a,const zcc &b){return a.b+a.a*10000<b.b+b.a*10000;}
multiset<int>S;
multiset<int>::iterator it;
char s[N];
int main()
{
    scanf("%d%d",&m,&n);rep(i,1,m)scanf("%s%d",s,&a[i].b),a[i].a=(s[0]=='A');
    rep(i,1,n)scanf("%d",&b[i]);
    sort(a+1,a+1+m,cmp1);sort(b+1,b+1+n);
    rep(i,1,n){
        if(a[i].a==0)break;if(i>m)break;if(a[i].b>=b[n-i+1])break;
        ans+=b[n-i+1]-a[i].b;
    }
    if(n>m){
        rep(i,1,n)S.insert(b[i]);
        sort(a+1,a+1+m,cmp2);
        rep(i,1,m){
            if(a[i].a)it=S.lower_bound(a[i].b);
            else it=S.upper_bound(a[i].b);
            if(it==S.end()){printf("%d\n",ans);return 0;}
            if(a[i].a)tot+=*it-a[i].b;
            S.erase(it);
        }for(;S.size();S.erase(S.begin()))tot+=*(S.begin());
        MAX(ans,tot);
    }printf("%d\n",ans);
    return 0;
}