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

vi ord;
vvi g;
void dfs(int v, int p) {
    ord.pb(v);
    for(auto u : g[v]) if(u!=p) dfs(u, v);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    g.resize(n);
    vvi c(3, vi(n));
    forn(i,0,3) forn(j,0,n) scanf("%d", &c[i][j]);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int s = -1;
    forn(i,0,n) {
        if(g[i].size() > 2) {
            printf("-1\n");
            exit(0);
        }
        if(g[i].size() == 1) s = i;
    }
    dfs(s, s);
    vi p = {0,1,2};
    ll ans = 1e18;
    vi res(n);
    do {
        ll cand = 0;
        forn(i,0,n) {
            cand += c[p[i%3]][ord[i]];
        }
        if(ans > cand) {
            ans = cand;
            forn(i,0,n) res[ord[i]] = p[i%3] + 1;
        }
    } while(next_permutation(all(p)));
    printf("%lld\n", ans);
    forn(i,0,n) printf("%d ", res[i]);
}