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


ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

ll ip;

vi FWHT(vi P, bool inverse) {
    for (int len = 1; 2 * len <= P.size(); len <<= 1) {
        for (int i = 0; i < P.size(); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int u = P[i + j];
                int v = P[i + len + j];
                P[i + j] = u + v;
                if(P[i+j] >= mod) P[i+j]-=mod;
                P[i + len + j] = u - v+mod;
                if(P[i+j+len] >= mod) P[i+j+len]-=mod;
            }
        }
    }
    
    if (inverse) {
        for (int i = 0; i < P.size(); i++)
            P[i] = ll(P[i])*ip%mod;
    }
    
    return P;
}

vi mult(vi & a, vi & b) {
    vi af = FWHT(a, false);
    vi bf = FWHT(b, false);
    vi c;
    forn(i,0,af.size()) c.pb(ll(af[i])*bf[i]%mod);
    return FWHT(c, true);
}

int n, m;
vvpi g;

const int MAXN = 100500;
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
int cost[MAXN];
const int PS = 1<<17;
vi prod(PS,0);
vi prod1(PS,0);
set<pi> br;
int def = 0;
void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                br.insert(mp(v,to));
                br.insert(mp(to,v));
                def^=cost[g[v][i].second];
                //                IS_BRIDGE(v,to);
                
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
}
int vis[MAXN];
vi curp(PS,0);
vi curx;
int totx = 0;

bool dc(int v, int p) {
    int good = false;
    for(auto u : g[v]) {
        if(vis[u.first] || u.first == p) continue;
        if(br.find(mp(u.first, v)) != br.end()) continue;
        vis[u.first] = 1;
        totx ^= cost[u.second];
        curx.pb(cost[u.second]);
//        curp[cost[u.second]]++;
        good = true;
        dc(u.first, v);
    }
    return good;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ip = invmod(PS, mod);
    scanf("%d %d", &n, &m);
    g.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d %d", &u, &v, &cost[i]);
        u--; v--;
        g[u].pb(mp(v, i));
        g[v].pb(mp(u, i));
    }
    find_bridges();
    prod[def] = 1;
    prod1[def] = 1;
    forn(i,0,n) if(vis[i] == 0) {
        if(dc(i,i)) {
            for(auto x : curx) curp[x^totx] ++;
            prod = mult(prod, curp);
            prod1 = mult(prod1, curp);
            forn(i,0,PS) if(prod1[i] !=0) prod1[i] = 1;
            forn(i,0,PS) curp[i] = 0;
            totx = 0;
            curx.clear();
        }
    }
    int pt = 0;
    while(prod1[pt]==0) pt++;
    printf("%d %d\n", pt, prod[pt]);
    
    
}