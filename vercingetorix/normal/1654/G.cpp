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
vi ge[A];
vi g2[A];
int d[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(tp,n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    const int INF = 1e9;
    vi dist(n);
    {
        priority_queue < pair<int,int> > q;
//        vector<int> d (n, INF);
        forn(i,0,n) d[i] = INF;
        forn(i,0,n) if(tp[i] == 1) {
            d[i] = 0;
            q.push(mp(0, i));
        }
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[v])  continue;
            
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j];
                if (d[v] + 1 < d[to]) {
                    d[to] = d[v] + 1;
                    q.push (make_pair (-d[to], to));
                }
            }
        }
        forn(i,0,n) dist[i] = d[i];
    }
    vi ans = dist;
    vi fnum(n,-1);
    vvi flat(n);
    forn(v,0,n) for(auto u : g[v]) {
        if(dist[u] > dist[v]) g2[v].pb(u);
        else if(dist[u] == dist[v]) ge[v].pb(u);
    }
    forn(v,0,n) for(auto u : g[v]) if(dist[u] == dist[v]) {
        fnum[u] = dist[u];
        fnum[v] = dist[v];
    }
    forn(i,0,n) if(fnum[i] != -1) flat[fnum[i]].pb(i);
    vi reach = dist;
    forn(lev,0,n) if(!flat[lev].empty()) {
        forn(i,0,n) d[i] = INF;
        priority_queue < pair<int,int> > q;
        for(auto v : flat[lev]) if(reach[v] == lev) {
            d[v] = lev;
            q.push(mp(-lev, v));
        }
        while(!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if(reach[v] < lev) continue;
            if (cur_d > d[v])  continue;
            if(cur_d <= dist[v]) reach[v] = lev;
            for (size_t j=0; j<g2[v].size(); ++j) {
                int to = g2[v][j];
                int nlen = max(dist[to], d[v]);
                if (nlen < d[to]) {
                    d[to] = nlen;
                    q.push (make_pair (-d[to], to));
                }
            }
            for (size_t j=0; j<ge[v].size(); ++j) {
                int to = ge[v][j];
                int nlen = max(dist[to], d[v]+1);
                if (nlen < d[to]) {
                    d[to] = nlen;
                    q.push (make_pair (-d[to], to));
                }
            }
        }
    }
    forn(i,0,n) printf("%d ", 2*dist[i] - reach[i]);
    
}