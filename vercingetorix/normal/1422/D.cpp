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
#include <queue>

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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const ll INF = 1e18;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N,M;
    scanf("%d %d", &N, &M);
    int sx,sy,fx,fy;
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
    
    
    int n = M + 2;
//    ...  n ...
    vector < vector < pair<int,int> > > g (n);
//    ...   ...
    int s = M; //  
    vi xc(M), yc(M);
    map<int, vi> lx, ly;
    set<int> xx,yy;
    forn(i,0,M) {
        scanf("%d %d", &xc[i], &yc[i]);
        if(lx.find(xc[i]) == lx.end()) lx[xc[i]] = vi();
        if(ly.find(yc[i]) == ly.end()) ly[yc[i]] = vi();
        lx[xc[i]].pb(i);
        ly[yc[i]].pb(i);
        xx.insert(xc[i]);
        yy.insert(yc[i]);
        g[M].pb(mp(i,min(abs (sx-xc[i]), abs(sy-yc[i]))));
    }
    int last = -1;
    g[M].pb(mp(M+1, abs(sx-fx) + abs(sy-fy)));
    for(auto x : xx) {
        if(last != -1) {
            for(auto v : lx[last]) {
                g[v].pb(mp(lx[x][0], x-last));
            }
            for(auto v : lx[x]) {
                g[v].pb(mp(lx[last][0], x-last));
            }
        }
        if(lx[x].size() > 1) {
            g[lx[x].back()].pb(mp(lx[x][0], 0));
            forn(i,0,lx[x].size() - 1) {
                g[lx[x][i]].pb(mp(lx[x][i+1], 0));
            }
        }
        for(auto v : lx[x]) g[v].pb(mp(M+1, abs(xc[v]-fx) + abs(yc[v]-fy)));
        last = x;
    }
    last = -1;
    for(auto y : yy) {
        if(last != -1) {
            for(auto v : ly[last]) {
                g[v].pb(mp(ly[y][0], y-last));
            }
            for(auto v : ly[y]) {
                g[v].pb(mp(ly[last][0], y-last));
            }
        }
        if(ly[y].size() > 1) {
            g[ly[y].back()].pb(mp(ly[y][0], 0));
            forn(i,0,ly[y].size() - 1) {
                g[ly[y][i]].pb(mp(ly[y][i+1], 0));
            }
        }
        last = y;
    }
    
    vector<ll> d (n, INF),  p (n);
    d[s] = 0;
    priority_queue < pair<ll,int> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second;
        ll cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        
        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
            len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push (make_pair (-d[to], to));
            }
        }
    }
    cout<<d[s+1];
}