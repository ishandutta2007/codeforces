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
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}
int d[200][200];
vvi g;
int n;
int cnt = 0;
void dfs(int v, int p) {
    cnt++;
    for(auto u : g[v]) if(u!=p) dfs(u,v);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    vvll prob(n, vll(n, 0));
    forn(i,1,n) prob[i][0] = 1;
    ll i2  = invmod(2, mod);
    forn(i,1,n) forn(j,1,n) {
        prob[i][j] = (prob[i-1][j] + prob[i][j-1])*i2%mod;
    }
    g.resize(n);
    forn(i,0,n) forn(j,0,n) d[i][j] = n;
    forn(i,0,n) d[i][i] = 0;
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        d[u][v] = 1;
        d[v][u] = 1;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll in= invmod(n, mod);
    ll ans = 0;
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (d[i][k] < n && d[k][j] < n)
                    d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    forn(s,0,n) forn(e,s+1,n) {
        vi path(d[s][e] + 1, 0);
        forn(i,0,n) if(d[i][s] + d[i][e] == d[s][e]) path[d[i][s]] = i;
        forn(i,0,d[s][e]+1) {
            cnt = 1;
            for(auto v : g[path[i]]) {
                if(i>0 && v == path[i-1]) continue;
                if(i<d[s][e] && v == path[i+1]) continue;
                dfs(v, path[i]);
            }
//            printf("%d %d %d %d %d\n", s,e,i,d[s][e]-i,cnt);
            ans = (ans + prob[i][d[s][e] - i] * cnt % mod * in) % mod;
        }
    }
    cout<<ans;

    
}