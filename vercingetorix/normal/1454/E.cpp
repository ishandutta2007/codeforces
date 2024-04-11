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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int n;
vvi g;
vi par;
vi l;
vi iscl;
vi cl;
pi res;

void dfs (int v, int p, int lev) {
    par[v] = p;
    l[v] = lev;
    for(auto u : g[v]) {
        if(u==p) continue;
        if(par[u] != -2) {
            res = mp(u,v);
            continue;
        }
        dfs(u,v,lev+1);
    }
}

ll dfs2(int v, int p) {
    ll ret = 1;
    for(auto u : g[v]) {
        if(iscl[u] || p == u) continue;
        ret += dfs2(u,v);
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(i,0,t) {
        
        read(n);
        g = vvi(n);
        par = vi(n,-2);
        l = vi(n,0);
        iscl = vi(n,0);
        cl = vi(n,-1);
        forn(i,0,n) {
            int u,v;
            read(u);
            read(v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0,-1,0);
        int x = res.first;
        int y = res.second;
        iscl[x] = 1;
        iscl[y] = 1;
        while(x!=y) {
            if(l[x] > l[y]) {
                x = par[x];
                iscl[x] = 1;
            }
            else {
                y= par[y];
                iscl[y] = 1;
            }
        }
        ll ans = ll(n) * ll(n-1);
        forn(i,0,n) {
            if(iscl[i]) {
                ll k = dfs2(i, i);
                ans -= k*(k-1)/2;
            }
        }
        printf("%lld\n", ans);
        
    }
    
}