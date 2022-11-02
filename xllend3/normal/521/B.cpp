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
const int mod=1000000009;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N=111111,M=111111;
int l,m,n,t,C;
pii a[N];
int can[N];
set<int>S;
map<pii,int>V;
void upd(int p){
    if(!p)return;
    //printf("upd:%d\n",p);
    int x=a[p].X,y=a[p].Y;int res=1;
    rep(i,-1,1)if(V[mp(x+i,y+1)]&&(!!V[mp(x+i-1,y)]+!!V[mp(x+i,y)]+!!V[mp(x+i+1,y)]==1))res=0;
    if(can[p]==res)return;
    can[p]=res;if(res)S.insert(p);else S.erase(p);
}
int main(){
#ifdef LOCAL
    freopen("B.in","r",stdin);//freopen("B.out","w",stdout);
#endif
    scanf("%d",&n);rep(i,1,n)scanf("%d%d",&a[i].X,&a[i].Y),V[mp(a[i].X,a[i].Y)]=i;
    rep(i,1,n)upd(i);
    ll ans=0;
    rep(i,1,n){
        //printf("orz:");for(int i:S)printf("%d ",i);puts("");
        int p;
        if(i&1)p=*(S.rbegin());
        else p=*(S.begin());
        S.erase(p);ans=(ans*n+p-1)%mod;
        //printf("%d\n",p);
        int x=a[p].X,y=a[p].Y;
        V[mp(x,y)]=0;
        rep(i,-2,2)upd(V[mp(x+i,y)]);
        rep(i,-1,1)upd(V[mp(x+i,y-1)]);
    }
    printf("%d\n",int(ans));
    return 0;
}