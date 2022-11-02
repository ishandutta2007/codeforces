/*
Date: 2014/11/26 10:56:24 Wednesday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
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

const int N=155,M=111111;
int l,m,n,t,C;
ll ans;
ll f[N][N][2][2],s[N][N][2][2];
void add(ll &x,ll y){x=(x+y)%mod;}
ll sum(int a,int b,int c,int d,int e,int f){return (s[c][d][e][f]-s[a-1][d][e][f]-s[c][b-1][e][f]+s[a-1][b-1][e][f])%mod+mod;}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF306D.in","r",stdin);//freopen("CF306D.out","w",stdout);
#endif
    scanf("%d%d",&m,&n);
    //rep(i,1,n)rep(j,i,n)f[i][j][0][0]=1;
    rep(_,1,m){
        rep(i,1,n)rep(j,i,n){
            f[i][j][0][0]=sum(i,i,j,j,0,0)%mod;
            f[i][j][0][1]=(sum(i,j+1,j,n,0,0)+sum(i,j,j,n,0,1))%mod;
            f[i][j][1][0]=(sum(1,i,i-1,j,0,0)+sum(1,i,i,j,1,0))%mod;
            f[i][j][1][1]=(sum(1,j+1,i-1,n,0,0)+sum(1,j,i-1,n,0,1)+sum(1,j+1,i,n,1,0)+sum(1,j,i,n,1,1))%mod;
            if(_==1)f[i][j][0][0]=1;
            //printf("%d %d %lld %lld %lld %lld\n",i,j,f[i][j][0][0],f[i][j][0][1],f[i][j][1][0],f[i][j][1][1]);
        }
        CPY(s,f);rep(i,1,n)rep(j,1,n)rep(k,0,3)
            add(s[i][j][k&1][k>>1],s[i-1][j][k&1][k>>1]+s[i][j-1][k&1][k>>1]-s[i-1][j-1][k&1][k>>1]);
        add(ans,(s[n][n][0][0]+s[n][n][0][1]+s[n][n][1][0]+s[n][n][1][1])*(m-_+1));
    }printf("%I64d\n",ans);
    return 0;
}