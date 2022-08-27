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

int n;
vi isstrong;
void strong(){
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            if(component.size() > 1) {
                for(auto x : component) isstrong[x] = 1;
            }
            component.clear();
        }
    }
}
vi rlev;
void go() {
    vi q;
    q.pb(0);
    rlev[0] = 1;
    while(!q.empty()) {
        int v = q.back();
        q.pop_back();
        for(auto u : g[v]) {
            if(rlev[u] < 2) {
                rlev[u] = max(rlev[v], rlev[u] + 1);
                q.pb(u);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int tt;
    read(tt);
    while(tt--) {
        order.clear();
        int m;
        scanf("%d %d", &n, &m);
        g = vvi(n);
        gr = vvi(n);
        isstrong = vi(n, 0);
        rlev = vi(n, 0);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            gr[v].pb(u);
            if(u==v) isstrong[u] = 1;
        }
        strong();
        go();
        vi q;
        forn(i,0,n) if(isstrong[i] && rlev[i] > 0) {
            rlev[i] = -1;
            q.pb(i);
        }
        while(!q.empty()) {
            int v = q.back();
            q.pop_back();
            for(auto u : g[v]) {
                if(rlev[u] != -1) {
                    rlev[u] = -1;
                    q.pb(u);
                }
            }
        }
        forn(i,0,n) printf("%d ", rlev[i]);
        printf("\n");
        
    }
    
}