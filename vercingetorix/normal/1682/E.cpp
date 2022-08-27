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
vpi g[A];
int lev[A];
int vis[A];
pi par[A];

void dfs1(int v) {
    vis[v] = 1;
    for(auto u : g[v]) {
        if(vis[u.first] == 0) {
            par[u.first] = mp(v, u.second);
            lev[u.first] = lev[v] + 1;
            dfs1(u.first);
        }
    }
}

vi path[A];

vi getpath(int a, int b) {
    vi l;
    vi r;
    while(lev[a] > lev[b]) {
        l.pb(par[a].second);
        a = par[a].first;
    }
    while(lev[b] > lev[a]) {
        r.pb(par[b].second);
        b = par[b].first;
    }
    while(a!=b) {
        l.pb(par[a].second);
        a = par[a].first;
        r.pb(par[b].second);
        b = par[b].first;
    }
    while(!r.empty()) {
        l.pb(r.back());
        r.pop_back();
    }
    return l;
}

int sum[A];
int pt[A];
int cnt[A];
vi loc[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(p,n);
    forn(i,0,n) p[i]--;
    vi x(m), y(m);
    forn(i,0,m) scanf("%d %d", &x[i], &y[i]);
    forn(i,0,m) {
        x[i]--;
        y[i]--;
        g[x[i]].pb(mp(y[i], i));
        g[y[i]].pb(mp(x[i], i));
    }
    forn(i,0,n) {
        if(vis[i] == 0) {
            dfs1(i);
        }
    }
    forn(i,0,n) if(i!=p[i]) {
        path[i] = getpath(i, p[i]);
        cnt[path[i][0]]++;
        for(auto v : path[i]) loc[v].pb(i);
    }
    vi q;
    forn(i,0,m) if(cnt[i] == 2) {
        q.pb(i);
    }
    while(!q.empty()) {
        printf("%d ", q.back() + 1);
        int ind = q.back();
        q.pop_back();
        for(auto pos : loc[ind]) {
            pt[pos]++;
            if(pt[pos] < path[pos].size()) {
                cnt[path[pos][pt[pos]]]++;
                if(cnt[path[pos][pt[pos]]] == 2) q.pb(path[pos][pt[pos]]);
            }
        }
    }
    
    
}