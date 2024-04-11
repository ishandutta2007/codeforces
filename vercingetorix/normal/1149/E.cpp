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

int n,m;
vvi g;
vb used;
vector<int> ts;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ts.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ts.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ts.begin(), ts.end());
}
int mex[100500];
int xr[100500];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    readv(h,n);
    g.resize(n);
    used.resize(n);
    vvi gr(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        gr[v].pb(u);
    }
    vi vt(n);
    topological_sort();
    for(int ind = n-1; ind>=0; ind--) {
        int i = ts[ind];
        for(auto v : g[i]) mex[vt[v]] = 1;
        while(mex[vt[i]]) vt[i]++;
        for(auto v : g[i]) mex[vt[v]] = 0;
    }
    forn(i,0,n) xr[vt[i]] ^= h[i];
    int p = -1;
    forn(i,0,n) if(xr[i] != 0) p = i;
    if(p == -1) cout<<"LOSE\n";
    else {
        printf("WIN\n");
        forn(i,0,n) {
            if(vt[i] == p && (h[i]^xr[p]) < h[i]) {
                h[i] ^= xr[p];
                for(auto u : g[i]) {
                    int q = vt[u];
                    h[u] ^= xr[q];
                    xr[q] = 0;
                }
                forn(i,0,n) printf("%d ", h[i]);
                printf("\n");
                exit(0);
            }
        }
    }
}