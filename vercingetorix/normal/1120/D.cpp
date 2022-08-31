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
#ifdef LOCAL
const int A = 50;
#else
const int A = 200500;
#endif
int n;
int c[A];
vi g[A];
int par[A];
vi ch[A];
ll p[A];
ll p1[A];

void dfsp(int v, int p) {
    par[v] = p;
    if(v != 0) ch[p].pb(v);
    for(auto u : g[v]) if(u!=p) dfsp(u, v);
}

void dfs(int v) {
    if(ch[v].empty()) {
        p[v] = c[v];
        return;
    }
    ll sum = 0;
    for(auto u : ch[v]) {
        dfs(u);
        sum += p[u];
    }
    p[v] = sum;
    p1[v] = sum;
    for(auto u : ch[v]) {
        p1[v] = min(p1[v], sum + p1[u] - p[u]);
    }
    p[v] = min(p[v], p1[v] + c[v]);
}
int can1[A];
int can[A];
vi ans;

void dfsa(int v) {
    ll sum = 0;
    for(auto u : ch[v]) {
        sum += p[u];
    }
    if(can1[v]) {
        vi un;
        for(auto u : ch[v]) {
            if(p1[v] == sum + p1[u] - p[u]) {
                can1[u] = 1;
                un.pb(u);
            }
        }
        if(!un.empty()) for(auto u : ch[v]) if(un.size() > 1 || u != un[0]) can[u] = 1;
    }
    int good = 0;
    if(can[v]) {
        if(p[v] == sum) for(auto u : ch[v]) can[u] = 1;
        vi un;
        for(auto u : ch[v]) {
            if(p[v] == sum + p1[u] - p[u] + c[v]) {
                good = 1;
                can1[u] = 1;
                un.pb(u);
            }
        }
        if(!un.empty()) for(auto u : ch[v]) if(un.size() > 1 || u != un[0]) can[u] = 1;
        if(ch[v].empty()) good = 1;
    }
    if(good) ans.pb(v);
    for(auto u : ch[v]) dfsa(u);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,n) scanf("%d", &c[i]);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfsp(0, 0);
    dfs(0);
//    cout<<p[0];
    can[0] = 1;
    dfsa(0);
    srt(ans);
    printf("%lld %d\n", p[0], ans.size());
    for(auto x : ans) printf("%d ", x+1);
    
    
}