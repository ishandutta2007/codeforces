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
vs f;

vi low;
int n,m;

void setlow(int i, int v) {
    if(low[i] >= v) return;
}
vvi g,gr;

void ed(int i1,int j1, int i2, int j2) {
    g[i1*m+j1].pb(i2*m+j2);
}

vector<char> used;
vector<int> order, component;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

vi vis;

void dfs3(int v) {
    vis[v] = 1;
    for(auto u : g[v]) if(!vis[u]) dfs3(u);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &m);
    g.resize(n*m);
    gr.resize(n*m);
    char c[500500];
    forn(i,0,n) {
        scanf("%s", c);
        f.pb(string(c));
    }
    readv(a,m);
    forn(j,0,m) {
        int llast = -1;
        int rlast = -1;
        int dlast = -1;
        for(int i = n-1; i>=0; i--) {
            if(j>0 && f[i][j-1] == '#') llast = i;
            if(j<m-1 && f[i][j+1] == '#') rlast = i;
            if(f[i][j] == '#') {
                if(dlast!=-1) {
                    ed(i,j,dlast,j);
                    if(dlast == i + 1) ed(i+1,j,i,j);
                }
                if(llast!=-1) ed(i,j,llast,j-1);
                if(rlast!=-1) ed(i,j,rlast,j+1);
                dlast = i;
            }
        }
    }
    forn(i,0,n*m) {
        for(auto v : g[i]) gr[v].pb(i);
    }
    used.assign (n*m, false);
    for (int i=0; i<n*m; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n*m, false);
    vis.assign (n*m, false);
    forn(i,0,n) forn(j,0,m) if(f[i][j] == '.') used[i*m+j]=true;
    int ans = 0;
    for (int i=0; i<n*m; ++i) {
        int v = order[n*m-1-i];
        if (!used[v]) {
            dfs2 (v);
//            for(auto x : component) printf("(%d %d) ", x/m,x%m);
            if(!vis[component[0]]) {
                dfs3(component[0]);
                ans++;
            }
            printf("\n");
            component.clear();
        }
    }
    cout<<ans;
//    vi h;
//    forn(j,0,m) {
//        if(a[j] == 0) h.pb(-1);
//        forn(i,0,n) {
//            if(f[i][j] == '#') {
//                h.pb(i);
//                break;
//            }
//        }
//    }
//    vi fl(m, 0);
//    vi tr(m, 0);
//    forn(j,0,m-1) {
//        if(h[j] == -1 || h[j+1] == -1) continue;
//        if(h[j] >= h[j+1]) {
//            fl[j] = 1;
//        }
//        else {
//            fl[j] = 1;
//            for(int i = h[j]+1; i<= h[j+1]; i ++) if(f[i][j] == '.') fl[j] = 0;
//        }
//        if(h[j+1] >= h[j]) {
//            tr[j] = 1;
//        }
//        else {
//            tr[j] = 1;
//            for(int i = h[j+1]+1; i<= h[j]; i ++) if(f[i][j+1] == '.') tr[j] = 0;
//        }
//    }
//    low = vi(m,0);
//    int r = 0;
//    int ans = 0;
//    while(r<m) {
//        while(r<m&&a[r] == 0) r++;
//        if(r==m) break;
//        int low = h[r];
//        while(low +1< n && f[low+1][r] == '#') low++;
////        while(r<m&&fl[r]) r++;
////        while(r<m&&tr[r]) r++;
////        ans++;
////        r++;
//
//    }
//    cout<<ans;
    
    
    
}