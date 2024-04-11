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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vvi g;
int n,a,b,da,db;
vi l1,l2;
vi dist;
const int INF = 1e9;
void dfs(int v, int par, int l) {
    dist[v] = l;
    vi lok;
    for(auto u : g[v]) {
        if(u==par) continue;
        dfs(u, v,l+1);
        lok.pb(l1[u] + 1);
    }
    sort(all(lok));
    reverse(all(lok));
    l1[v] = 0;
    if(lok.size() > 0) l1[v] = lok[0];
    l2[v] = l1[v];
    if(lok.size() > 1) l2[v] = lok[0]+lok[1];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
//    char c[300010];
    while(t--) {
        
        scanf("%d %d %d %d %d", &n, &a,&b,&da,&db);
        g = vvi(n);
        a--;b--;
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u,&v);
            u--;v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(db<=2*da) {
            printf("Alice\n");
            continue;
        }
        l1 = vi(n,-INF);
        l2 = vi(n,-INF);
        dist = vi(n,INF);
        dfs(a, -1, 0);
        if(dist[b] <= da) {
            printf("Alice\n");
            continue;
        }
        int diam = 0;
        forn(i,0,n) diam = max(diam, l2[i]);
        if(diam <= 2*da) printf("Alice\n");
        else printf("Bob\n");
    }
}