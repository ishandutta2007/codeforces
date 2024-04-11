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

const int maxn = 200005;
const int mod = 1e9+7;
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
ll cnt[2],cnt2[2],art=0;
ll ans=0;
void add(int u,int fa,ll cur,int f) {
    cnt[f]++;
    if(f) cur+=a[u];
    else cur-=a[u];
    cnt2[f]+=cur;
    cur%=mod;
    cnt2[f]%=mod;
    for(int v:g[u]) {
        if(vis[v] || v==fa) continue;
        add(v,u,cur,f^1);
    }
}
void sum(int u,int fa,ll cur,int f) {
    if(f) cur+=a[u];
    else cur-=a[u];
    cur %= mod;
    if(f) (ans += cnt2[f] + cnt[f] * (art+cur) % mod) %= mod;
//    if(f) {
//        cout << cnt2[f] << " " << cnt[f] << " " << art << endl;
//        cout << u << " " << fa << " " << cur << " " << f << " " << ans << endl;
//    }
    for(int v:g[u]) {
        if(vis[v] || v==fa) continue;
        sum(v,u,cur,f^1);
    }
}
void calc(int u) {
    art = -a[u];
    cnt[0]++;
//    cnt2[0]+=art;
    for(int v : g[u]) {
        if(vis[v]) continue;
//        cout << u << " -> " << v << endl;
        sum(v, u, 0, 1);
        add(v, u, 0, 1);
    }
//    cout << ans << endl;
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    art = a[u];
    cnt[1]++;
//    cnt2[1]+=art;
    for(int v : g[u]) {
        if(vis[v]) continue;
//        cout << u << " -> " << v << endl;
        sum(v, u, 0, 0);
        add(v, u, 0, 0);
    }
//    cout << ans << endl;
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
}
void solve(int u) {
//    cout << "solve: " << u << endl;
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
    ans = ans * 2 % mod;
    ii ans += a[i];
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}

/*
 *
7
1 0 1 0 1 1 1
1 2
2 3
3 4
4 5
5 6
5 7

7
0 0 0 1 0 0 0
1 2
2 3
3 4
4 5
5 6
5 7
 */