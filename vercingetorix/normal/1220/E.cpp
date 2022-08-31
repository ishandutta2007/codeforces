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
int parent[200500];
int rk[200500];
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
vi w;
ll sg = 0;
ll ans = 0;
vi good, par;
vvi ch;
void dfs(int v, int p) {
    par[v] = p;
    if(p!=v) ch[p].pb(v);
    for(auto u : g[v]) {
        if(u==p) continue;
        if(par[u] != -1) {
            good[u] = 1;
            good[v] = 1;
        }
        else dfs(u, v);
        if(good[u]) good[v] = 1;
    }
}

ll cur = 0;
int forbid = -1;
void dfst(int v) {
    cur+=w[v];
    ans = max(ans, sg+cur);
    for(auto u : ch[v]) {
        if(u == forbid) continue;
        dfst(u);
    }
    cur-=w[v];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    w.resize(n);
    forn(i,0,n) scanf("%d", &w[i]);
    int root = 0;
    vpi e;
    forn(i,0,n) make_set(i);
    forn(i,0,m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(find_set(u)==find_set(v)) root = u;
        union_sets(u, v);
        g[u].pb(v);
        g[v].pb(u);
    }
    int s;
    read(s);
    s--;
    
    good = vi(n,0);
    ch.resize(n);
    par = vi(n, -1);
    if(m==n-1) root = s;
    dfs(root, root);
    if(m == n-1) {
        dfst(s);
        cout<<ans;
        exit(0);
    }
    forn(i,0,n) if(good[i]) sg+=w[i];
    ans = sg;
    if(good[s]) {
        forn(v,0,n) if(good[v]) {
            for(auto u : ch[v]) {
                if(good[u] == 0) dfst(u);
            }
        }
        cout<<ans;
    }
    else {
        int pr = s;
        cur += w[pr];
        while(good[par[pr]] == 0) {
            pr = par[pr];
            cur += w[pr];
        }
        forn(v,0,n) if(good[v]) {
            for(auto u : ch[v]) {
                if(u != pr) if(good[u] == 0) dfst(u);
            }
        }
        cur-=w[s];
//        dfs2(s);
        dfst(s);
        cur+=w[s];
        forbid = s;
        int pt = par[s];
        while(1) {
            if(good[pt]) break;
            dfst(pt);
            forbid = pt;
            pt = par[pt];
        }
        cout<<ans;
    }
}