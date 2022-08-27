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
const int A = 100400;
int k;
int st[A];
vpi g[A];
int deg[A];
int dpar[A];
//ll ans = 0;

//void dfs(int v, int p) {
//    for(auto u : g[v]) {
//        if(p == u.first) continue;
//        dpar[u.first] = u.second;
//        dfs(u.first, v);
//        st[v] += st[u.first];
//    }
//    if(st[v] >0 && st[v] < k && p!=-1) {
//        deg[v]++;
//        deg[p]++;
//        ans+=dpar[v];
//    }
//}

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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vector<pair<pi, int>> e;
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
        e.pb(mp(mp(u,v), w));
    }
    
    read(k);
    readv(port, k);
    forn(i,0,k) port[i]--;
    const ll INF = 1e18;
    vector<ll> d (n, INF);
    vi p(n);
    
    priority_queue < pair<ll,int> > q;
    for(auto x : port) {
        st[x] = 1;
        d[x] = 0;
        p[x] = x;
        q.push (make_pair (0, x));
    }
    while (!q.empty()) {
        int v = q.top().second;
        ll cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
            len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = p[v];
                q.push (make_pair (-d[to], to));
            }
        }
    }
    vector<pair<ll, pi>> krus;
    for(auto x : e) {
        int u = x.first.first;
        int v = x.first.second;
        int w = x.second;
        if(p[u] != p[v]) krus.pb(mp(d[u] + d[v] +w, mp(p[u], p[v])));
    }
    srt(krus);
    forn(i,0,n) make_set(i);
    ll ans  = d[0];
    for(auto x : krus) {
        int u = x.second.first;
        int v = x.second.second;
        ll w = x.first;
        if(find_set(v) != find_set(u)) {
            ans += w;
            union_sets(u, v);
        }
    }
//    dfs(0,-1);
//    ans += d[0];
//    deg[0]--;
//    forn(i,0,n) {
//        if(deg[i] > 2) ans += (deg[i]-2)*d[i];
//    }
    cout<<ans;
    
}