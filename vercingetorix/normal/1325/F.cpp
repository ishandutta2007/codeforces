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

const int A = 200500;
int lev[A];
vi g[A];
int par[A];
int l=1;

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(u == p) continue;
        if(lev[u] == -1) {
            lev[u] = lev[v] + 1;
            par[u] = v;
            dfs(u, v);
        }
        else if(lev[u] < lev[v]) {
            if(lev[v] - lev[u] >= l-1) {
                vi c;
                c.pb(u);
                int cur = v;
                while(cur != u) {
                    c.pb(cur);
                    cur = par[cur];
                }
                printf("2\n");
                printf("%d\n", (int) c.size());
                for(auto x : c) printf("%d ", x+1);
                exit(0);
            }
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
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    while(l*l < n) l++;
    forn(i,0,n) lev[i] = -1;
    lev[0] = 0;
    dfs(0,0);
    vvi res(l-1);
    forn(i,0,n) res[lev[i]%(l-1)].pb(i);
    int pt = 0;
    while(res[pt].size() < l) pt++;
    printf("1\n");
    forn(i,0,l) printf("%d ", res[pt][i]+1);
    
    
}