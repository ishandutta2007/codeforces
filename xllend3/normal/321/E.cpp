/*
Date: 2014/06/19 12:48:14 Thursday
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

const int N=4044,M=111111;
int l,m,n,t,v[N][N],f[N][N],opt[N][N],sum[N][N],row[N][N];
void calc(int p,int L,int R,int l,int r){
    int mid=L+R>>1;rep(i,l,r){
        if(i>=mid)break;
        if(f[p-1][i]+v[i+1][mid]<=f[p][mid])f[p][mid]=f[p-1][i]+v[i+1][mid],opt[p][mid]=i;
    }
    //printf("%d %d %d %d %d %d %d %d\n",p,L,R,l,r,mid,f[p][mid],opt[p][mid]);
    //printf("%d %d %d %d\n",p,mid,f[p][mid],opt[p][mid]);
    if(L==R)return;
    if(L<mid)calc(p,L,mid-1,l,opt[p][mid]);
    if(mid<R)calc(p,mid+1,R,opt[p][mid],r);
}
//#include<ctime>
int main()
{
    read(n);read(m);rep(i,1,n)rep(j,1,n)read(sum[i][j]);
    rep(i,1,n)rep(j,1,n)row[i][j]=row[i][j-1]+sum[i][j];
    rep(i,1,n)rep(j,1,n)sum[i][j]=sum[i-1][j]+row[i][j];
    rep(i,1,n)rep(j,1,n)v[i][j]=(sum[i-1][i-1]+sum[j][j]-sum[i-1][j]-sum[j][i-1])/2;
    //printf("%d\n",clock());
    memset(f,0x20,sizeof(f));
    f[0][0]=0;
    rep(i,1,m)calc(i,1,n,0,n-1);
    printf("%d\n",f[m][n]);
    //printf("%d\n",clock());
    return 0;
}