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

void no() {
    cout<<"Impossible";
    exit(0);
}

const int MAXN = 200*2;
int n;
int n2;
struct edge {
    int v, to, u, f, c;
};
vector<edge> edges;
vector<int> g[MAXN];

void add_edge (int v, int to, int cap, int cost) {
    edge e1 = { v, to, cap, 0, cost };
    edge e2 = { to, v, 0, 0, -cost };
    g[v].push_back ((int) edges.size());
    edges.push_back (e1);
    g[to].push_back ((int) edges.size());
    edges.push_back (e2);
}

void go() {
    const int INF = 1000000000;
    for (;;) {
        bool found = false;
        vector<int> d (n, INF);
        vector<int> par (n, -1);
        vi rec(n2,-1);
        vi u;
        forn(i,0,n) u.pb(i);
        shuffle(all(u), gen);
//        for (int i=0; i<n; ++i)
        for(auto i : u)
            if (d[i] == INF) {
                d[i] = 0;
                vector<int> q, nq;
                q.push_back (i);
                for (int it=0; it<n && q.size(); ++it) {
                    nq.clear();
                    sort (q.begin(), q.end());
                    q.erase (unique (q.begin(), q.end()), q.end());
                    for (size_t j=0; j<q.size(); ++j) {
                        int v = q[j];
                        for (size_t k=0; k<g[v].size(); ++k) {
                            int id = g[v][k];
                            if (edges[id].f < edges[id].u)
                                if (d[v] + edges[id].c < d[edges[id].to] && rec[v%n2] != edges[id].to%n2) {
                                    d[edges[id].to] = d[v] + edges[id].c;
                                    par[edges[id].to] = v;
                                    if(v%n2 != edges[id].to%n2)
                                    rec[edges[id].to%n2] = v%n2;
                                    nq.push_back (edges[id].to);
                                }
                        }
                    }
                    swap (q, nq);
                }
                if (q.size()) {
                    int leaf = q[0];
                    vector<int> path;
                    for (int v=leaf; v!=-1; v=par[v])
                        if (find (path.begin(), path.end(), v) == path.end())
                            path.push_back (v);
                        else {
                            path.erase (path.begin(), find (path.begin(), path.end(), v));
                            break;
                        }
                    for (size_t j=0; j<path.size(); ++j) {
                        int to = path[j],  v = path[(j+1)%path.size()];
                        for (size_t k=0; k<g[v].size(); ++k)
                            if (edges[ g[v][k] ].to == to) {
                                int id = g[v][k];
                                edges[id].f += 1;
                                edges[id^1].f -= 1;
                            }
                    }
                    found = true;
                }
            }
        
        if (!found)  break;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 20000;
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    read(n);
    readv(a,n);
    vpi b,c;
    forn(i,0,n) if(a[i]&1) b.pb(mp(a[i], i+1));
    forn(i,0,n) add_edge(i, n+i, 1, -1);
    forn(i,0,n) forn(j,i+1,n) {
        if(isp[a[i] + a[j]]) {
            add_edge(n+i, j, 1, 0);
            add_edge(n+j, i, 1, 0);
        }
    }
    n2 =n;
    int done = 0;
    vi pp(n, -1);
    while(1) {
        forn(i,0,n) pp[i] = -1;
        for(auto & x : edges) x.f = 0;
        n*=2;
        go();
        n/=2;
        for(auto & x : edges) {
            if(x.f == 1 && x.v >= n) pp[x.v-n] = x.to;
        }
        forn(i,0,n) if(pp[i] == -1) no();
        int notbad = 1;
        forn(i,0,n) if(pp[pp[i]] == i) notbad = 0;
        if(notbad) break;
    }
    
    vi vis(n,0);
    vvi ans;
    forn(i,0,n) if(!vis[i]) {
        ans.pb(vi(1,i+1));
        vis[i] = 1;
        for(int j = pp[i]; j != i; j = pp[j]) {
            vis[j] = 1;
            ans.back().pb(j+1);
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans) {
        printf("%d", x.size());
        for(auto y : x) printf(" %d", y);
        printf("\n");
    }
//    forn(i,0,n) printf("%d ", pp[i]);
}