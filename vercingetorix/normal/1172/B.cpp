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

const long long mod = 998244353 ;
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
vvi g;
ll d[200500];
ll nfac[200500];

void dfs(int v, int p) {
    int nc = 0;
    d[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u, v);
        d[v] = d[v] * d[u] % mod;
        nc++;
    }
    d[v] = d[v]*nfac[nc]%mod;
    if(nc > 0 && v != 0) d[v] = d[v] * (nc+1) % mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    nfac[0] = 1;
    forn(i,1,200500) nfac[i] = nfac[i-1]*i%mod;
    int n;
    read(n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0);
    printf("%lld\n", d[0]*n%mod);
    
    
}