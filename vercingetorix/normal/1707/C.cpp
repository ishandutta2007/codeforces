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

const int A = 200500;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}
vi g[A];

int l;
vector<int> tin, tout;
int tl[A];
int tr[A];
int lev[A];
int timer2;
int timer;
vector < vector<int> > up;

void dfs1 (int v, int p = 0) {
    if(v!=p) lev[v] = lev[p]+1;
    tl[v] = timer2++;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs1 (to, v);
    }
    tout[v] = ++timer;
    tr[v] = timer2-1;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int pred(int a, int c) {
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], c))
            a = up[a][i];
    return a;
}

int ban[A];
string ans;
int dfs(int v, int p) {
    int cur = ban[v];
    for(auto u : g[v]) if(u!=p) {
        cur += dfs(u,v);
    }
    if(cur == 0) ans[v] = '1';
    return cur;
}

int who[A];

int shift[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,n) make_set(i);
    vpi e;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        if(find_set(u) != find_set(v)) {
            g[u].pb(v);
            g[v].pb(u);
            union_sets(u, v);
        }
        else e.pb(mp(u,v));
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs1 (0, 0);
    for(auto x : e) {
        int u = x.first;
        int v=  x.second;
        int c = lca(u,v);
        if(c!=u && c!=v) {
            shift[tl[u]]++;
            shift[tl[v]]++;
            shift[tr[u]+1]--;
            shift[tr[v]+1]--;
        }
        else {
            if(v==c) swap(u,v);
            int pv = pred(v, c);
            shift[0]++;
            shift[n]--;
            shift[tl[pv]]--;
            shift[tr[pv]+1]++;
            shift[tl[v]]++;
            shift[tr[v]+1]--;
        }
//        if(up[v][0] != v) ban[up[v][0]] ++;
//        if(up[u][0] != u) ban[up[u][0]] ++;
//        if(up[c][0] != c) ban[up[c][0]] -= 2;
    }
    forn(i,0,n) who[tl[i]] = i;
    int cur=  0;
    ans= string(n,'0');
    forn(i,0,n) {
        cur+=shift[i];
        if(cur == e.size()) ans[who[i]]='1';
    }
    cout<<ans;
    
}