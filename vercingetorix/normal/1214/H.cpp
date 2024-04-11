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
int n,k;
vvi g;
pi dc[200500];
int lev[200500];
int par[200500];
int a=0,b=0,len=0;

void dfs(int v, int p, int l) {
    lev[v] = l;
    par[v] = p;
    dc[v] = mp(l, v);
    vpi bdc;
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u, v, l+1);
        dc[v] = max(dc[v], dc[u]);
        bdc.pb(dc[u]);
    }
    srtrev(bdc);
    if(bdc.size() >= 2) {
        if(bdc[0].first - l + bdc[1].first -l > len) {
            a = bdc[0].second;
            b = bdc[1].second;
            len = bdc[0].first - l + bdc[1].first -l;
        }
    }
    if(bdc.size() >= 1) {
        if(bdc[0].first - l > len) {
            a = bdc[0].second;
            b = v;
            len = bdc[0].first - l;
        }
    }
}
int col[200500];
int dfscol(int v, int p1, int p2, int c, int dir) {
    col[v] = c;
    int d = 0;
    for(auto u : g[v]) if(u!=p1 && u!=p2) {
        d = max(d, 1 + dfscol(u, v, v, (c+dir)%k, dir));
    }
    return d;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &k);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0,0);
    vi pta;
    vi ptb;
    while(lev[a] > lev[b]) {
        pta.pb(a);
        a = par[a];
    }
    while(lev[b] > lev[a]) {
        ptb.pb(b);
        b = par[b];
    }
    while(a!=b) {
        pta.pb(a);
        a = par[a];
        ptb.pb(b);
        b = par[b];
    }
    pta.pb(a);
    reverse(all(ptb));
    for(auto x : ptb) pta.pb(x);
//    cout<<pta.size();
    int plen = pta.size() - 1;
    forn(i,0,pta.size()) {
        int p1 = pta[i];
        int p2 = pta[i];
        if(i>0) p1 = pta[i-1];
        if(i+1<pta.size()) p2 = pta[i+1];
        int tol = i;
        int tor = plen - i;
        int dp;
        if(tol<=tor) dp = dfscol(pta[i], p1, p2, i%k, k-1);
        else dp = dfscol(pta[i], p1, p2, i%k, 1);
        if(dp >0 && k>2 && dp + min(tol, tor) >= k-1) {
            cout<<"No";
            exit(0);
        }
    }
    printf("Yes\n");
    forn(i,0,n) printf("%d ", col[i]+1);
    
    
}