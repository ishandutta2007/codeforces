#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int A = 100500;
vpi g[A];
int tl[A];
int tr[A];
ll dist[A];

int l;
vector<int> tin, tout;
int timer;
int timer2;
vector < vector<int> > up;

void dfs1 (int v, int p = 0) {
    tl[v] = timer2++;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (to != p) {
            dist[to] = (dist[v] + g[v][i].second)%mod;
            dfs1 (to, v);
            
        }
    }
    tout[v] = ++timer;
    tr[v] = timer2-1;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int st[A];
ll sumldown[A];
ll suml2down[A];
ll sumlup[A];
ll suml2up[A];
ll suml[A];
ll suml2[A];
int n;

void dfs(int v, int p) {
    st[v] = 1;
    for(auto u : g[v]) {
        if(u.first == p) continue;
        dfs(u.first, v);
        st[v] += st[u.first];
        sumldown[v] = (sumldown[v] + ll(u.second) * st[u.first] + sumldown[u.first])%mod;
        suml2down[v] = (suml2down[v] + suml2down[u.first] + ll(u.second)*u.second%mod * st[u.first] + 2*sumldown[u.first]*u.second)%mod;
    }
}

void dfsd(int v, int p) {
    
    suml[v] = (sumlup[v] + sumldown[v])%mod;
    suml2[v] = (suml2up[v] + suml2down[v])%mod;
    ll fl = suml[v];
    ll fl2 = suml2[v];
//    for(auto u : g[v]) {
//        if(u.first == p) continue;
//        fl = fl + sumldown[u.first];
//        fl2 = fl2 + suml2down[u.first];
//    }
    for(auto u : g[v]) {
        if(u.first == p) continue;
        int stu = n - st[u.first];
        ll cl = fl;
        cl -= sumldown[u.first] + ll(u.second)*st[u.first];
        cl = (cl%mod + mod)%mod;
        ll cl2 = fl2;
        cl2 -= suml2down[u.first] + ll(u.second)*u.second%mod*st[u.first] + 2*sumldown[u.first]*u.second;
        cl2 = (cl2%mod + mod)%mod;
//        ll cl = (fl - sumldown[u.first])%mod;
//        ll cl2 = (fl2 - suml2down[u.first])%mod;
        sumlup[u.first] = (cl+ll(u.second)*stu)%mod;
        suml2up[u.first] = (cl2 + ll(u.second)*u.second%mod * stu + 2*cl*u.second)%mod;
        dfsd(u.first, v);
    }
}

ll gdist(int u, int v) {
    int c = lca(u, v);
    return (dist[u] + dist[v] + 2*mod-2*dist[c])%mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,n-1) {
        int u,v,w;
        scanf("%d %d %d", &u, &v,&w);
        u--; v--;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
    }
    
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs1 (0, 0);
    dfs(0,0);
    dfsd(0,0);
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(tl[u] >= tl[v] && tl[u] <= tr[v]) {
            ll stu = n - st[v];
            ll len = gdist(u, v);
            ll ans = suml2[u] - 2*(suml2up[v] + len*len%mod*stu+2*len*sumlup[v]);
            ans = (ans%mod + mod)%mod;
            printf("%lld\n", ans);
        }
        else {
            ll stu = st[v];
            ll len = gdist(u, v);
            ll ans = 2*(suml2down[v] + len*len%mod*stu+2*len*sumldown[v]) - suml2[u];
            ans = (ans%mod + mod)%mod;
//            ll ans = -1;
            printf("%lld\n", ans);
        }
    }
    
    
}