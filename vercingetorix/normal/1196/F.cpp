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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    vector<pair<int, pi>> e(m);
    forn(i,0,m) {
        scanf("%d %d %d", &e[i].second.first, &e[i].second.second, &e[i].first);
        e[i].second.first--;
        e[i].second.second--;
    }
    srt(e);
    while(e.size() > k) e.pop_back();
    vi touch(n,0);
    vector < vector < pair<int,int> > > g (n);
    for(auto x : e) {
        touch[x.second.first] = 1;
        touch[x.second.second] = 1;
        g[x.second.first].pb(mp(x.second.second, x.first));
        g[x.second.second].pb(mp(x.second.first, x.first));
    }
    const ll INF = 1e18;
    vi ver;
    forn(i,0,n) if(touch[i]) ver.pb(i);
    vll dist;
    vector<ll> d (n, INF);
    for(auto s : ver) {
        for(auto x : ver) d[x] = INF;
        d[s] = 0;
        priority_queue < pair<ll,int> > q;
        q.push (make_pair (0, s));
        while (!q.empty()) {
            int v = q.top().second;
            ll cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[v])  continue;
            if(v != s) dist.pb(cur_d);
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    q.push (make_pair (-d[to], to));
                }
            }
        }
    }
    srt(dist);
    cout<<dist[2*k-1];
    
}