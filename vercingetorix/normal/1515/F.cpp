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
int n,m;
ll x;

const int A = 300500;
ll c[A];
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
    ll nc = c[a] + c[b] - x;
    c[a] = 0;
    c[b] = 0;
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
    c[find_set(a)] = nc;
}

vi vis;
vvpi g;
vi ans;
void dfs1(int v, int p) {
    vis[v] = 1;
    for(auto u : g[v]) {
        if(vis[u.first]) continue;
        dfs1(u.first,v);
        int u1 = find_set(u.first);
        int v1 = find_set(v);
        if(u1 != v1 && c[u1] + c[v1] >= x) {
            union_sets(u1, v1);
            ans.pb(u.second);
        }
    }
}

void dfs2(int v, int p) {
    vis[v] = 1;
    for(auto u : g[v]) {
        if(vis[u.first]) continue;
        int u1 = find_set(u.first);
        int v1 = find_set(v);
        if(u1 != v1 && c[u1] + c[v1] >= x) {
            union_sets(u1, v1);
            ans.pb(u.second);
        }
        dfs2(u.first,v);
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d %lld", &n, &m, &x);
    forn(i,0,n) make_set(i);
    forn(i,0,n) scanf("%lld", &c[i]);
    g.resize(n);
    forn(i,0,m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(mp(v, i+1));
        g[v].pb(mp(u, i+1));
    }
    
    vis = vi(n,0);
    dfs1(0,0);
    vis = vi(n,0);
    dfs2(0,0);
    if(ans.size() < n-1) printf("NO\n");
    else {
        printf("YES\n");
        for(auto xx : ans) printf("%d\n", xx);
    }
    
    
}