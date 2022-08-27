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


vector<set<int>> g;
vi vis;
void dfs(int v, int p){
    vis[v] = 1;
    if(g[v].empty()) return;
    vi candel;
    for(auto u : g[v]) {
        if(u==p) continue;
        if(g[u].size() > 1) candel.pb(u);
    }
    if(candel.size() == g[v].size()) candel.pop_back();
    for(auto u : candel) {
        g[v].erase(u);
        g[u].erase(v);
    }
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
    int t;
    read(t);
    
    while(t--) {
        g.clear();
        int n,m;
        scanf("%d %d", &n, &m);
        vvi gf(n);
        g.resize(n);
        forn(i,0,m) {
            int u, v;
            scanf("%d %d", &u,&v);
            u--;
            v--;
            gf[u].pb(v);
            gf[v].pb(u);
        }
        
        vi bad;
        vi used(n,0);
        vi taken(n,0);
        forn(i,0,n) {
            if(used[i]) continue;
            if(gf[i].size() == n-1) {
                bad.pb(i);
            }
            else {
                for(auto x : gf[i]) taken[x] = 1;
                taken[i] = 1;
                int pt = 0;
                while(taken[pt]) pt++;
                g[i].insert(pt);
                g[pt].insert(i);
                used[i] = 1;
                used[pt] = 1;
                for(auto x : gf[i]) taken[x] = 0;
                taken[i] = 0;
            }
        }
        vis = vi(n,0);
        forn(i,0,n) if(vis[i] == 0) dfs(i,i);
        vis = vi(n,0);
        int cur = 0;
        vi p(n);
        vi q(n);
        forn(i,0,n) {
            if(vis[i]) continue;
            else if(g[i].size() == 0) {
                p[i] = cur;
                q[i] = cur++;
            }
            else {
                int root = i;
                if(g[root].size() == 1) root = *(g[root].begin());
                int k = g[root].size();
                p[root] = cur;
                q[root] = cur + k;
                vis[root] = 1;
                for(auto x : g[root]) {
                    vis[x] = 1;
                    q[x] = cur++;
                    p[x] = cur;
                }
                cur++;
            }
        }
        forn(i,0,n) printf("%d ", p[i] + 1); printf("\n");
        forn(i,0,n) printf("%d ", q[i] + 1); printf("\n");
        
    }
    
}