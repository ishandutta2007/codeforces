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
const int A = 201;
vi g[A];
int b[A];
int curbest;

int dfs(int v, int p, int ban) {
    int best[2];
    best[0] = 0;
    best[1] = 0;
    for(auto u : g[v]) {
        if(u == p || u == ban) continue;
        int cur = 1 + dfs(u,v,ban);
        if(cur >= best[0]) {
            best[1] = best[0];
            best[0] = cur;
        }
        else if(cur >= best[1]) best[1] = cur;
    }
    if(ban == -1) b[v] = best[0] + best[1];
    else curbest = max(curbest, best[0] + best[1]);
    return best[0];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0,-1);
    int ans = 0;
    forn(i,1,n) {
        curbest = 0;
        dfs(0,0,i);
        ans = max(ans, curbest*b[i]);
    }
    cout<<ans;
    
}