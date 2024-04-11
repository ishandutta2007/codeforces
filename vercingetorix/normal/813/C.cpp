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
vvi nb;
vi l;
vi par;
vi md;
void dfs(int v, int p) {
    par[v] = p;
    md[v] = 0;
    for(auto u : nb[v]) {
        if(u==p) continue;
        l[u] = l[v] + 1;
        dfs(u,v);
        md[v] = max(md[v], md[u] + 1);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,x;
    scanf("%d %d", &n, &x);
    x--;
    l = vi(n,0);
    nb.resize(n);
    par.resize(n);
    md.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].pb(v); nb[v].pb(u);
    }
    dfs(0,-1);
    int lx = l[x];
    int px=lx/2+1;
    while(l[x] > px) x = par[x];
    cout<<2*(px+md[x]);
    
}