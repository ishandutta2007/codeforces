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
#include <queue>
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
int n,m,a,b;
const int A = 80;
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

const int INF = 2e9;
int d[70][1<<17];
vvpi g;
int badbit[70];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d %d %d", &n, &m, &a,&b);
    forn(i,0,n) make_set(i);
    g.resize(n);
    forn(i,0,70) forn(j,0,1<<17) d[i][j] = INF;
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
        if(w==a) union_sets(u, v);
    }
    vi ss(70, 0);
    forn(i,0,n) ss[find_set(i)]++;
    vvpi ng(n);
    forn(v,0,n) {
        for(auto u : g[v]) if(u.second == a || find_set(u.first) != find_set(v)) ng[v].pb(u);
    }
    g = ng;
    int bn = 0;
    map<int, int> to;
    forn(i,0,n) if(ss[i] > 3) to[i] = bn++;
    forn(i,0,n) if(ss[find_set(i)] > 3) badbit[i] = 1<<to[find_set(i)];
    pi s = mp(0, badbit[0]);
    d[s.first][s.second] = 0;
    priority_queue < pair<int,pi> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second.first, mask = q.top().second.second,  cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v][mask])  continue;
        for (size_t j=0; j<g[v].size(); ++j) {
            int u = g[v][j].first;
            int len = g[v][j].second;
            int mto = mask;
            if(len == b) {
                if(badbit[u]&mask) continue;
                mto |= badbit[u];
            }
            if (d[v][mask] + len < d[u][mto]) {
                d[u][mto] = d[v][mask] + len;
                q.push (mp(-d[u][mto], mp(u,mto)));
            }
        }
    }
    forn(i,0,n) {
        int best = INF;
        forn(mask,0,1<<bn) {
            best = min(best, d[i][mask]);
        }
        printf("%d ", best);
    }
    
    
}