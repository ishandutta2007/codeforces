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
const int A = 300500;
vi g[A];
int n;

int h = -1;
vpi q;

int l;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfs1 (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs1 (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int dep[A];

void dfs(int v, int p) {
    h++;
    dep[v] = h;
    q.pb(mp(h,v));
    for(auto u : g[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    h--;
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
        int n;
        scanf("%d", &n);
        
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        
        up.clear();
        tin.clear();
        tout.clear();
        tin.resize (n),  tout.resize (n),  up.resize (n);
        l = 1;
        while ((1<<l) <= n)  ++l;
        for (int i=0; i<n; ++i)  up[i].resize (l+1);
        timer = 0;
        dfs1 (0, 0);
        
        
        
        q.clear();
        dfs(0,0);
        srtrev(q);
        int v2 = q[0].second;
        int v1 = q[0].second;
        vi ans(n+1,q[0].first);
        auto dist = [&] (int u, int v) {
            int c = lca(u, v);
            return dep[u] + dep[v] - 2*dep[c];
        };
        int pt = 0;
        int diam = 0;
        for(int res = q[0].first; res >= 1; res--) {
            while(q[pt].first > res) {
                int v = q[pt].second;
                int vv1 = dist(v1,v);
                int vv2 = dist(v2,v);
                if(vv1 >= vv2 && vv1 > diam) {
                    v2 = v;
                    diam = vv1;
                }
                else if(vv2 >= vv1 && vv2 > diam) {
                    v1 = v;
                    diam = vv2;
                }
                pt++;
            }
//            int diam = dist(v1, v2);
            if((diam+1)/2 < res) {
                ans[res-(diam+1)/2] = res;
            }
        }
        for(int i = n-1; i>=1; i--) ans[i] = min(ans[i], ans[i+1]);
        forn(i,1,n+1) printf("%d ", ans[i]);
        printf("\n");
        
        forn(i,0,n) g[i].clear();
    }
    
    
}