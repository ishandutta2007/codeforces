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
vvpi g;
int mval[5050];

bool dfs(int v, int p, int to, int val) {
    if(v == to) return true;
    for(auto u : g[v]) {
        if(u.first == p) continue;
        if(dfs(u.first, v, to, val)) {
            mval[u.second] = max(mval[u.second], val);
            return true;
        }
    }
    return false;
}

bool dfsget(int v, int p, int to, int & minval) {
    if(v == to) return true;
    for(auto u : g[v]) {
        if(u.first == p) continue;
        if(dfsget(u.first, v, to, minval)) {
            minval = min(minval, mval[u.second]);
            return true;
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    g.resize(n);
    forn(i,0,n-1) mval[i] = 1;
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(mp(v,i));
        g[v].pb(mp(u,i));
    }
    int q;
    scanf("%d", &q);
    vi a(q), b(q), g(q);
    forn(i,0,q) {
        scanf("%d %d %d", &a[i], &b[i], &g[i]);
        a[i]--;
        b[i]--;
        dfs(a[i], a[i], b[i], g[i]);
    }
    int good = 1;
    forn(i,0,q) {
        int ans = 1e9;
        dfsget(a[i], a[i], b[i], ans);
        if(ans != g[i]) {
            good = 0;
            break;
        }
    }
    if(good) {
        forn(i,0,n-1) printf("%d ", mval[i]);
    }
    else printf("-1");
    
}