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
vi a;
int n,m;
int vis[10001][1001];
int st = 0;
vi q[10002];
int d[10001];
ll ans = -1;
int g,r;
void dfs(int v, int tl) {
    if(v==m-1) if(ans == -1 || ans > g*(st+1) + r*st - tl) ans = g*(st+1) + r*st - tl;
    vis[v][tl] = 1;
    if(tl == 0) {
        d[v] = st+1;
        q[st+1].pb(v);
    }
    if(v>0 && a[v]-a[v-1] <= tl && vis[v-1][tl-a[v] + a[v-1]] == 0) dfs(v-1, tl-a[v]+a[v-1]);
    if(v<m-1 && a[v+1]-a[v] <= tl && vis[v+1][tl-a[v+1] + a[v]] == 0) dfs(v+1, tl-a[v+1]+a[v]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    a.resize(m);
    forn(i,0,m) scanf("%d", &a[i]);
    srt(a);
    
    scanf("%d %d", &g, &r);
    forn(i,0,m) d[i] = -1;
    d[0] = 0;
    q[0].pb(0);
    vis[0][0] = 1;
    while(!q[st].empty()) {
        for(auto x : q[st]) dfs(x, g);
        st++;
    }
    cout<<ans;
    
    
}