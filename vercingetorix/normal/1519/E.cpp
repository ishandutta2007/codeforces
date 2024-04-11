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
typedef vector<vpll> vvpll;

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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

set<pll> v1;
map<pll, int> ind;
int pt = 0;
vi nto;
vvpi g;
vi cnt;
vi vis;

void dfs(int v, int p, int ind) {
    vis[v] = 1;
    for(auto u : g[v]) {
        if(u.first != p && vis[u.first] == 0) {
            dfs(u.first, v, u.second);
        }
    }
    if(cnt[v]%2 != 0 && v != p) {
        cnt[v]--;
        cnt[p]++;
        nto[ind] = 1-nto[ind];
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    
    scanf("%d", &n);
    vll a(n),b(n),c(n),d(n);
    forn(i,0,n) scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
    vvpll to(n);
    forn(i,0,n) {
        forn(op,0,2) {
            ll x = a[i]*d[i];
            ll y = c[i]*b[i];
            if(op == 0) x += b[i]*d[i];
            else y += d[i]*b[i];
            ll dd = gcd(x,y);
            to[i].pb(mp(x/dd, y/dd));
            v1.insert(mp(x/dd, y/dd));
        }
    }
    for(auto x : v1) ind[x] = pt++;
    vvi toy(n);
    forn(i,0,n) for(auto y : to[i]) toy[i].pb(ind[y]);
    g.resize(pt);
    cnt.resize(pt);
    vis = vi(pt, 0);
    nto = vi(n, 0);
    forn(i,0,n) {
        int u = toy[i][0];
        int v = toy[i][1];
        g[u].pb(mp(v,i));
        g[v].pb(mp(u,i));
        cnt[u]++;
    }
    forn(i,0,pt) {
        if(!vis[i]) dfs(i, i, -1);
    }
    vvi ass(pt);
    forn(i,0,n) {
        ass[toy[i][nto[i]]].pb(i);
    }
    vpi turns;
    forn(j,0,pt) {
        for(int i = 1; i < ass[j].size(); i+=2) turns.pb(mp(ass[j][i], ass[j][i-1]));
    }
    printf("%d\n", turns.size());
    for(auto x : turns) {
        printf("%d %d\n", x.first+1, x.second+1);
    }
    
    
}