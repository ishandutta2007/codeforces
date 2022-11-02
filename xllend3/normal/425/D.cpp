/*
Date: 2014/05/12 18:27:59 Monday
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
inline void r(int &x)
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
int l,m,n,t;
struct zcc{int x,y;}a[N];
ll ans;
set<int>S1[N],S2[N];
inline bool cmp(const zcc &a,const zcc &b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
int main()
{
    r(n);rep(i,1,n)r(a[i].x),r(a[i].y),S1[a[i].x].insert(a[i].y),S2[a[i].y].insert(a[i].x);
    sort(a+1,a+1+n,cmp);
    rep(i,1,n){
        S1[a[i].x].erase(a[i].y);S2[a[i].y].erase(a[i].x);
        if(SZ(S1[a[i].x])>SZ(S2[a[i].y])){
            re(S2[a[i].y],set<int>)if(S1[a[i].x].find(*it-a[i].x+a[i].y)!=S1[a[i].x].end()&&
                S1[*it].find(*it-a[i].x+a[i].y)!=S1[*it].end())++ans;
        }else{
            swap(a[i].x,a[i].y);
            re(S1[a[i].y],set<int>)if(S2[a[i].x].find(*it-a[i].x+a[i].y)!=S2[a[i].x].end()&&
                S2[*it].find(*it-a[i].x+a[i].y)!=S2[*it].end())++ans;
        }
        //printf("%d %d\n",i,ans);
    }printf("%lld\n",ans);
    return 0;
}