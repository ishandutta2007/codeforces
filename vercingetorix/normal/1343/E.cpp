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
#include <queue>
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
int n,m,a,b,c;
const int INF = 1e9;
vi dij(const vvi & g, int s) {
    vector<int> d (n, INF),  par (n);
    d[s] = 0;
    priority_queue < pair<int,int> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second,  cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j];
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                par[to] = v;
                q.push (make_pair (-d[to], to));
            }
        }
    }
    return d;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        scanf("%d %d %d %d %d" , &n, &m, &a, &b, &c);
        a--;b--;c--;
        vvi g(n);
        readv(p,m);
        srt(p);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u,&v);
            u--; v--;
            g[u].pb(v); g[v].pb(u);
        }
        vll pref;
        pref.pb(0);
        forn(i,0,m) pref.pb(pref.back() + p[i]);
        forn(i,0,2*n) pref.pb(pref.back() + p.back());
        ll ans = 1e18;
        auto da = dij(g, a);
        auto db = dij(g, b);
        auto dc = dij(g, c);
        forn(mid, 0, n) {
            ans = min(ans, pref[db[mid]] + pref[db[mid] + da[mid] + dc[mid]]);
        }
        printf("%lld\n", ans);
        
        
        
        
    }
    
    
}