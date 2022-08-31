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
int n,r;
vvi g;
vi st;
vi par;
void dfst(int v, int p) {
    par[v] = p;
    st[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        dfst(u, v);
        st[v] += st[u];
    }
}

int root;
vi cost;
int mult = 1;
int bnext = 1;
void dfs(int v, int p) {
    cost[v] = bnext;
    bnext++;
    printf("%d %d %d\n", v+1, p+1, mult*(cost[v] - cost[p]));
    for(auto u : g[v]) {
        if(u!=p) dfs(u,v);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n==1) return 0;
    if(n==2) {
        cout<<"1 2 1\n";
        return 0;
    }
    par = vi(n);
    st = vi(n,0);
    dfst(0,0);
    root =0;
    forn(iaffa,0,n) {
        for(auto v : g[root]) if(v!=par[root] && st[v]*2 >= n) {
            root = v;
            break;
        }
    }
    dfst(root,root);
    cost.resize(n);
    vi l;
    vi r;
    int sl = 0;
    int sr = 0;
    vpi q;
    for(auto v : g[root]) q.pb(mp(st[v], v));
    sort(all(q));
    reverse(all(q));
    forn(i,0,q.size()) {
//    for(auto v : g[root]) {
        int v = q[i].second;
        if(sl <= sr) {
            l.pb(v);
            sl+=st[v];
        }
        else {
            r.pb(v);
            sr += st[v];
        }
    }
    cost[root] = 0;
    for(auto v : l) dfs(v, root);
    mult = sl+1;
    bnext = 1;
    for(auto v : r) dfs(v, root);
}