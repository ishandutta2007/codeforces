#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int n,q;
vvi nb;
vvi par;
vi lev;
vi d2(1,1);

void dfs(int v, int p, int l) {
    lev[v] = l;
    for(auto u : nb[v]) {
        if(u==p) continue;
        par[u][0] = v;
        dfs(u, v, l+1);
    }
}

int lca(int u, int v) {
    for(int i = 16; i >= 0; i--) {
        if(lev[u] - lev[v] >= d2[i]) u = par[u][i];
        if(lev[v] - lev[u] >= d2[i]) v = par[v][i];
    }
    if(u==v) return u;
    for(int i = 16; i >= 0; i--) {
        if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,20) d2.pb(d2.back()*2);
    scanf("%d %d", &n, &q);
    nb.resize(n);
    lev.resize(n);
    par = vvi(n, vi(18, -1));
    par[0][0] = 0;
    forn(i,0,n-1) {
        int u,v;
        u = i+1;
        scanf("%d", &v);
        v--;
        nb[u].pb(v);
        nb[v].pb(u);
    }
    dfs(0, -1, 0);
    forn(l,1,18) {
        forn(i,0,n) {
            par[i][l] = par[par[i][l-1]][l-1];
        }
    }
    forn(i,0,q) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--; c--;
        int ab = lca(a, b);
        int ac = lca(a, c);
        int bc = lca(c, b);
        int abc = lca(ab, c);
        int ml = max(lev[ab], max(lev[ac], lev[bc]));
        if(lev[ac] == ml) {
            swap(b,c);
            swap(ab,ac);
        }
        else if(lev[bc] == ml) {
            swap(a,c);
            swap(ab,bc);
        }
        int ans = lev[ab] - lev[abc] + lev[c] - lev[abc];
        ans = max(ans,lev[a] - lev[ab]);
        ans = max(ans,lev[b] - lev[ab]);
        printf("%d\n", ans+1);
    }
}