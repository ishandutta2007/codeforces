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
vvi e;
int n,m,k;
int cnt = 0;
vvi col(2);
vi vis,par;
vi l;

void cb(int u, int v) {
    vi pu, pv;
    pu.pb(u);
    pv.pb(v);
    while(l[u] > l[v]) {
        u = par[u];
        pu.pb(u);
    }
    while(l[u] < l[v]) {
        v = par[v];
        pv.pb(v);
    }
    while(u!=v) {
        u = par[u];
        v = par[v];
        pu.pb(u);
        pv.pb(v);
    }
    pv.pop_back();
    reverse(all(pv));
    for(auto x : pv) pu.pb(x);
    cout<<2<<endl;
    cout<<pu.size()<<endl;
    for(auto x : pu) cout<<x+1<<' ';
    exit(0);
}

void dfs(int u, int p, int curc, int lv) {
    l[u] = lv;
    vis[u] = 1;
    cnt += 1;
    col[curc].pb(u);
    par[u] = p;
    for (auto v : e[u]) {
        if(v == p) continue;
        if (vis[v]) {
            cb(u,v);
        }
        if(cnt < k) dfs(v,u,1-curc, lv+1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &m, &k);
    e.resize(n);
    vis = vi(n,0);
    l = vi(n,0);
    par = vi(n,-1);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(0,-1,0,0);
    if(col[1].size() > col[0].size()) swap(col[0], col[1]);
    cout<<1<<endl;
    forn(i,0,(k+1)/2) cout<<col[0][i]+1<<' ';
    
}