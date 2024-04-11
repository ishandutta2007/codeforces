#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
const int A = 200500;
int st[A];
int par[A];
int n;
int cent;

void dfs(int v, int p) {
    par[v] = p;
    st[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u,v);
        st[v] += st[u];
    }
    if(st[v]*2 == n) cent = v;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        
        scanf("%d", &n);
        g.clear();
        g.resize(n);
        vpi e;
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
            e.pb(mp(u,v));
        }
        cent= -1;
        dfs(0,0);
        if(cent == -1) {
            printf("%d %d\n", e[0].first+1, e[0].second+1);
            printf("%d %d\n", e[0].first+1, e[0].second+1);
        }
        else {
            int i = 0;
            while(g[cent][i] == par[cent]) i++;
            printf("%d %d\n", cent+1,g[cent][i]+1);
            printf("%d %d\n", par[cent]+1,g[cent][i]+1);
            
            
        }
        
    }
    
    
}