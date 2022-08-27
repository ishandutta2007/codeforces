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
vi a,b;
vvi g;
vi par;
vi v2;
vi vis;
ll curp;
int n;

int dfs(int v, int p, ll cpow) {
    if(cpow <= a[v]) return -1;
    par[v] = p;
    vis[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        if(vis[u] > 0) return v;
        int kra = dfs(u,v,cpow+b[v]);
        if(kra!=-1) return kra;
    }
    return -1;
    
}

bool go() {
    forn(i,0,n) vis[i] = 0;
    for(auto x : v2) vis[x] = 2;
    int meg = -1;
    for(auto x : v2) {
        for(auto u : g[x]) if(vis[u] == 0) {
            meg = dfs(u, x, curp);
            if(meg!=-1) break;
        }
        if(meg!=-1) break;
    }
    if(meg!=-1) {
        while(vis[meg]!=2) {
            curp+=b[meg];
            v2.pb(meg);
            meg = par[meg];
        }
        return true;
    }
    return false;
}

bool test(int m) {
    vis.resize(n);
    par.resize(n);
    curp = m;
    v2.clear();
    v2.pb(0);
    while(go()) {}
    if(v2.size() == n) return true;
    else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int mm;
        scanf("%d %d", &n, &mm);
        g = vvi(n);
        a.resize(n);
        b.resize(n);
        forn(i,1,n) scanf("%d", &a[i]);
        forn(i,1,n) scanf("%d", &b[i]);
        forn(i,0,mm) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        int r = 1000000005;
        int l = 0;
        while(r-l>1) {
            int m = (r+l)/2;
            if(test(m)) r = m;
            else l = m;
        }
        printf("%d\n", r);
        
    }
    
    
}