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

vvpi g;
vi w;
ll ans = 0;
ll d[300500];

void dfs(int v, int p) {
    vll best(2,0);
    for(auto u : g[v]) {
        if(u.first == p) continue;
        dfs(u.first, v);
        best.pb(d[u.first] - u.second);
    }
    srtrev(best);
    d[v] = best[0] + w[v];
    ans = max(ans, w[v] + best[0] + best[1]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    g.resize(n);
    w.resize(n);
    forn(i,0,n) scanf("%d", &w[i]);
    forn(i,0,n-1) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        g[u].pb(mp(v,c));
        g[v].pb(mp(u,c));
    }
    dfs(0,0);
    cout<<ans;
    
    
}