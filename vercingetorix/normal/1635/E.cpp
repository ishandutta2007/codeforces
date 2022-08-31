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

const int A = 200500;
vpi gs[A];
pi e[A];
int tp[A];
int vis[A];
int bad = 0;
vi comp[2];

void dfs1(int v) {
    comp[vis[v]].pb(v);
    for(auto u : gs[v]) {
        if(vis[u.first] == -1) {
            vis[u.first] = vis[v]^1;
            dfs1(u.first);
        }
        else {
            if((vis[u.first]^vis[v]) != 1) bad = 1;
        }
    }
}

vi g[A];
int edone[A];

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
    ts.clear();
    for(auto i : comp[0])
        if (!used[i])
            dfs (i);
    for(auto i : comp[1])
        if (!used[i])
            dfs (i);
    reverse (ts.begin(), ts.end());
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,m) {
        scanf("%d %d %d", &tp[i], &e[i].first, &e[i].second);
        e[i].first--;
        e[i].second--;
        gs[e[i].first].pb(mp(e[i].second,tp[i]));
        gs[e[i].second].pb(mp(e[i].first,tp[i]));
    }
    forn(i,0,n) vis[i] = -1;
    used = vb(n,0);
    vi ans(n,0);
    int pt = 0;
    vi ord(n);
    forn(i,0,n) if(vis[i] == -1) {
        vis[i] = 0;
        dfs1(i);
        if(bad) {
            printf("NO\n");
            exit(0);
        }
        for(auto v : comp[0]) {
            for(auto u2 : gs[v]) {
                int t = u2.second;
                int u = u2.first;
                if(t == 1) g[v].pb(u);
                else g[u].pb(v);
            }
        }
        topological_sort();
        forn(i,0,ts.size()) ord[ts[i]] = i;
        forn(i,0,ts.size()) {
            int v = ts[i];
            for(auto u : g[v]) if(ord[u] < ord[v]) bad = 1;
        }
        if(bad) {
            printf("NO\n");
            exit(0);
        }
        for(auto x : ts) ans[x] = pt++;
        comp[0].clear();
        comp[1].clear();
    }
    printf("YES\n");
    forn(i,0,n) {
        if(vis[i] == 0) printf("L");
        else printf("R");
        printf(" %d\n", ans[i]);
    }
    
}