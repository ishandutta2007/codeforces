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

vi ans[2];

vi cur[2];
vvi g;

int ask(const vi & ver) {
    if(ver.size() <= 1) return 0;
    printf("? %d\n", ver.size());
    printf("%d", ver[0]+1);
    forn(i,1,ver.size()) printf(" %d", ver[i]+1);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

vi path;
int vp[700];

bool dfs(int v, int to) {
    vp[v] = 1;
    if(v == to) {
        path.pb(v);
        return true;
    }
    for(auto u : g[v]) {
        if(vp[u] == 0) {
            if(dfs(u,to)) {
                path.pb(v);
                return true;
            }
        }
    }
    return false;
}

void die() {
    printf("N %d\n", path.size());
    for(auto x : path) printf("%d ", x+1);
    exit(0);
}

vi sel(int v, vi & out, int num) {
    if(num == 0) return vi();
    else if(num == out.size()) return out;
    vi h[2];
    forn(i,0,out.size()) h[i%2].pb(out[i]);
    int num0 = -ask(h[0]);
    h[0].pb(v);
    num0 += ask(h[0]);
    h[0].pop_back();
    vi ret = sel(v, h[0], num0);
    for(auto x : sel(v, h[1], num-num0)) ret.pb(x);
    return ret;
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int n;
    scanf("%d", &n);
    g.resize(n);
    vi vis(n,-1);
    vi q;
    forn(i,0,n) {
        if(vis[i] == -1) {
            cur[0].pb(i);
            vis[i] = 0;
            q.pb(i);
        }
        while(!q.empty()) {
            int v = q.back();
            int col = vis[v];
            q.pop_back();
            vi req;
            forn(j,0,n) if(vis[j] == -1) req.pb(j);
            int out = ask(req);
            req.pb(v);
            int in = ask(req);
            req.pop_back();
            vi con = sel(v, req, in-out);
            for(auto x : con) {
                g[x].pb(v);
                g[v].pb(x);
                cur[col^1].pb(x);
                int bnum = ask(cur[col^1]);
                if(bnum > 0) {
                    cur[col^1].pop_back();
                    vi bad = sel(x, cur[col^1], bnum);
                    dfs(x, bad[0]);
                    die();
                }
                vis[x] = col^1;
                q.pb(x);
            }
        }
        forn(s,0,2) for(auto x : cur[s]) ans[s].pb(x);
        forn(s,0,2) cur[s].clear();
    }
    printf("Y %d\n", ans[0].size());
    for(auto x : ans[0]) printf("%d ", x+1);
    
    
}