#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 100005;
int sz[maxn], mx[maxn], a[maxn], vis[maxn];
int N,rt;
vector<int> g[maxn];
void getrt(int u, int fa) {
    sz[u] = 1; mx[u] = 0;
    for(int v : g[u]) {
        if(vis[v] || v == fa) continue;
        getrt(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], N - sz[u]);
    if(mx[u] < mx[rt]) rt = u;
}
int cnt[20][2],art=0;
ll ans=0;
void add(int u,int fa,int cur) {
    cur^=a[u];
    for(int i=19;i>=0;--i) cnt[i][cur>>i&1]++;
    for(int v:g[u]) {
        if(vis[v] || v==fa) continue;
        add(v,u,cur);
    }
}
void sum(int u,int fa,int cur) {
    cur^=a[u];
    for(int i=19;i>=0;--i) ans += (1ll<<i)*cnt[i][(cur>>i&1)^(art>>i&1)^1];
    for(int v:g[u]) {
        if(vis[v] || v==fa) continue;
        sum(v,u,cur);
    }
}
void calc(int u) {
    art = a[u];
    for(int i=19;i>=0;--i) cnt[i][0]++;
    for(int v : g[u]) {
        if(vis[v]) continue;
        sum(v, u, 0);
        add(v, u, 0);
    }
    memset(cnt, 0, sizeof(cnt));
}
void solve(int u) {
    vis[u] = 1; calc(u);
    int last = N;
    for(int v : g[u]) {
        if(vis[v]) continue;
        N = sz[u] > sz[v] ? sz[v] : last - sz[u];
        rt = 0;
        getrt(v, u);
        solve(rt);
    }
}
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main() {
    int n = read();
    ii a[i] = read();
    for(int i=1;i<n;++i) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    N = n; mx[0] = 1e9; rt = 0;
    getrt(1, -1);
    solve(rt);
    ii ans += a[i];
    cout << ans << endl;
}