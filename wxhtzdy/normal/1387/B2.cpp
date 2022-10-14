#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,rt,ans[N],sz[N];
ll tot;
VI e[N],q;

void dfs1(int v,int f) {
    int mx=0;
    sz[v]=1;
    for (int u:e[v]) {
        if (u==f) continue;
        dfs1(u,v);
        sz[v]+=sz[u];
        mx=max(mx,sz[u]);
    }
    if (sz[v]*2>n&&mx*2<=n)
        rt=v;
}

void dfs2(int v,int f) {
    q.pb(v);
    sz[v]=1;
    for (int u:e[v]) {
        if (u==f) continue;
        dfs2(u,v);
        sz[v]+=sz[u];
        tot+=sz[u]*2;
    }
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y); e[y].pb(x);
    }
    dfs1(1,0);
    dfs2(rt,0);
    printf("%lld\n",tot);
    rep(i,0,n) ans[q[i]-1]=q[(i+n/2)%n];
    rep(i,0,n) printf("%d ",ans[i]); puts("");
    return 0;
}