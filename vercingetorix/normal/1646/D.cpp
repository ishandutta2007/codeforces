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
vi g[A];
pi d1[A];
pi d0[A];

pi operator+(pi & a, pi & b) {
    return mp(a.first+b.first, a.second + b.second);
}

void dfs(int v, int p) {
    d0[v] = mp(0, 1);
    d1[v] = mp(-1, g[v].size());
    for(auto u : g[v]) {
        if(u == p) continue;
        dfs(u,v);
        d1[v] = d1[v] + d0[u];
        if(d0[u] <= d1[u]) d0[v] = d0[v] + d0[u];
        else d0[v] = d0[v] + d1[u];
    }
}

int ans[A];
int cnt = 0;

void dfs2(int v, int p, int cur) {
    if(cur == 1 && d0[v] < d1[v]) cur = 0;
    if(cur) {
        cnt++;
        ans[v] = g[v].size();
    }
    else ans[v] = 1;
    for(auto u : g[v]) {
        if(u == p) continue;
        dfs2(u, v, cur^1);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    if(n==2) {
        printf("2 2\n");
        printf("1 1\n");
        exit(0);
    }
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, 0);
    dfs2(0, 0, 1);
    int sum  = 0;
    forn(i,0,n) sum += ans[i];
    printf("%d %d\n", cnt, sum);
    forn(i,0,n) printf("%d ", ans[i]);
    
    
}