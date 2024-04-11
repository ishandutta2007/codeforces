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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

vi ban;

void dfsback(int v) {
    for(auto u : gr[v]) {
        if(!ban[u]) {
            ban[u] = 1;
            dfsback(u);
        }
    }
}

ll ans = 1;

vector<int> gt[200001]; // 
bool usedt[200001];
vector<int> topsort;
int n;
void dfs (int v) {
    usedt[v] = true;
    for (size_t i=0; i<gt[v].size(); ++i) {
        int to = gt[v][i];
        if (!usedt[to])
            dfs (to);
    }
    topsort.push_back (v);
}

void topological_sort() {
    for (int i=0; i<2*n; ++i)
        usedt[i] = false;
    topsort.clear();
    for (int i=0; i<2*n; ++i)
        if (!usedt[i])
            dfs (i);
    reverse (topsort.begin(), topsort.end());
}
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
    gcd(a, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}

//vi be[200000];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    g.resize(2*n);
    gr.resize(2*n);
    used.resize(2*n);
    ban = vi(2*n, 0);
    vi to(2*n,-1);
    vpi e;
    vi bad;
    forn(i,0,n) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(u==v) {
            bad.pb(u);
            continue;
        }
        to[u] = v;
        e.pb(mp(u,v));
        g[u].pb(v);
        gr[v].pb(u);
    }
    used.assign (2*n, false);
    for (int i=0; i<2*n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (2*n, false);
    for (int i=0; i<2*n; ++i) {
        int v = order[2*n-1-i];
        if (!used[v]) {
            dfs2 (v);
            if(component.size() > 1) {
                ans = (2*ans)%mod;
                for(auto x : component) ban[x] = 1;
                for(auto x : component) dfsback(x);
            }
            component.clear();
        }
    }
    for(auto x : bad) ban[x] = 1;
    for(auto x : bad) dfsback(x);
    for(auto x : e) if(!ban[x.second]) {
        gt[x.first].pb(x.second);
    }
    vi cnt(2*n,1);
    topological_sort();
    for(auto x : topsort) {
        if(!ban[x]) {
            if(to[x] == -1) {
                ans = (ans*(cnt[x]))%mod;
            }
            else {
                cnt[to[x]] += cnt[x];
            }
        }
    }
//    forn(i,0,2*n) {
//        if(gr[i].empty() && to[i] != -1) {
//            ll cnt = 0;
//            int cur = i;
//            while(cur != -1) {
//                cur = to[cur];
//                cnt++;
//                if(ban[cur]) {
//                    cnt = 0;
//                    break;
//                }
//            }
//            ans = (ans*(cnt+1))%mod;
//        }
//    }
    
    cout<<ans;
    
    
    
}