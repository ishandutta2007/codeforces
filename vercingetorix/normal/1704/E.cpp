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

const long long mod = 998244353 ;
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
const int A = 1004;
vi g[A];
ll a[A];


int n,m;
vb used;
vector<int> ts;

void dfs2 (int v) {
    used[v] = true;
    forn(i,0,g[v].size()) {
        int to = g[v][i];
        if (!used[to])
            dfs2 (to);
    }
    ts.push_back (v);
}

void topological_sort() {
    used = vb(n,false);
    ts.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs2 (i);
    reverse (ts.begin(), ts.end());
}

vpll res[A];
vpll ret;

void go(int v) {
    if(a[v]  > 0) res[v].pb(mp(0,a[v]));
    srt(res[v]);
    ll cur = 0;
    int pt = 0;
    
    while(pt < res[v].size()) {
        cur = res[v][pt].first;
        ll cnt = res[v][pt].second;
        pt++;
        while(pt < res[v].size() && res[v][pt].first <= cur+cnt) {
            cnt += res[v][pt++].second;
        }
        ret.pb(mp(cur+1, cnt));
    }
    res[v].clear();
    for(auto u : g[v]) for(auto y : ret) res[u].pb(y);
    ret.clear();
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
        
        scanf("%d %d", &n,&m);
        forn(i,0,n) scanf("%lld",&a[i]);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u,&v);
            --u; --v;
            g[u].pb(v);
        }
        topological_sort();
        int done = 0;
        forn(it,0,n) {
            vi big;
            forn(i,0,n) if(a[i] > 0) big.pb(i);
            if(big.empty()) {
                printf("%d\n", it);
                done = 1;
                break;
            }
            for(auto v : big) {
                a[v]--;
                for(auto u : g[v]) a[u]++;
            }
        }
        
        if(done == 0) {
            forn(i,0,n) a[i] %= mod;
            for(auto v : ts) {
                for(auto u:g[v]) a[u] = (a[v] + a[u])%mod;
            }
            printf("%lld\n", (a[ts.back()] +n)%mod);
        }
//        g[ts.back()].pb(n);
//        for(auto v : ts) go(v);
//        if(res[n].empty()) printf("0\n");
//        else printf("%lld\n", (res[n].back().first+res[n].back().second-1)%mod);
        forn(i,0,n) g[i].clear();
//        forn(i,0,n+1) res[i].clear();
    }
    
    
}