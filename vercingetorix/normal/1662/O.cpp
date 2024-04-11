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
const int A = 22*360;
bool ban[A][A];
vi g[A];
int vis[A];

int to(int r, int a) {
    return r*360 + a%360;
}

void dfs(int v) {
    vis[v] = 1;
    for(auto u : g[v]) if(ban[u][v] == 0 && vis[u] == 0) dfs(u);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(r,0,22) {
        forn(a,0,360) {
            int u = to(r,a);
            int v = to(r,a+1);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    forn(r,1,22) {
        forn(a,0,360) {
            int u = to(r,a);
            int v = to(r-1,a);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        forn(u,0,A) for(auto v : g[u]) ban[u][v] = 0;
        forn(i,0,A) vis[i] = 0;
        while(n--) {
            char c;
            scanf("%c", &c);
            if(c == 'C') {
                int r,a,b;
                scanf("%d %d %d\n", &r, &a, &b);
                while(a!=b) {
                    int u = to(r-1, a);
                    int v = to(r, a);
                    ban[u][v] = 1;
                    ban[v][u] = 1;
                    a = (a+1)%360;
                }
            }
            else {
                int r1,r2,a;
                scanf("%d %d %d\n", &r1, &r2, &a);
                while(r1 < r2) {
                    int u = to(r1, a);
                    int v = to(r1,a+359);
                    ban[u][v] = 1;
                    ban[v][u] = 1;
                    r1++;
                }
            }
        }
        dfs(to(21,0));
        if(vis[to(0,0)]) printf("YES\n");
        else printf("NO\n");
    }
    
    
}