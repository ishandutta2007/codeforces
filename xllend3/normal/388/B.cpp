#include<bits/stdc++.h>
using namespace std;
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define SZ(x) ((int)(x).size())
#define pi 3.1415926535897
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define Y second
#define X first
typedef pair<int,int> pii;
typedef long long ll;
typedef double lf;
const int inf=0x20202020;
const int mod=1000000007;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N=111,M=33;
int l,m,n,t,C;
int a[N][N];
int main(){
#ifdef LOCAL
    freopen("path.in","r",stdin);//freopen("path.out","w",stdout);
#endif
    scanf("%d",&m);n=3*M+2;
    rep(i,2*M+3,3*M+1)a[i][i+1]=1;a[3*M+2][2]=1;
    for(int i=3;i<=2*M-1;i+=2)a[i][i+2]=a[i][i+3]=a[i+1][i+2]=a[i+1][i+3]=1;
    a[1][3]=a[1][4]=1;
    if(m&1)a[1][2*M+3]=1;m>>=1;
    rep(_,1,99){
        if(!m)break;if(m&1)a[_*2+1][2*M+3+_]=a[_*2+2][2*M+3+_]=1;m>>=1;
    }
    printf("%d\n",n);
    rep(i,1,n)rep(j,1,n)a[i][j]=a[j][i]=a[i][j]||a[j][i];
    rep(i,1,n){rep(j,1,n)printf("%c",a[i][j]?'Y':'N');puts("");}
    return 0;
}