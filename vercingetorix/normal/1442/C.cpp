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

const long long mod = 998244353;
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
vvi g[2];
const ll INF = 1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n,&m);
    g[0].resize(n); g[1].resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[0][u].pb(v);
        g[1][v].pb(u);
    }
    vi d(n, INF);
    vi p(n);
    d[0] = 0;
    vi vis(n,0);
    vi last(1,0);
    vi av(1,0);
    ll apen = 1;
    ll totpen = 0;
    ll ans = 1e18;
    forn(inv,0,n+1) {
        vi nlast;
        int was = d[n-1];
        priority_queue < pair<int,int> > q;
        if(inv == 1) last.pb(0);
        for(auto s : last) q.push (make_pair (-d[s], s));
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[v])  continue;
            for (size_t j=0; j<g[inv%2][v].size(); ++j) {
                int to = g[inv%2][v][j];
                if (d[v] + 1 < d[to]) {
                    nlast.pb(to);
                    d[to] = d[v] + 1;
                    p[to] = v;
                    q.push (make_pair (-d[to], to));
                }
            }
        }
        
        if(inv < 21) {
            if(d[n-1] != INF) ans = min(ans, d[n-1] + totpen);
        }
        else {
            if(was == INF && d[n-1] != INF) ans = (d[n-1] +totpen)%mod;
        }
        totpen = (apen + totpen)%mod;
        apen *= 2;
        apen %= mod;
        last = nlast;
    }
    cout<<ans;
    
}