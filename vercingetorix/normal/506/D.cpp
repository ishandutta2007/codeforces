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
const int A = 500;
vi touch;
vi vis;
vvi qnum;
vi big;
vvi g;
vi bigtouch;
const int N = 100500;
int d[A][N];
vi curvis;
int qt[N];
int ans[N];
vi qtouch;

void dfs(int v) {
    vis[v] = 1;
    if(big[v] >= 0) {
        bigtouch.pb(v);
    }
    else {
        for(auto x : qnum[v]) {
            if(qt[x]) ans[x]++;
            else {
                qt[x] = 1;
                qtouch.pb(x);
            }
        }
    }
    curvis.pb(v);
    for(auto u : g[v]) if(!vis[u]) dfs(u);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    vvpi e(m);
    vis = vi(n,0);
    forn(i,0,m) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        c--; u--; v--;
        e[c].pb(mp(u,v));
    }
    int q;
    scanf("%d", &q);
    qnum = vvi (n);
    big = vi(n,-1);
    int bc = 0;
    g.resize(n);
    vpi qq;
    forn(i,0,q) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        qnum[u].pb(i);
        qnum[v].pb(i);
        qq.pb(mp(u,v));
    }
    forn(i,0,n) if(qnum[i].size() >= A) big[i] = bc++;
    forn(col,0,m) {
        for(auto x : e[col]) {
            g[x.first].pb(x.second);
            g[x.second].pb(x.first);
            touch.pb(x.first);
            touch.pb(x.second);
        }
        for(auto x : touch) if(!vis[x]) {
            dfs(x);
            for(auto x : bigtouch) for(auto y : curvis) d[big[x]][y]++;
            bigtouch.clear();
            curvis.clear();
            for(auto x : qtouch) {
                qt[x] = 0;
            }
            qtouch.clear();
            
        }
        for(auto x : touch) {
            vis[x] = 0;
            g[x].clear();
        }
        touch.clear();
        curvis.clear();
    }
    forn(i,0,q) {
        if(big[qq[i].first]>=0) ans[i] = d[big[qq[i].first]][qq[i].second];
        else if(big[qq[i].second]>=0) ans[i] = d[big[qq[i].second]][qq[i].first];
        printf("%d\n", ans[i]);
    }
    
    
    
}