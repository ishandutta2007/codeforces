/*
Date: 2014/09/28 08:44:05 Sunday
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
#define rep(i,a,n) for(int _tmp=(n),i=a;i<=_tmp;++i)
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
int l,m,n,t,C,a[N],b[N];
pii res[9];
int calc(){
    int ans=0;
    rep(i,1,n-1)b[i]=a[i+1]-a[i];b[0]=b[1];
    rep(i,1,n-1)if(b[i]==b[i-1]&&abs(b[i])==1);else b[i]=b[i+1],++ans;
    //rep(i,1,n)printf("%d ",a[i]);printf("[%d]\n",ans);
    return ans;
}
void rev(int l,int r){rep(i,l,l+r>>1)swap(a[i],a[r+l-i]);}
int ok(){rep(i,1,n)if(a[i]!=i)return 0;return 1;}
void dfs(int x){
    if(ok()){
        printf("%d\n",x-1);
        dep(i,x-1,1)printf("%d %d\n",res[i].X,res[i].Y);
        exit(0);
    }
    if(x>3)return;
    int p=calc();
    rep(i,1,n)rep(j,i+1,n)if(abs(a[i-1]-a[j])==1||abs(a[i]-a[j+1])==1)
    {
        rev(i,j);int t=calc();if(t<=(3-x)*2&&t<=p){
            res[x].X=i;res[x].Y=j;dfs(x+1);
        }rev(i,j);
    }
}
int main()
{
    scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);a[0]=0;a[n+1]=n+1;
    dfs(1);
    return 0;
}