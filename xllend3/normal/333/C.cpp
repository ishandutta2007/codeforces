/*
Date: 2014/10/08 15:12:07 Wednesday
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

const int N=11111,M=111111;
int l,m,n,t,C,vis[N];
void dfs(int num,int cal,int rest,int dep){
    if(!m)return;
    //printf("%d %d %d %d\n",num,cal,rest,dep);
    if(dep>3){
        if(dep>4)return;
        if(cal+n<10000&&cal+n>=0&&vis[cal+n]!=num&&m){vis[cal+n]=num;printf("%04d%04d\n",cal+n,num);m--;}
        if(n-cal<10000&&n-cal>=0&&vis[n-cal]!=num&&m){vis[n-cal]=num;printf("%04d%04d\n",n-cal,num);m--;}
        return;
    }
    dfs(num,cal+rest%10,rest/10,dep+1);dfs(num,cal*(rest%10),rest/10,dep+1);dfs(num,rest%10-cal,rest/10,dep+1);
    dfs(num,cal+rest%100,rest/100,dep+2);dfs(num,cal*(rest%100),rest/100,dep+2);dfs(num,rest%100-cal,rest/100,dep+2);
}
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,0,9999)dfs(i,i%10,i/10,1),dfs(i,i%100,i/100,2),dfs(i,i%1000,i/1000,3);
    return 0;
}