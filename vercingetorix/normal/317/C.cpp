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
const int A = 1000;
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
int a[A];
int b[A];
vi g[A];
int deg[A];
vi q;
vector<pair<pi, int>> ans;
int done[A];
int cur;
int cap;

void dfs(int v, int p, int push) {
    for(auto u : g[v]) {
        if(u == p || done[u]) continue;
        dfs(u, v, push);
        if(push) {
            int f = cap - a[u];
            int hv = (v == cur) ? a[v] - b[v] : a[v];
            int tk = min(f, hv);
            ans.pb(mp(mp(v, u), tk));
            a[u] += tk;
            a[v] -= tk;
        }
        else {
            int f = a[u];
            int nd = (v==cur) ? b[v] - a[v] : cap - a[v];
            int tk = min(f, nd);
            ans.pb(mp(mp(u,v), tk));
            a[u] -= tk;
            a[v] += tk;
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d %d", &n, &cap, &m);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) scanf("%d", &b[i]);
    forn(i,0,n) make_set(i);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(find_set(u) != find_set(v)) {
            g[u].pb(v);
            g[v].pb(u);
            deg[u]++;
            deg[v]++;
            union_sets(u, v);
        }
    }
    forn(i,0,n) if(deg[i] == 1) q.pb(i);
    while(!q.empty()) {
        int v = q.back();
        q.pop_back();
        if(deg[v] != 1) continue;
        cur = v;
        if(a[v] > b[v]) dfs(v, v, 1);
        else if(a[v] < b[v]) dfs(v,v,0);
        done[v] = 1;
        for(auto u : g[v]) if(done[u] == 0) {
            deg[u] --;
            if(deg[u] == 1) q.pb(u);
        }
    }
    forn(i,0,n) if(a[i]!=b[i]) {
        printf("NO\n");
        exit(0);
    }
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d %d %d\n", x.first.first+1, x.first.second+1,x.second);
    
    
    
}