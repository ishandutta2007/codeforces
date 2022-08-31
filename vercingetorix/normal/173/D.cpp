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

const int A = 100500;
vvi g;
int col[A];

void dfs(int v) {
    for(auto u : g[v]) {
        if(col[u] == -1) {
            col[u] = col[v]^1;
            dfs(u);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i,0,n) srt(g[i]);
    forn(i,0,n) col[i] = -1;
    forn(i,0,n) if(col[i] == -1) {
        col[i] = 0;
        dfs(i);
    }
    vvi a(2);
    forn(i,0,n) a[col[i]].pb(i);
    vi ans(n,-1);
    if(a[0].size() % 3 == 0) {
        int num = 3;
        forn(it,0,2) for(auto x : a[it]) ans[x] = (num++)/3;
    }
    else {
        if(a[0].size() % 3 == 1) swap(a[0], a[1]);
        vvi pr(n);
        int done = 0;
        int num = 0;
        for(auto v : a[1]) {
            vi f;
            int pt = 0;
            for(auto x : a[0]) {
                while(pt<g[v].size() && g[v][pt] < x) pt++;
                if(pt < g[v].size() && g[v][pt] == x) pt++;
                else f.pb(x);
            }
            if(f.size() >= 2) {
                ans[v] = 1;
                ans[f[0]] = 1;
                ans[f[1]] = 1;
                num = 6;
                done = 1;
                break;
            }
            else if(f.size() == 1) {
                pr[f[0]].pb(v);
            }
        }
        if(done == 0) {
            vi big;
            for(auto v : a[0]) if(pr[v].size() > 1) big.pb(v);
            if(big.size() < 2) {
                printf("NO\n");
                exit(0);
            }
            forn(i,0,2) {
                int v = big[i];
                ans[v] = i+1;
                forn(j,0,2) ans[pr[v][j]] = i+1;
            }
            num = 9;
        }
        forn(it,0,2) for(auto x : a[it]) if(ans[x] == -1) ans[x] = (num++)/3;
    }
    printf("YES\n");
    forn(i,0,n) printf("%d ", ans[i]);
    
    
    
    
}