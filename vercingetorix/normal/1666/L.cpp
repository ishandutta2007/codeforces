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
vi par;
vi megapar;

void dfs(int v, int mep) {
    megapar[v] = mep;
    for(auto u : g[v]) if(par[u] == -1) {
        par[u] = v;
        dfs(u, mep);
    }
}
int s;
void getpath(int u, int add = 0) {
    vi path(1,u);
    int cur = u;
    while(cur != s) {
        cur = par[cur];
        path.pb(cur);
    }
    reverse(all(path));
    printf("%d\n", path.size()+add);
    for(auto x : path) printf("%d ", x+1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d %d", &n, &m, &s);
    --s;
    g.resize(n);
    par = vi(n,-1);
    megapar = vi(n,-1);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
    }
    par[s] = s;
    for(auto u : g[s]) if(par[u] == -1) {
        par[u] = s;
        dfs(u,u);
    }
    else {
        printf("Possible\n");
        printf("2\n");
        printf("%d %d\n", s+1, u+1);
        getpath(u);
        printf("\n");
        exit(0);
    }
    forn(u,0,n) {
        if(u == s || par[u] == -1) continue;
        for(auto v : g[u]) {
            if(v == s ||  megapar[v] == megapar[u]) continue;
            printf("Possible\n");
            getpath(v);
            printf("\n");
            getpath(u,1);
            printf("%d\n", v+1);
            exit(0);
        }
    }
    printf("Impossible\n");
    
    
}