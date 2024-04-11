#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
vector<pair<int, pi>> e;
vi g[10000];
int pr[10000];

vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if(mt[to] == -1) {
            mt[to] = v;
            pr[v]++;
            return true;
        }
        else if(try_kuhn (mt[to])) {
            pr[mt[to]]--;
            mt[to] = v;
            pr[v] ++;
            return true;
        }
    }
    return false;
}

template <bool ToShuffle = false>
struct bipartite_matching {
    int n_left, n_right, flow = 0;
    std::vector<std::vector<int>> g;
    std::vector<int> match_from_left, match_from_right;
    
    bipartite_matching(int _n_left, int _n_right)
    : n_left(_n_left),
    n_right(_n_right),
    g(_n_left),
    match_from_left(_n_left, -1),
    match_from_right(_n_right, -1),
    dist(_n_left) {}
    
    void add(int u, int v) { g[u].push_back(v); }
    
    std::vector<int> dist;
    
    void bfs() {
        std::queue<int> q;
        for (int u = 0; u < n_left; ++u) {
            if (!~match_from_left[u])
                q.push(u), dist[u] = 0;
            else
                dist[u] = -1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
                if (~match_from_right[v] && !~dist[match_from_right[v]]) {
                    dist[match_from_right[v]] = dist[u] + 1;
                    q.push(match_from_right[v]);
                }
        }
    }
    
    bool dfs(int u) {
        for (auto v : g[u])
            if (!~match_from_right[v]) {
                match_from_left[u] = v, match_from_right[v] = u;
                return true;
            }
        for (auto v : g[u])
            if (dist[match_from_right[v]] == dist[u] + 1 &&
                dfs(match_from_right[v])) {
                match_from_left[u] = v, match_from_right[v] = u;
                return true;
            }
        return false;
    }
    
    int get_max_matching() {
        if constexpr (ToShuffle) {
            for (int i = 0; i < n_left; ++i)
                std::random_shuffle(std::begin(g[i]), std::end(g[i]), gen);
        }
        while (true) {
            bfs();
            int augment = 0;
            for (int u = 0; u < n_left; ++u)
                if (!~match_from_left[u]) augment += dfs(u);
            if (!augment) break;
            flow += augment;
        }
        return flow;
    }
    
    std::pair<std::vector<int>, std::vector<int>> minimum_vertex_cover() {
        std::vector<int> L, R;
        for (int u = 0; u < n_left; ++u) {
            if (!~dist[u])
                L.push_back(u);
            else if (~match_from_left[u])
                R.push_back(match_from_left[u]);
        }
        return {L, R};
    }
    
    std::vector<std::pair<int, int>> get_edges() {
        std::vector<std::pair<int, int>> ans;
        for (int u = 0; u < n_left; ++u)
            if (match_from_left[u] != -1)
                ans.emplace_back(u, match_from_left[u]);
        return ans;
    }
};

bool can(int md) {
    bipartite_matching<false> matching(n, n);
    forn(i,0,md+1) {
        g[e[i].second.first].pb(e[i].second.second);
        matching.add(e[i].second.first, e[i].second.second);
    }
    matching.get_max_matching();
    if(matching.get_edges().size() == n) return true;
    else return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    
    forn(i,0,m) {
        int u,v,d;
        scanf("%d %d %d", &u, &v, &d);
        u--; v--;
        e.pb(mp(d, mp(u,v)));
    }
    srt(e);
    int r = m;
    int l = 0;
    while(r-l>1) {
        int md = (r+l)/2;
        if(can(md)) r = md;
        else l = md;
    }
    if(r==m) r = -1;
    else r = e[r].first;
    cout<<r;
    
    
    
}