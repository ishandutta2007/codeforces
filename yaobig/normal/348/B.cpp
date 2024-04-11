#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
vi e[maxn+5];
ll b[maxn+5],S;

void dfs(int now,int fa,ll mul)
{
    if(now!=1 && e[now].size()==1) 
    {
        if(a[now]==0) {printf("%lld\n",S); exit(0);}
        b[now]=mul; return;
    }
    mul=mul*(e[now].size()-(now!=1));
    if(mul>1e13+5) {printf("%lld\n",S); exit(0);}
    for(auto v: e[now]) if(v!=fa) dfs(v,now,mul);
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]),S+=a[i];
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0,1);
    ll L=1;
    rep(i,1,n) if(a[i]!=0)
    {
        ll g=__gcd(L,b[i]);
        L/=g;
        if(log10(L)+log10(b[i])>=15) {printf("%lld\n",S); exit(0);}
        L*=b[i];
    }
    ll ans=1ll<<60;
    rep(i,1,n) if(a[i]!=0)
    {
        ll x=L/b[i];
        chmin(ans,a[i]/x);
    }
    printf("%lld\n",S-ans*L);
    return 0;
}