#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
vvi g;
int n;
int root = 0;
vi st;
vi par;
vi lev;

int l;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfs1 (int v, int p = 0) {
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


void dfs(int v, int p) {
    par[v] = p;
    st[v] = 1;
    for(auto u : g[v]) {
        if(u!=p) {
            lev[u] = lev[v] + 1;
            dfs(u, v);
            st[v] += st[u];
        }
    }
}
void dfsroot(int v, int p) {
    for(auto u : g[v]) {
        if(u == p) continue;
        if(st[u]*2 >= n) {
            root = u;
            dfsroot(u, v);
        }
    }
}

vi path;
vi let;
ll ans = 0;
ll cand = 0;
ll r;

void dfsans(int v, int p) {
    vi taken;
    int wasr = r;
    if(v != root) {
        while(let.size() >= 2 && r*let[let.size() - 2] > st[v] * let.back()) {
            cand += r*let[let.size() - 2];
            taken.pb(let.back());
            let.pop_back();
        }
        cand += st[v] * let.back();
        r = st[v];
        ans = max(ans, cand);
    }
    for(auto u : g[v]) {
        if(u==p) continue;
        dfsans(u, v);
    }
    if(v!=root) {
        r = wasr;
        cand -= st[v] * let.back();
        while(!taken.empty()) {
            cand -= r * let.back();
            let.pb(taken.back());
            taken.pop_back();
        }
    }
}
vi prpr;
vvll d;
vi d2(1,1);
void go1(int v, int p) {
    int u = v;
    for (int i=l; i>=0; --i) {
        if(lev[u] > lev[p] + d2[i]) u = up[u][i];
    }
    d[v][p] = max(d[p][v], d[v][p]);
    d[p][v] = d[v][p];
    d[u][v] = max(d[u][v], d[v][u]);
    d[u][v] = max(d[u][v], d[v][p] + st[v]*(n-st[u]));
    d[v][u] = d[u][v];
    d[par[v]][p] = max(d[par[v]][p], d[p][par[v]]);
    d[par[v]][p] = max(d[par[v]][p], d[v][p] + st[v]*(n-st[u]));
    d[p][par[v]] = d[par[v]][p];
}

void go(int u, int v) {
    if(u==v) return;
    int c = lca(u,v);
    if(c==u) go1(v,c);
    else if(c==v) go1(u,c);
    else {
        d[up[u][0]][v] = max(d[up[u][0]][v], d[u][v] + st[u] * st[v]);
        d[u][up[v][0]] = max(d[u][up[v][0]], d[u][v] + st[u] * st[v]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,20) d2.pb(d2.back()*2);
    scanf("%d", &n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n==2) {
        cout<<1;
        return 0;
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    
    st.resize(n);
    par.resize(n);
    lev.resize(n);
    
    dfs(0,0);
    dfsroot(0, 0);
    lev[root] = 0;
    dfs(root, root);
    dfs1 (root, root);
//    forn(i,0,n) {
//        if(st[i] != 1) continue;
//        int cur = i;
//        path.clear();
//        let.clear();
//        while(cur != root) {
//            let.pb(st[cur]);
//            path.pb(cur);
//            cur = par[cur];
//        }
//        r = n - st[path.back()];
//        cand = st[path.back()]*(n-st[path.back()]);
//        dfsans(root, path.back());
//
//    }
    vpi q;
    forn(i,0,n) q.pb(mp(lev[i], i));
    sort(all(q));
    reverse(all(q));
    d = vvll (n, vll(n,0));
    prpr = vi (n);
    forn(i,0,n) if(i!=root) {
        int cur = i;
        while(par[cur] != root) cur = par[cur];
        prpr[i] = cur;
    }
    vector<pair<int, pi>> qq;
    forn(i,0,n) forn(j,0,n) {
        int c = lca(i, j);
        qq.pb(mp(lev[i]+lev[j]-2*lev[c], mp(i,j)));
    }
    srtrev(qq);
    for(auto x : qq) {
//        cout<<x.second.first<< ' '<<x.second.second<<endl;
        go(x.second.first, x.second.second);
    }
//    forn(i,0,n) forn(j,0,n) {
//        int u = q[i].second;
//        int v = q[j].second;
//        if(u!=root && v!=root && prpr[u]!=prpr[v]) {
//            d[par[u]][v] = max(d[par[u]][v], d[u][v] + st[u]*st[v]);
//            d[u][par[v]] = max(d[u][par[v]], d[u][v] + st[u]*st[v]);
//        }
//        if(u==v) continue;
//        if(u!=root && v == root) {
//            d[par[u]][v] = max(d[par[u]][v], d[u][v] + st[u] * (n-st[prpr[u]]));
//        }
//        else if(u==root && v!=root) {
//            d[u][par[v]] = max(d[u][par[v]], d[u][v] + st[v] * (n-st[prpr[v]]));
//        }
//    }
//    forn(i,0,n) if(i!=root) {
//        ans = max(ans, d[i][root] + st[i] * (n-st[i]));
//    }
    forn(i,0,n) ans = max(ans, d[i][i]);
    cout<<ans;
}