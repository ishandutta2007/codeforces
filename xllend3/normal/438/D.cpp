/*
Date: 2014/06/01 20:35:30 Sunday
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

const int N=888888,M=111111;
int l,m,n,t,v[N],opt,Max[N],x,y,p;
ll sum[N];
#define upd(x) Max[x]=max(Max[(x)<<1],Max[((x)<<1)+1]),sum[x]=sum[(x)<<1]+sum[((x)<<1)+1];
void creat(int x,int l,int r){
    if(l==r){Max[x]=sum[x]=v[l];return;}
    int mid=l+r>>1;creat(x<<1,l,mid);creat((x<<1)+1,mid+1,r);
    upd(x);
}
ll que(int x,int l,int r,int L,int R){
    if(l==L&&r==R){
        return sum[x];
    }int mid=L+R>>1;ll ans=0;
    if(l<=mid)ans+=que(x<<1,l,min(r,mid),L,mid);
    if(r>mid)ans+=que((x<<1)+1,max(l,mid+1),r,mid+1,R);
    return ans;
}
void modi(int x,int l,int r,int p,int L,int R){
    if(Max[x]<p)return;
    if(L==R){
        v[L]%=p;Max[x]=sum[x]=v[L];
        return;
    }int mid=L+R>>1;
    if(l<=mid)modi(x<<1,l,min(r,mid),p,L,mid);
    if(r>mid)modi((x<<1)+1,max(l,mid+1),r,p,mid+1,R);
    upd(x);
}
void modi(int x,int k,int p,int L,int R){
    if(L==R){
        v[L]=p;Max[x]=sum[x]=v[L];
        return;
    }int mid=L+R>>1;
    if(k<=mid)modi(x<<1,k,p,L,mid);else modi((x<<1)+1,k,p,mid+1,R);
    upd(x);
}
int main()
{
    scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&v[i]);creat(1,1,n);
    while(m--){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d",&x,&y);printf("%lld\n",que(1,x,y,1,n));
        }else if(opt==2){
            scanf("%d%d%d",&x,&y,&p);modi(1,x,y,p,1,n);
        }else{
            scanf("%d%d",&x,&y);modi(1,x,y,1,n);
        }
    }
    return 0;
}