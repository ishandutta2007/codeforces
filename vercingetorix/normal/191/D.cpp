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
vi vis;
vi par,deg;
int need = 0;
const int A = 100500;
int odd[A];
int oddson[A];

int lev[A];

void dfs1(int v, int p) {
    vis[v] = 1;
    oddson[v] = deg[v]%2;
    for(auto u : g[v]) {
        if(vis[u]) continue;
        par[u] = v;
        lev[u] = lev[v] + 1;
        dfs1(u, v);
        if(oddson[u] > 0) oddson[v]++;
    }
}

void dfs(int v, int p) {
    vis[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        if(vis[u]) {
            if(lev[u] > lev[v]) continue;
            vi c(1,v);
            int cur = v;
            while(cur != u) {
                cur = par[cur];
                c.pb(cur);
            }
            int add = 1;
            int found = 0;
            for(auto x : c) {
                if(oddson[x] > 1) {
                    if(found) add = 0;
                }
                if(oddson[x]) found = 1;
            }
            need += add;
        }
        else {
            dfs(u, v);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    deg =vi (n,0);
    vis = deg;
    par = vis;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    vis = vi(n, 0);
    dfs1(0, 0);
    vis = vi(n, 0);
    dfs(0, 0);
    int cnt = 0;
    forn(i,0,n) cnt+=deg[i]%2;
    cout<<need+cnt/2<<' '<<m;
    
    
}