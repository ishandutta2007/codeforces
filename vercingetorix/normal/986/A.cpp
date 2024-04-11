#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
int n;
vvi g;
const int INF = 1e9;
vi god(const vi & s) {
    vector<int> d (n, INF),  p (n);
    priority_queue < pair<int,int> > q;
    for(auto x : s) {
        d[x] = 0;
        q.push(mp(0, x));
    }
    while (!q.empty()) {
        int v = q.top().second,  cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j];
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                p[to] = v;
                q.push (make_pair (-d[to], to));
            }
        }
    }
    return d;
}
const int MAXN  = 100500;
vi best[MAXN];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,k,s;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    vvi goods(k);
    readv(a,n);
    forn(i,0,n) {
        a[i]--;
        goods[a[i]].pb(i);
    }
    g.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i,0,k) {
        vi dist = god(goods[i]);
        forn(j,0,n) best[j].pb(dist[j]);
    }
    forn(i,0,n) {
        srt(best[i]);
        int ans = 0;
        forn(j,0,s) ans += best[i][j];
        printf("%d ", ans);
    }
    
}