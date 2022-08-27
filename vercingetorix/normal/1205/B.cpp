#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <queue>
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
int n,r;
vvi g;
const int INF = 1e6;
vi d,p;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    forn(i,0,n) {
        if(a[i] == 0) {
            swap(a[i], a[n-1]);
            n--;
            i--;
        }
    }
    if(n>120) {
        cout<<3;
        exit(0);
    }
    g.resize(n);
    forn(i,0,n) {
        forn(j,i+1,n) {
            if(a[i]&a[j]) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    int ans = INF;
    forn(s,0,n) {
        d = vi(n, INF);
        p = vi(n, -1);
        d[s] = 0;
        priority_queue < pair<int,int> > q;
        q.push (make_pair (0, s));
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[v])  continue;
            
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j],
                len = 1;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push (make_pair (-d[to], to));
                }
            }
        }
        forn(u,0,n) for(auto v : g[u]) {
            if(u!=p[v] && v!=p[u]) ans = min(ans, d[u] + d[v] + 1);
        }
    }
    if(ans == INF) ans = -1;
    cout<<ans;
}