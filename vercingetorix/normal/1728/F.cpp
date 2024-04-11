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

int n;
const int A = 1000;
//vector < vector<int> > g;
vi g[A];
vi grev[A];
int mt[A];
int mtrev[A];
char used[A];

int fr[A];

bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int vis[A];
void dfs(int v) {
    vis[v] = 1;
    for(auto mu : grev[v]) {
        int u = mtrev[mu];
        if(!vis[u]) dfs(u);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    readv(a,n);
    forn(i,0,n) mt[i] = -1;
    int cur = 0;
    ll ans = 0;
    forn(it,0,n) {
        forn(i,0,n) fr[i] = 1;
        forn(i,0,n) if(mt[i] != -1) {
            fr[i] = 0;
            mtrev[mt[i]] = i;
        }
        forn(i,0,n) vis[i] = 0;

        forn(i,0,n) if(fr[i] && vis[i]==0) dfs(i);
        
        int nx = 2e9;
        forn(i,0,n) if(vis[i]) nx = min(nx, cur/a[i]*a[i]+a[i]);
        ans += nx;
        forn(i,0,n) if(nx%a[i]==0) {
            g[it].pb(i);
            grev[i].pb(it);
        }
        forn(i,0,n) used[i] = false;
        try_kuhn(it);
        cur = nx;
    }
    cout<<ans;
    
    
    
}