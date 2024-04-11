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
const ll INF = 2e9;
ll d[600][600];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,n) forn(j,0,n) d[i][j] = INF;
    forn(i,0,n) d[i][i] = 0;
    vvpi g(n);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        d[u][v] = min(d[u][v], ll(w));
        d[v][u] = d[u][v];
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    int q;
    scanf("%d", &q);
    vi f(q), t(q), l(q);
    forn(i,0,q) {
        scanf("%d %d %d", &f[i], &t[i], &l[i]);
        f[i]--;
        t[i]--;
    }
    vvi good(n, vi(n,0));
    int ans = 0;
    forn(es,0,n) {
        vll elim(n,-1);
        forn(i,0,q) {
            elim[t[i]] = max(elim[t[i]], l[i] - d[f[i]][es]);
        }
        for(auto x : g[es]) {
            if(good[es][x.first]) continue;
            int can = 0;
            forn(to,0,n) {
                if(d[x.first][to] + x.second <= elim[to]) {
                    can = 1;
                    break;
                }
            }
            if(can == 1) {
                good[es][x.first] = 1;
                good[x.first][es] = 1;
            }
//            ans += can;
        }
    }
    forn(i,0,n) forn(j,0,n) ans += good[i][j];
    cout<<ans/2;
    
    
}