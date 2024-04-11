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
int n;
vvi g;
vi a;
vvi ch;
vi lev;
vi par;
void dfs(int v, int p) {
    par[v] = p;
    if(v!=p) ch[p].pb(v);
    for(auto u : g[v]) {
        if(u== p )continue;
        lev[u] = lev[v] + 1;
        dfs(u, v);
    }
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
        read(n);
        g = vvi(n);
        ch = vvi(n);
        a = vi(n,0);
        lev = vi(n,0);
        par = vi(n,0);
        forn(i,0,n-1) {
            int v;
            scanf("%d", &v); v--;
            g[i+1].pb(v);
            g[v].pb(i+1);
        }
        forn(i,1,n) scanf("%d", &a[i]);
        lev[0] = 0;
        dfs(0, 0);
        vvi lvl(n+1);
        forn(i,0,n) lvl[lev[i]].pb(i);
        vll d(n,0);
        ll ans = 0;
        forn(l,1,n+1) {
            vi aprev;
            for(auto x : lvl[l-1]) aprev.pb(a[x]);
            srt(aprev);
            for(auto p : lvl[l-1]) ans = max(ans, d[p] + max(abs(a[p] - aprev[0]), abs(a[p] - aprev.back())));
            for(auto x : lvl[l]) d[x] = d[par[x]] + max(abs(a[par[x]] - aprev[0]), abs(a[par[x]] - aprev.back()));
            vector<pair<pll, int>> e;
            for(auto x : lvl[l-1]) e.pb(mp(mp(a[x], d[x]), x));
            srt(e);
            int k = e.size();
            ll cmax = -1e18;
            vll lf(k);
            vll rt(k);
            forn(i,0,k) {
                cmax = max(cmax, e[i].first.second - e[i].first.first);
                lf[i] = cmax;
            }
            cmax = -1e18;
            for(int i = k-1; i>=0; i--) {
                cmax = max(cmax, e[i].first.second + e[i].first.first);
                rt[i] = cmax;
            }
            forn(i,0,k) {
                int p = e[i].second;
                for(auto v : ch[p]) d[v] = max(d[v], max(a[p] + lf[i], rt[i] - a[p]));
            }
        }
        cout<<ans<<endl;
    }
    
}