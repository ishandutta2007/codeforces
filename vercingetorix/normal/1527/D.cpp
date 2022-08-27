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
vvi g;

int par[18][200500];
int lev[200500];
ll st[200500];

void dfs(int v, int p, int l) {
    lev[v] = l;
    par[0][v] = p;
    st[v] = 1;
    for(auto u : g[v]) {
        if(u!=p) {
            dfs(u,v,l+1);
            st[v] += st[u];
        }
    }
}

int a = 0;
int b= 0;
int c = 0;
int n;
ll mul() {
    if(b==c) {
        swap(a,b);
    }
    ll kb = st[b];
    if(a!=c) return kb*st[a];
    ll pr = b;
    for(int i = 17; i>=0; i--) if(lev[pr] > lev[a] + (1<<i)) pr = par[i][pr];
    return kb*(n-st[pr]);
}

int lca(int x, int y) {
    for(int i = 17; i >= 0; i--) {
        if(lev[x] >= lev[y] + (1<<i)) x = par[i][x];
        if(lev[y] >= lev[x] + (1<<i)) y = par[i][y];
    }
    if(x==y) return x;
    for(int i = 17; i >= 0; i--) {
        if(par[i][x] != par[i][y]) {
            x = par[i][x];
            y = par[i][y];
        }
    }
    return par[0][x];
}

void update(int i) {
    if(a==b) {
        b = i;
        c = lca(i,a);
        return;
    }
    int ia = lca(i,a);
    int ib = lca(i,b);
    if(ia == c) {
        if(ib == i) return;
        else if(ib==b) {
            b = i;
            return;
        }
        else if(a==c && ib == c) {
            a= i;
            c = ib;
        }
        else {
            c = -1;
            return;
        }
    }
    else if(ib == c) {
        if(ia == i) return;
        else if(ia==a) {
            a = i;
            return;
        }
        else if(b==c && ia == c) {
            b= i;
            c = ia;
        }
        else {
            c = -1;
            return;
        }
    }
    else {
        if(b==c) {
            b = i;
            c = ia;
        }
        else if(a==c) {
            a= i;
            c = ib;
        }
        else c = -1;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        
        scanf("%d", &n);
        g = vvi(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
//            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0,0,0);
        forn(p,1,18) forn(i,0,n) par[p][i] = par[p-1][par[p-1][i]];
        a = 0;
        b = 0;
        c = 0;
        vll ans(n+1,0);
        ans[0] = ll(n)*(n-1)/2;
        ans[1] = ll(n)*(n-1)/2;
        forn(i,0,n) if(lev[i] == 1) ans[1] -= st[i]*(st[i]-1)/2;
        forn(i,1,n) {
            update(i);
            if(c== -1) break;
            ans[i+1] = mul();
            
        }
        forn(i,0,n) ans[i] -= ans[i+1];
        forn(i,0,n+1) printf("%lld ", ans[i]); printf("\n");
    }
    
    
}