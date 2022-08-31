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
const int INF = 1e9 + 100;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vector < vector < pair<int,int> > > g (n);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v,&w);
        u--;v--;
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }
    vi p2;
    forn(i,0,200) p2.pb(i*i);
    int s = 0;
    vi bu(n, 100);
    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    priority_queue < pair<int,int> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second,  cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        
        for (size_t j=0; j<g[v].size(); ++j) {
            int spin = g[v][j].first;
            int l = g[v][j].second;
            if(bu[spin] <= l) continue;
            bu[spin] = l;
            forn(k,0,g[spin].size()) {
                int len = g[spin][k].second;
                int to = g[spin][k].first;
                if(d[to] > d[v] + p2[len + l]) {
                    d[to] = d[v] + p2[len + l];
                    p[to] = v;
                    q.push(mp(-d[to], to));
                }
                
            }
        }
    }
    forn(i,0,n) if(d[i] == INF) d[i] = -1;
    forn(i,0,n) printf("%d ", d[i]);
    
}