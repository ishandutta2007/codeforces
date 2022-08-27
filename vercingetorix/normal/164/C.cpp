#ifdef LOCAL
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
typedef std::priority_queue<int> pr_q;
#else
#include <bits/extc++.h>
typedef __gnu_pbds::priority_queue<std::pair<long long, int>> pr_q;
#endif

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
// #define read(x) scanf("%d", &x)
// #define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair


const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pik;
    vpi par;
    
    MCMF(int N) :
    N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
    seen(N), dist(N), pik(N), par(N) {}
    
    void addEdge(int from, int to, ll cap, ll cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }
    
    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0; ll di;
        
        pr_q q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});
        
        auto relax = [&](int i, ll cap, ll cost, int dir) {
            ll val = di - pik[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };
        
        while (!q.empty()) {
            s = q.top().second; q.pop();
            seen[s] = 1; di = dist[s] + pik[s];
            for (int i : ed[s]) if (!seen[i])
                relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            for (int i : red[s]) if (!seen[i])
                relax(i, flow[i][s], -cost[i][s], 0);
        }
        forn(i,0,N) pik[i] = min(pik[i] + dist[i], INF);
    }
    
    pair<ll, ll> maxflow(int s, int t) {
        ll totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            ll fl = INF;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        forn(i,0,N) forn(j,0,N) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }
    
    // If some costs can be negative, call this before maxflow:
    void setpi(int s) { // (otherwise, leave this out)
        fill(all(pik), INF); pik[s] = 0;
        int it = N, ch = 1; ll v;
        while (ch-- && it--)
            forn(i,0,N) if (pik[i] != INF)
                for (int to : ed[i]) if (cap[i][to])
                    if ((v = pik[i] + cost[i][to]) < pik[to])
                        pik[to] = v, ch = 1;
        // assert(it >= 0); // negative cost cycle
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vi s(n), t(n), c(n);
    vpi e;
    forn(i,0,n) {
        scanf("%d %d %d", &s[i], &t[i], &c[i]);
        e.pb(mp(s[i], i+1));
        e.pb(mp(s[i]+t[i], -i-1));
    }
    srt(e);
    map<pi, int> to;
    int pt = 0;
    for(auto x : e) to[x] = pt++;
    MCMF mc(pt+n+2);
    int st = pt+n;
    int en = st+1;
    mc.addEdge(st, 0, k, 0);
    mc.addEdge(pt-1, en, k, 0);
    forn(i,1,pt) mc.addEdge(i-1, i, k, 0);
    forn(i,0,n) {
        int u = to[mp(s[i], i+1)];
        int v = to[mp(s[i]+t[i], -i-1)];
        mc.addEdge(u, pt+i, 1, -c[i]);
        mc.addEdge(pt+i, v, 1, 0);
    }
    mc.setpi(st);
    auto res = mc.maxflow(st, en);
    forn(i,0,n) {
        int u = to[mp(s[i], i+1)];
        if(mc.flow[u][pt+i] > 0) printf("1 ");
        else printf("0 ");
    }
//    cout<<res.first <<' '<<res.second;
    
    
    
}