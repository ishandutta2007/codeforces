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
vvi g;
vi vis;

void dfs(int v, int ignore, int bit) {
    vis[v] |= bit;
    for(auto u : g[v]) {
        if(u==ignore) continue;
        if(vis[u]&bit) continue;
        dfs(u, ignore, bit);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    
    while(t--) {
        int n,m,a,b;
        scanf("%d %d %d %d", &n, &m, &a,&b);
        a--; b--;
        g.clear();
        g.resize(n);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        vis = vi(n,0);
        dfs(a,b,1);
        dfs(b,a,2);
        ll c1=0, c2=0;
        forn(i,0,n) {
            if(i== a || i == b) continue;
            if(vis[i] == 1) c1++;
            if(vis[i] == 2) c2++;
        }
        printf("%lld\n", c1*c2);
        
    }
    
    
}