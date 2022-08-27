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
vi par;
vi lev;
vvi ch;
int root;
void dfs(int v, int p, int l) {
    lev[v] = l;
    par[v] = p;
    if(p!=v) ch[p].pb(v);
    for(auto u : g[v]) if(u!=p) dfs(u,v,l+1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    g.resize(n);
    par.resize(n);
    lev.resize(n);
    ch.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    root = 0;
    while(g[root].size() > 1) root++;
    dfs(root, root, 0);
    root = 0;
    while(root<n && lev[root] != 2*k) root++;
    if(root == n) {
        printf("No\n");
        exit(0);
    }
    forn(i,0,k) root = par[root];
    ch.clear();
    ch.resize(n);
    dfs(root, root, 0);
    forn(i,0,n) {
        if(lev[i] > k) {
            printf("No\n");
            exit(0);
        }
        else if(lev[i]<k && ch[i].size() < 3) {
            printf("No\n");
            exit(0);
        }
    }
    printf("Yes\n");
    
    
}