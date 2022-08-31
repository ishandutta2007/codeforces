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
const int A = 100400;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

int n;
vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

void scc() {
    order.clear();
//    used.assign (n, false);
    used = vector<char>(n,false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            // new component
            forn(i,1,component.size()) {
                union_sets(component[i], component[i-1]);
            }
            component.clear();
            return;
        }
    }
}

vvi gs;

int main()
{
//#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
//#endif
    int m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    gr.resize(n);
    forn(i,0,n) make_set(i);
    vector<pair<pi, int>> e;
    vpi ge;
    vvpi gb(n);
    forn(i,0,m) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        u--;
        v--;
        if(c == 0) {
            g[u].pb(v);
            gr[v].pb(u);
            ge.pb(mp(u, v));
        }
        else {
            e.pb(mp(mp(u,v), i+1));
            gb[u].pb(mp(v, i+1));
        }
//        if(c == )
    }
    scc();
    gs.resize(n);
    vi done(n,0);
    vi din(n,0);
    for(auto x : ge) {
        int u = x.first;
        int v = x.second;
        u = find_set(u);
        v = find_set(v);
        if(u != v) {
            gs[u].pb(v);
            din[v]++;
        }
    }
    forn(i,0,n) if(find_set(i) == i) {
        
    }
    vi q;
    q.pb(0);
    done[0] = 1;
    vi add;
    while(!q.empty()) {
        int v = q.back();
        q.pop_back();
        for(auto u : g[v]) {
            if(done[u] == 0) {
                done[u] = 1;
                q.pb(u);
            }
        }
        for(auto u2 : gb[v]) {
            int u = u2.first;
            u = find_set(u);
            if(din[u] == 0 && done[u] == 0) {
                add.pb(u2.second);
                done[u] = 1;
                q.pb(u);
            }
        }
    }
    int can = 1;
    forn(i,0,n) {
        if(done[i] == 0) can = 0;
    }
    if(can == 0) printf("-1\n");
    else {
        printf("%d\n", add.size());
        for(auto x : add) printf("%d ", x);
    }
    
    
}