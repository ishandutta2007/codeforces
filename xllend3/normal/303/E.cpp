/*
Date: 2015/01/04 09:33:15 Sunday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
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

const int N=199,M=111111;
int m,n,t,C,tot;
int l[N],r[N],MA[N*2];
lf res[N],dp[N][N],tmp[N][N];
void work(int x,int y){
    CLR(dp);dp[0][0]=1.0*(MA[y+1]-MA[y])/(r[x]-l[x]);int s1=0,s2=0;
    rep(_,1,n)if(_!=x){
        //dep(i,_+1,0)dep(j,_-i+1,0)tmp[i][j]=0;
        if((min(r[_],MA[y])-min(l[_],MA[y]))==(r[_]-l[_])){s1++;continue;}
        if((max(r[_],MA[y+1])-max(l[_],MA[y+1]))==(r[_]-l[_])){s2++;continue;}
        lf p1=1.0*(min(r[_],MA[y])-min(l[_],MA[y]))/(r[_]-l[_]);
        lf p3=1.0*(max(r[_],MA[y+1])-max(l[_],MA[y+1]))/(r[_]-l[_]);
        lf p2=1-p1-p3;
        //printf("%d %d %d %d %d %d %.9lf %.9lf\n",x,MA[y],MA[y+1],i,l[i],r[i],p1,p3);
        dep(i,_,0)dep(j,_-i,0)if(dp[i][j]){
            dp[i+1][j]+=dp[i][j]*p1,dp[i][j+1]+=dp[i][j]*p3,dp[i][j]=dp[i][j]*p2;
        }
        //dep(i,_+1,0)dep(j,_-i+1,0)dp[i][j]=tmp[i][j];
    }
    //rep(i,0,n){rep(j,0,n)printf("%.3lf ",dp[i][j]);puts("");}
    if(s1||s2)dep(i,n,0)dep(j,n-i,0)dp[i+s1][j+s2]=dp[i][j],dp[i][j]=0;
    //rep(i,0,n){rep(j,0,n)printf("%.3lf ",dp[i][j]);puts("");}
    rep(i,0,n)rep(j,0,n-i)if(i+1<=i+(n-i-j))res[i+1]+=dp[i][j]/(n-i-j),res[i+(n-i-j)+1]-=dp[i][j]/(n-i-j);
    //rep(k,i+1,i+(n-i-j))res[k]+=dp[i][j]/(n-i-j);
}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF303E.in","r",stdin);//freopen("CF303E.out","w",stdout);
#endif
    scanf("%d",&n);rep(i,1,n)scanf("%d%d",&l[i],&r[i]),MA[++tot]=l[i],MA[++tot]=r[i];
    sort(MA+1,MA+1+tot);tot=unique(MA+1,MA+1+tot)-MA-1;
    rep(i,1,n){
        CLR(res);rep(j,1,tot-1)if(l[i]<=MA[j]&&MA[j+1]<=r[i])work(i,j);
        res[0]=0;rep(i,1,n)printf("%.9lf ",res[i]+=res[i-1]);puts("");
    }
    return 0;
}