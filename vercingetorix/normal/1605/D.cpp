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
vi ind[2];
vi place[20];

void dfs(int v, int p, int curc) {
    ind[curc].pb(v);
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u,v,1-curc);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        g.clear();
        g.resize(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0,0,0);
        int d2 = 1;
        int deg = 0;
        forn(i,1,n+1) {
            if(i>=2*d2) {
                d2*=2;
                deg++;
            }
            place[deg].pb(i);
        }
        vi ans(n,0);
        for(int l = 19; l>=0; l--) {
            if(place[l].empty()) continue;
            int tk = 0;
            if(ind[tk].size() < place[l].size()) tk = 1;
            while(!place[l].empty()) {
                ans[ind[tk].back()] = place[l].back();
                place[l].pop_back();
                ind[tk].pop_back();
            }
        }
        forn(i,0,n) printf("%d ", ans[i]);
        printf("\n");
    }
    
    
}