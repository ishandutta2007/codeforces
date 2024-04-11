/*
Date: 2014/03/20 18:49:43 Thursday
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
#define MAX(a,b) a=max(a,b);
#define MIN(a,b) a=min(a,b);
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define CLR(a) memset(a,0,sizeof(a));
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

const int N=1111111,M=111111;
int l,m,n,t,f[N][5],ans;
char s[N];
//0-* 1-1l 2-1x 3-0 4-2
int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    rep(i,1,2)f[0][i]=1;
    rep(i,1,n){
        if(s[i]=='0'){f[i][3]=f[i-1][1]+f[i-1][3];}
        else if(s[i]=='*'){f[i][0]=(f[i-1][2]+f[i-1][4])%mod+f[i-1][0];}
        else if(s[i]=='1'){f[i][1]=f[i-1][0];f[i][2]=f[i-1][1]+f[i-1][3];}
        else if(s[i]=='2'){f[i][4]=f[i-1][0];}
        else{f[i][0]=(f[i-1][2]+f[i-1][4])%mod+f[i-1][0];
            f[i][1]=f[i-1][0];
            f[i][2]=f[i-1][1]+f[i-1][3];
            f[i][3]=f[i-1][1]+f[i-1][3];
            f[i][4]=f[i-1][0];
        }
        rep(j,0,4)f[i][j]%=mod;
    }
    //rep(i,0,n){rep(j,0,4)printf("%d ",f[i][j]);puts("");}
    ans=(f[n][0]+f[n][1])%mod+f[n][3];printf("%d\n",ans%mod);
    return 0;
}