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
const int N = 100500;
vvi g;
vpi del;
vpi bam;
int deg[N];
int done[N];

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u,v);
    }
    for(auto u : g[v]) {
        if(u==p || done[u]) continue;
        if(deg[v] <= 3) break;
        done[u] = 1;
        del.pb(mp(u,v));
        deg[v]--;
        deg[u]--;
    }
    if(deg[v] == 3) {
        del.pb(mp(v,p));
        done[v] = 1;
        deg[v]--;
        deg[p]--;
    }
}

int vis[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        forn(i,0,n) deg[i] = 0;
        forn(i,0,n) vis[i] = 0;
        forn(i,0,n) done[i] = 0;
        g.clear();
        bam.clear();
        del.clear();
        g.resize(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--;v--;
            g[u].pb(v);
            g[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        int root = 0;
        while(deg[root]!=1) root++;
        dfs(root, root);
        set<pi> rem;
        for(auto x : del) if(x.first < x.second) rem.insert(x);
        else rem.insert(mp(x.second, x.first));
        forn(v,0,n) {
            vi temp;
            for(auto u : g[v]) {
                
                pi e = mp(u,v);
                if(u > v) e = mp(v,u);
                if(rem.find(e) == rem.end()) temp.pb(u);
                
            }
            g[v] = std::move(temp);
        }
        forn(i,0,n) {
            if(vis[i] == 0) {
                if(g[i].empty()) {
                    vis[i] = 1;
                    bam.pb(mp(i,i));
                }
                else if(g[i].size() == 1) {
                    int v = g[i][0];
                    int p = i;
                    while(g[v].size() != 1) {
                        int u = g[v][0];
                        if(u==p) u = g[v][1];
                        p = v;
                        v = u;
                    }
                    bam.pb(mp(i,v));
                    vis[i] = 1;
                    vis[v] = 1;
                }
            }
        }
        printf("%d\n", del.size());
        forn(i,0,del.size()) {
            printf("%d %d %d %d\n", del[i].first+1, del[i].second+1,bam[i].second+1,bam[i+1].first+1);
        }
    }
    
    
}