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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
int n,m;
const int A = 200110;
set<int> nb[A];
vi ch[A];
int par[A];
int vis[A];
vi x,y,z;
int to[A];
vi comp;

void dfs(int v, int p) {
    vis[v] = 1;
    comp.pb(v);
    vi take;
    vi er;
    for(auto u : nb[v]) {
        if(u==p || vis[u]) continue;
        ch[v].pb(u);
        par[u] = v;
        nb[u].erase(v);
        dfs(u, v);
        er.pb(u);
    }
    for(auto u : er) nb[v].erase(u);
}

bool dfs2(int v, int p) {
    vi take;
    for(auto u : ch[v]) {
        if(dfs2(u, v)) take.pb(u);
    }
    if(to[v] != -1) {
        take.pb(to[v]);
        to[to[v]] = -1;
    }
    while(take.size() > 1) {
        x.pb(take.back());
        y.pb(v);
        take.pop_back();
        z.pb(take.back());
        take.pop_back();
    }
    if(take.empty()) return true;
    if(p!=-1) {
        x.pb(take[0]);
        y.pb(v);
        z.pb(p);
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    forn(i,0,n) to[i] = -1;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].insert(v); nb[v].insert(u);
    }
    forn(i,0,n) {
        if(!vis[i]) {
            comp.clear();
            dfs(i, -1);
            for(auto v : comp) {
                vi nbv;
                for(auto y : nb[v]) nbv.pb(y);
                while(nbv.size() > 1) {
                    x.pb(nbv.back());
                    nbv.pop_back();
                    y.pb(v);
                    z.pb(nbv.back());
                    nbv.pop_back();
                    nb[x.back()].erase(v);
                    nb[z.back()].erase(v);
                }
                nb[v].clear();
                if(nbv.size() > 0) nb[v].insert(nbv[0]);
            }
            for(auto v : comp) if(!nb[v].empty()) to[v] = *nb[v].begin();
            dfs2(i, -1);
        }
    }
    printf("%d\n", x.size());
    forn(i,0,x.size()) printf("%d %d %d\n", x[i]+1, y[i]+1, z[i]+1);
    
}