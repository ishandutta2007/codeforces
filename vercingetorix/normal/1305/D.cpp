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

int ask(int a, int b) {
    printf("? %d %d\n", a+1, b+1);
    fflush(stdout);
    int c;
    scanf("%d",&c);
    return c-1;
}

void fin(int x) {
    printf("! %d\n", x+1);
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d", &n);
    vvi g(n);
    vi deg(n,0);
    m = n;
    vi vis(n,0);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        deg[u]++;
        deg[v]++;
        g[u].pb(v);
        g[v].pb(u);
    }
    while(m > 1) {
        vi lf;
        forn(i,0,n) if(!vis[i] && deg[i] == 1) lf.pb(i);
        int u = lf[0];
        int v = lf[1];
        int c = ask(u, v);
        if(c==u || c==v) fin(c);
        else {
            for(auto x : g[u]) if(vis[x] == 0) {
                deg[x]--;
            }
            for(auto x : g[v]) if(vis[x] == 0) {
                deg[x]--;
            }
            vis[u] = 1;
            vis[v] = 1;
            m-=2;
        }
    }
    int v = 0;
    while(vis[v]) v++;
    fin(v);
}