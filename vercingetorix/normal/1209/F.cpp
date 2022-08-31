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
#include <queue>
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
typedef std::pair<pi, int> ppi;
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

vvpi ch;
vll ans;

void dfs(int v, ll val) {
    ans[v] = val;
    for(auto u : ch[v]) {
        dfs(u.first, (ll(val)*10+u.second)%mod);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    vvpi g;
    g.resize(m*14);
    int wn = n;
    forn(i,1,m+1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        vi dig;
        int k = i;
        while(k>0) {
            dig.pb(k%10);
            k/=10;
        }
        reverse(all(dig));
        if(dig.size() == 1) {
            g[u].pb(mp(i, v));
        }
        else {
            int last = u;
            forn(f,0,dig.size() - 1) {
                g[last].pb(mp(dig[f], n));
                last = n++;
            }
            g[last].pb(mp(dig.back(), v));
        }
        if(dig.size() == 1) {
            g[v].pb(mp(i, u));
        }
        else {
            int last = v;
            forn(f,0,dig.size() - 1) {
                g[last].pb(mp(dig[f], n));
                last = n++;
            }
            g[last].pb(mp(dig.back(), u));
        }
    }
    ans.resize(n);
    ch.resize(n);
    ans[0] = 0;
    vi d(1,0);
    vi re(1,0);
    vi p(n,0);
    vi vis(n,0);
    vis[0] = 1;
    vi pt(n,0);
    forn(i,0,n) srt(g[i]);
    while(1) {
        vi nd;
        vi nre;
        int r = 0;
        int nds = 0;
        while(r < d.size()) {
            int nr = re[r] + 1;
            forn(i,0,10) {
                int wnds = nds;
                forn(j,r,nr) {
                    while(pt[d[j]] < g[d[j]].size() && g[d[j]][pt[d[j]]].first == i) {
                        if(vis[g[d[j]][pt[d[j]]].second] == 0) {
                            nd.pb(g[d[j]][pt[d[j]]].second);
                            p[g[d[j]][pt[d[j]]].second] = d[j];
                            ch[d[j]].pb(mp(g[d[j]][pt[d[j]]].second, i));
                            vis[g[d[j]][pt[d[j]]].second] = 1;
                            nds++;
                        }
                        pt[d[j]]++;
                    }
                }
                forn(j,wnds,nds) {
                    nre.pb(nds-1);
                }
            }
            r = nr;
        }
        d = nd;
        re = nre;
        if(d.empty()) break;
    }
    dfs(0,0);
    forn(i,1,wn) printf("%lld\n", ans[i]);

    
}