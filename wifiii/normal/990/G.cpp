#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 200005;
int sz[maxn], mx[maxn], vis[maxn], a[maxn];
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
ll cnt[maxn];

int G[505][505];
int Gcd(int a,int b) {return b == 0 ? a : Gcd(b, a % b);}
void init() {
    for(int i=0;i<=500;++i) for(int j=0;j<=500;++j) G[i][j]=Gcd(i,j);
}
inline int gcd(int a, int b) {
    if(a <= 500 && b <= 500) return G[a][b];
    return b == 0 ? a : gcd(b, a % b);
}

unordered_map<int,ll> mp;
void cal(int u,int fa,int w) {
    for(auto p : mp) cnt[gcd(p.first, w)] += p.second;
    for(int v : g[u]) {
        if(v == fa || vis[v]) continue;
        cal(v, u, gcd(w, a[v]));
    }
}

void add(int u,int fa,int w) {
    mp[w]++;
    for(int v : g[u]) {
        if(v == fa || vis[v]) continue;
        add(v, u, gcd(w, a[v]));
    }
}
void calc(int u) {
    mp[a[u]]++;
    for(int v : g[u]) {
        if(vis[v]) continue;
        cal(v, u, gcd(a[u], a[v]));
        add(v, u, gcd(a[u], a[v]));
    }
    mp.clear();
}
void solve(int u) {
    vis[u] = 1; calc(u);
    for(int v : g[u]) {
        if(vis[v]) continue;
        N = sz[v]; rt = 0;
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
    init();
    int n = read();
    for(int i=1;i<=n;++i) a[i] = read(), cnt[a[i]]++;
    for(int i=1;i<n;++i) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    N = n; mx[0] = 1e9; rt = 0;
    getrt(1, -1);
    solve(rt);
    for(int i=1;i<maxn;++i) {
        if(cnt[i]) cout << i << " " << cnt[i] << endl;
    }
}