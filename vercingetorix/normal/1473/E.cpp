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
const ll INF = 1e18;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    n*=4;
    vector < vector < pair<int,int> > > g (n);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);;
        u--; v--;
        u*=4;
        v*=4;
        forn(r,0,4) g[u+r].pb(mp(v+r,w));
        forn(r,0,4) g[v+r].pb(mp(u+r,w));
        g[u].pb(mp(v+3,w));
        g[v].pb(mp(u+3,w));
        forn(mt,0,2) g[u+mt].pb(mp(v+2+mt,0));
        forn(mt,0,2) g[v+mt].pb(mp(u+2+mt,0));
        for(int mt = 0; mt<=2; mt+=2) g[u+mt].pb(mp(v+1+mt,w*2));
        for(int mt = 0; mt<=2; mt+=2) g[v+mt].pb(mp(u+1+mt,w*2));
    }
    int s = 0; //
    vector<ll> d (n, INF);
    d[s] = 0;
    priority_queue < pair<ll,int> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second;
        ll cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
            len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push (make_pair (-d[to], to));
            }
        }
    }
    n/=4;
    forn(i,1,n) printf("%lld ", d[i*4+3]);
    
}