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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

const ll INF = 1e18;
int n;
vi use;
vvll a;
vll dij (int s, int inv) {
    vll res(n, INF);
    vector<ll> d (n, INF),  p (n);
    d[s] = 0;
    vector<char> u (n);
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;
        
//        for (size_t j=0; j<g[v].size(); ++j) {
        forn(j,0,n) {
            if(!use[j]) continue;
            int to = j;
//            int to = g[v][j].first,
            ll len = a[v][j];
            if(inv) len = a[j][v];
//            len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    use = vi(n,0);
    a = vvll(n, vll(n));
    forn(i,0,n) forn(j,0,n) scanf("%lld", &a[i][j]);
    vll ans;
    vi x(n);
    forn(i,0,n) scanf("%d", &x[i]);
    forn(i,0,n) x[i]--;
    reverse(all(x));
    ll cur = 0;
    vvll dist(n, vll(n, INF));
    for(auto v : x) {
        vll from = dij(v, 0);
        vll to = dij(v, 1);
        forn(i,0,n) if(use[i]) {
            cur += from[i] + to[i];
            dist[v][i] = from[i];
            dist[i][v] = to[i];
        }
        dist[v][v] = 0;
        forn(i,0,n) forn(j,0,n) {
            if(i==v || j==v || i==j) continue;
            if(dist[i][j] > dist[i][v] + dist[v][j]) {
                cur -= dist[i][j];
                dist[i][j] = dist[i][v] + dist[v][j];
                cur += dist[i][j];
            }
        }
        ans.pb(cur);
        use[v] = 1;
    }
    reverse(all(ans));
    for(auto x : ans) printf("%lld ", x);
}