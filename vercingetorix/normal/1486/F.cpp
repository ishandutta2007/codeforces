#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <queue>
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
int l,n;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
vvi g;

void dfs1 (int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs1 (to, v);
    }
    tout[v] = ++timer;
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

pi almost(int a, int b) {
    for (int i=l; i>=0; --i) {
        if (! upper (up[a][i], b))
            a = up[a][i];
        if (! upper (up[b][i], a))
            b = up[b][i];
    }
    return mp(a,b);
}

ll ans = 0;
vi st;
vi top;
vvpi dd;

int dfs(int v, int p) {
    int come = st[v];
    for(auto u : g[v]) {
        if(u==p) continue;
        come += dfs(u, v);
    }
    come -= 2*top[v];
    ans += ll(top[v])*ll(come);
    st[v] = come;
    return come;
}

void solve() {
    forn(v,0,n) {
        map<int, int> cnt1;
        map<pi, int> cnt2;
        forn(i,0,dd[v].size()) {
            auto x = dd[v][i];
            if(x==mp(v,v)) ans += i;
            else if(x.first == v) ans += i - cnt1[x.second]++;
            else if(x.second == v) ans += i - cnt1[x.first]++;
            else {
                ans += i - cnt1[x.first]++ - cnt1[x.second]++ + cnt2[x]++;
            }
        }
        for(auto x : cnt1) ans -= (ll)x.second * ll(st[x.first]-x.second);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs1 (0, 0);
    int m;
    read(m);
    st=vi(n,0);
    top = vi(n,0);
    dd.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        int c = lca(u, v);
        st[u] ++;
        st[v] ++;
        top[c]++;
        auto x = almost(u,v);
        if(x.first != c && x.second != c && x.second < x.first) swap(x.second, x.first);
        dd[c].pb(x);
    }
    dfs(0,0);
    solve();
    cout<<ans;
}