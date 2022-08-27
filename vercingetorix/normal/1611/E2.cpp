#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
const int MAXN = 200500;
int mf[MAXN];
const int INF = 1e9;
vvi ch;
int par[MAXN];
int me[MAXN];
void dfspar(int v, int p) {
    for(auto u : g[v]) {
        if(u == p) continue;
        ch[v].pb(u);
        par[u] = v;
        dfspar(u,v);
        mf[v] = min(mf[v], mf[u] + 1);
    }
}

void dfs(int v, int p, int l) {
    me[v] = l;
    if(me[v] < mf[v]) for(auto u : g[v]) {
        if(u == p) continue;
        dfs(u,v, l+1);
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
        int n,k;
        scanf("%d %d", &n, &k);
        readv(x,k);
        forn(i,0,n) mf[i] = INF;
        forn(i,0,k) x[i]--;
        for(auto fr : x) mf[fr] = 0;
        g.clear();
        ch.clear();
        ch.resize(n);
        g.resize(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfspar(0, 0);
        forn(i,0,n) me[i] = INF;
        dfs(0,0,0);
        int can = 0;
        forn(i,1,n) {
            if(g[i].size() == 1 && me[i] < mf[i]) {
                can = 1;
                break;
            }
        }
        if(can == 1) printf("-1\n");
        else {
            int ans = 0;
            forn(i,0,n) if(me[i]<mf[i]) for(auto v : g[i]) if(me[v] >= mf[v]) ans++;
            printf("%d\n", ans);
        }
    }
    
    
}