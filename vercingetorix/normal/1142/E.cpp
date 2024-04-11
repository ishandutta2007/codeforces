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
vvi g,gr;
vb used;
vector<int> ts;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ts.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ts.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ts.begin(), ts.end());
}

vvi swarm;
int root;
int pink[100500];
int parnum[100500];

int ask(int u, int v) {
    printf("? %d %d\n", u+1, v+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
int ind[100500];
set<pi> q;

void unpink(int v) {
    pink[v] = 0;
    for(auto u : g[v]) if(pink[u]) {
        parnum[u]--;
        if(parnum[u] == 0) q.insert(mp(ind[u], u));
    }
}

void gopink(int v) {
    pink[v] = 1;
    for(auto u : g[root]) if(pink[u]) {
        parnum[u]++;
    }
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    
    scanf("%d %d", &n, &m);
    g.resize(n);
    used.resize(n);
    gr.resize(n);
    swarm.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        gr[v].pb(u);
    }
    topological_sort();
    forn(i,0,n) ind[ts[i]] = i;
    root = ts[0];
    pink[root] = 1;
    forn(i,1,n) {
        int v = ts[i];
        int can = 0;
        for(auto u : gr[v]) {
            if(pink[u]) {
                pink[v] = 1;
                parnum[v]++;
//                if(can == 0) swarm[u].pb(v);
                can = 1;
            }
        }
        if(can) continue;
        if(ask(root, v)) continue;
        unpink(root);
        root = v;
        pink[root] = 1;
        while(!q.empty()) {
            pi del = *q.begin();
            q.erase(del);
            if(ask(del.second, root)) {
                unpink(root);
                root = del.second;
            }
            else {
                unpink(del.second);
            }
        }
        
    }
    printf("! %d", root+1);
    
    
}