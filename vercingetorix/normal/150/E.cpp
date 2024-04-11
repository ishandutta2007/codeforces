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
const int A = 100500;
vpi g[A];
vi ver;
vi ch[A];
vpi ch2[A];
int ban[A];
int st[A];
int n,pl,pr;

int best = -1;
pi ans = mp(-1,-1);
int can;
vi fc;

int dfsst(int v, int p) {
    ver.pb(v);
    st[v] = 1;
    int bd[2];
    bd[0] = 0;
    bd[1] = 0;
    for(auto u : g[v]) {
        if(u.first == p || ban[u.first]) continue;
        ch[v].pb(u.first);
        fc.pb(u.second);
        int cd = dfsst(u.first, v);
        if(cd >= bd[0]) {
            bd[1] = bd[0];
            bd[0] = cd;
        }
        else if(cd >= bd[1]) bd[1] = cd;
        st[v] += st[u.first];
    }
    if(bd[0] + bd[1] >= pl) can = 1;
    return bd[0] + 1;
}

void dfsch(int v, int p) {
    for(auto u : g[v]) {
        if(u.first == p || ban[u.first]) continue;
        ch2[v].pb(u);
        dfsch(u.first, v);
    }
}

int lim,root;
int curd;

pi maxdif[A];
pi curmaxdif[A];
set<pi> dist[2*A];
vpi curdist[2*A];
int bal;
int depth;
int maxdepth;
int curmaxdepth;
int done = 0;


void dfs(int v) {
    if(depth > pr) return;
    int mn = max(pl - depth, 0);
    auto it = dist[A-bal].lower_bound(mp(mn, 0));
    if(it != dist[A-bal].end() && it->first <= pr-depth) {
        if(lim > best) {
            best = lim;
            ans = mp(v+1, it->second + 1);
        }
        done = 1;
        return;
    }
    if(depth <= pl) {
        if(maxdif[pl-depth].first + bal >= 0) {
            if(lim > best) {
                best = lim;
                ans = mp(v+1, maxdif[pl-depth].second + 1);
            }
            done = 1;
            return;
        }
    }
    curmaxdif[depth] = max(curmaxdif[depth], mp(bal, v));
    curdist[A+bal].pb(mp(depth, v));
    curmaxdepth = max(curmaxdepth, depth);
    for(auto u : ch2[v]) {
        if(u.second >= lim) bal++;
        else bal--;
        depth++;
        dfs(u.first);
        if(u.second >= lim) bal--;
        else bal++;
        depth--;
        if(v == root) {
            maxdepth = max(maxdepth, curmaxdepth);
            forn(i,1,curmaxdepth+1) {
                maxdif[i] = max(maxdif[i], curmaxdif[i]);
                curmaxdif[i] = mp(-n,-1);
            }
            forn(i,A-curmaxdepth,A+curmaxdepth+1) {
                for(auto x : curdist[i]) {
                    dist[i].insert(x);
                }
                curdist[i].clear();
            }
            curmaxdepth = 0;
        }
        if(done) return;
    }
}

void clean() {
    for(auto v : ver) {
        ch[v].clear();
        ch2[v].clear();
    }
    ver.clear();
}

void go(int sv) {
    fc.clear();
    ver.clear();
    can = 0;
    dfsst(sv, sv);
    if(can == 0) {
        clean();
        return;
    }
    root = sv;
    while(1) {
        int was = root;
        for(auto u : ch[root]) {
            if(st[u]*2 >= st[sv]) {
                root = u;
                break;
            }
        }
        if(root == was) break;
    }
    for(auto v : ver) ch[v].clear();
    srtrev(fc);
    int l = 0;
    int r = fc.size();
    dfsch(root, root);
    if(r - l == 1) {
        r = l+2;
    }
    while(r-l > 1) {
        int m = (r+l)/2;
        lim = fc[m-1];
        done = 0;
        maxdepth = 0;
        dist[0].insert(mp(0, root));
        maxdif[0] = mp(0, root);
        dfs(root);
        if(done) r = m;
        else l = m;
        forn(i,0,maxdepth+1) {
            maxdif[i] = mp(-n,-1);
        }
        forn(i,A-maxdepth,A+maxdepth+1) {
            dist[i].clear();
        }
    }
    ban[root] = 1;
    vpi nx = ch2[root];
    clean();
    for(auto v : nx) {
        go(v.first);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d %d", &n, &pl, &pr);
    forn(i,0,A) {
        maxdif[i] = mp(-n,-1);
        curmaxdif[i] = mp(-n,-1);
    }
    forn(i,0,n-1) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        g[u].pb(mp(v,c));
        g[v].pb(mp(u,c));
    }
    go(0);
    cout<<ans.first<<' '<<ans.second;
    
    
    
}