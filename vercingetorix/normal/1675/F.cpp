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
int n;
vvi g;
vi mark;
vi par;
int ans = 0;

void dfs(int v, int p) {
    for(auto u: g[v]) {
        if(u == p) continue;
        par[u] = v;
        dfs(u, v);
        if(mark[u]) mark[v] = 1;
    }
    if(mark[v]) ans += 2;
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
        int s,e;
        scanf("%d %d", &s, &e);
        --s; --e;
        readv(a,k);
        forn(i,0,k) a[i]--;
        g.clear();
        g.resize(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            --u; --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        mark = vi(n, 0);
        for(auto x : a) mark[x] = 1;
        mark[e] = 1;
        par = vi(n,-1);
        ans = 0;
        dfs(s, s);
        ans -= 2;
        while(e != s) {
            ans --;
            e = par[e];
        }
        printf("%d\n", ans);
    }
    
    
}