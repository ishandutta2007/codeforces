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
int n;
vvi g;
vb used;
vector<int> ts;
const int A = 200500;
int good[A];

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (good[to] && !used[to])
            dfs (to);
    }
    ts.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ts.clear();
    for (int i=0; i<n; ++i)
        if (good[i] && !used[i])
            dfs (i);
    reverse (ts.begin(), ts.end());
}
int ord[A];
int d[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    ll k;
    scanf("%d %d %lld", &n, &m, &k);
    readv(a,n);
    used.resize(n);
    g.resize(n);
    forn(i,0,m) {
        int v, u;
        scanf("%d %d", &v, &u);
        v--;
        u--;
        g[v].pb(u);
    }
    const int INF = 1e9 + 1000;
    int mn = INF;
    forn(i,0,n) mn = min(mn, a[i]);
    int l = mn-1;
    int r =INF;
    while(r-l>1) {
        int md = (ll(l)+r)/2;
        forn(i,0,n) good[i] = (a[i] <= md);
        topological_sort();
        forn(i,0,ts.size()) ord[ts[i]] = i;
        bool cyc = false;
        for(auto v : ts) {
            for(auto u : g[v]) if(good[u] && ord[u] < ord[v]) cyc = true;
        }
        if(cyc) r = md;
        else {
            int cur = 0;
            for(int i = ts.size()-1; i>=0; i--) {
                int v = ts[i];
                d[v] = 1;
                for(auto u : g[v]) if(good[u]) d[v] = max(d[v], d[u]+1);
                cur = max(cur, d[v] );
            }
            if(cur >= k) r = md;
            else l = md;
        }
    }
    if(r == INF) r = -1;
    cout<<r;
    
    
}