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

int vx[40][100000];
int uvx[40][100000];
vi a;
vvi g;
int n,k;
void dfsd(int v, int p) {
    forn(j,k,2*k) vx[j][v] ^= a[v];
    for(auto u : g[v]) {
        if(u==p) continue;
        dfsd(u, v);
        forn(j,0,2*k) vx[j][v] ^= vx[(j+1)%(2*k)][u];
    }
}

vi ans;

void dfsu(int v, int p) {
    if(v!=p) forn(j,0,2*k) uvx[j][v] = uvx[(j+1)%(2*k)][p]^vx[(j+1)%(2*k)][p]^vx[(j+2)%(2*k)][v];
    if(uvx[0][v]^vx[0][v]) ans[v] = 1;
    for(auto u : g[v]) if(u!=p) dfsu(u, v);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &k);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    dfsd(0, 0);
    ans = vi(n,0);
    dfsu(0, 0);
    forn(i,0,n) printf("%d ", ans[i]);
}