/*
Date: 2014/11/25 07:42:01 Tuesday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define ph push
#define pb push_back
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

const int N=2111111,M=111111;
typedef complex<double> cd;
#define sta static cd
#define con const cd *
#define co const int &
#define REP(i,a,n) for(int i=a;i<n;++i)
const lf PI=acos(-1);
cd pow_[N],a[N],b[N],ans[N];
void fft(con a,co n,co step,cd *ans,co ty){
    if(n==1){ans[0]=a[0];return;}
    int m=n>>1;fft(a,m,step<<1,ans,ty);fft(a+step,m,step<<1,ans+m,ty);
    REP(i,0,m){
        cd even=ans[i],odd=ans[i+m];
        if(ty==1)odd*=pow_[i*step];else odd/=pow_[i*step];
        ans[i]=even+odd;ans[i+m]=even-odd;
    }
}
void fft(con a,con b,int n,cd *ans){
    int m=1;for(;m<(n<<1);m<<=1);n=m;
    REP(i,0,n)pow_[i]=exp(cd(0.0,-2*PI*i/n));
    sta ta[N],tb[N];
    fft(a,n,1,ta,1);fft(b,n,1,tb,1);
    REP(i,0,n)ta[i]*=tb[i];
    fft(ta,n,1,ans,-1);
    REP(i,0,n)ans[i]/=n;
}
int l,m,n,t,C;
int v[N];
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF286E.in","r",stdin);//freopen("CF286E.out","w",stdout);
#endif
    scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&t),a[t]=b[t]=v[t]=1;
    fft(a,b,m,ans);
    //rep(i,1,m)printf("%d\n",int(a[i].real()+0.5));
    //rep(i,1,m)printf("%d\n",int(b[i].real()+0.5));
    //rep(i,1,m)printf("%lf\n",ans[i].real());
    rep(i,1,m)if(ans[i].real()>0.5&&!v[i]){puts("NO");return 0;}
    int cnt=0;rep(i,1,m)if(ans[i].real()<0.5&&v[i])++cnt;
    printf("YES\n%d\n",cnt);
    rep(i,1,m)if(ans[i].real()<0.5&&v[i])printf("%d ",i);puts("");
    return 0;
}