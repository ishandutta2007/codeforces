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
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vvi nb;
vi col;
vi ucol;
vvi s;
void dfs(int v, int p) {
    for(auto x : s[v]) if(col[x] != -1) ucol[col[x]] = 1;
    int pt = 1;
    for(auto x : s[v]) if(col[x] == -1) {
        while(ucol[pt] == 1) pt++;
        col[x] = pt;
        ucol[pt] = 1;
    }
    for(auto x : s[v]) ucol[col[x]] = 0;
    for(auto u : nb[v]) if(u != p) dfs(u, v);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n,&m);
    int ans = 1;
    s.resize(n);
    col = vi(m+1,-1);
    ucol = vi(m+1,0);
    
    forn(i,0,n) {
        int k;
        scanf("%d", &k);
        s[i].resize(k);
        forn(j,0,k) scanf("%d", &s[i][j]);
        ans = max(ans, k);
    }
    nb.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;v--;
        nb[u].pb(v);
        nb[v].pb(u);
    }
    dfs(0,-1);
    printf("%d\n", ans);
    forn(i,1,m+1) {
        if(col[i] == -1) col[i] = 1;
        printf("%d ", col[i]);
    }
    
    
}