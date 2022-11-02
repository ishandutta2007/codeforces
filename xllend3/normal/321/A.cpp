/*
Date: 2014/06/19 12:48:11 Thursday
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
#define y1 SJKDghdfklagh
int l,m,n,t,x,y,x1,y1,p1,p2;
char s[N];
set<pii>S;
int main()
{
    scanf("%d%d",&x,&y);scanf("%s",s+1);n=strlen(s+1);x1=y1=0;S.insert(mp(0,0));
    rep(i,1,n){
        switch(s[i]){
            case 'U':y1++;break;
            case 'D':y1--;break;
            case 'L':x1--;break;
            case 'R':x1++;break;
        }S.insert(mp(x1,y1));
        //printf("%d %d\n",x1,y1); 
    }
    if(x1==0&&y1==0){
        if(S.find(mp(x,y))!=S.end()){puts("Yes");return 0;}
        puts("No");return 0;
    }else if(x1!=0&&y1!=0){
        m=min(x/x1,y/y1);
    }else m=(x1==0)?y/y1:x/x1;
    x-=m*x1;y-=m*y1;
    x+=min(100,m)*x1;y+=min(100,m)*y1;
    rep(_,1,200){
        if(S.find(mp(x,y))!=S.end()){puts("Yes");return 0;}
        x-=x1;y-=y1;
        //printf("%d %d\n",x,y);
    }puts("No");
    return 0;
}