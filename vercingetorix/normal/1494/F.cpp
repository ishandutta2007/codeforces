#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <stack>
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
vvi g;
vpi e;
vvi ban;
vi ans;
vi pr;
int n,m;
set<int> gs[3000];

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(ban[u][v]) continue;
    }
}

bool euler(int s) {
    ans.clear();
    forn(i,0,n) {
        gs[i].clear();
        for(auto u : g[i]) if(ban[u][i] == 0) gs[i].insert(u);
    }
    stack<int> x;
    x.push(s);
    while(!x.empty()) {
        int v = x.top();
        if(gs[v].empty()) {
            ans.pb(v);
            x.pop();
        }
        else {
            int u = *gs[v].begin();
            gs[v].erase(u);
            gs[u].erase(v);
            x.push(u);
        }
    }
    reverse(all(ans));
    return true;
}

void win() {
    printf("%d\n", ans.size());
    for(auto x : ans) {
        if(x!=-1) x++;
        printf("%d ", x);
    }
    printf("\n");
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &m);
    g.resize(n);
    vvi a(n, vi(n, 0));
    vi isbad(n,0);
    ban = vvi(n, vi(n, 0));
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
        a[u][v] = 1;
        a[v][u] = 1;
    }
    vi odd;
    forn(i,0,n) if(g[i].size() % 2) odd.pb(i);
    for(auto x : odd) isbad[x] = 1;
    forn(e,0,n) {
        int bad = -1;
        int cbad = 0;
        for(auto x : odd) {
            if(x!=e && a[x][e] == 0) {
                cbad++;
                bad = x;
            }
        }
        int decos = isbad[e];
        if(cbad > 1) continue;
        else if(cbad == 1) {
            for(auto x : odd) if(x != bad) {
                ban[x][e] = 1;
                ban[e][x] = 1;
            }
            euler(bad);
            if(ans.size() - 1 + odd.size() - 1 - decos == m) {
                ans.pb(-1);
                for(auto x : odd) if(x != bad && x != e) {
                    ans.pb(x);
                    ans.pb(e);
                }
                win();
            }
            for(auto x : odd) if(x != bad) {
                ban[x][e] = 0;
                ban[e][x] = 0;
            }
        }
        else {
            for(auto x : odd) {
                ban[x][e] = 1;
                ban[e][x] = 1;
            }
            euler(e);
            if(ans.size() - 1 + odd.size() - decos == m) {
                ans.pb(-1);
                for(auto x : odd) if(x != e){
                    ans.pb(x);
                    ans.pb(e);
                }
                win();
            }
            for(auto x : odd) {
                ban[x][e] = 0;
                ban[e][x] = 0;
            }
            for(auto notbad : odd) if(notbad != e){
                for(auto x : odd) if(x != notbad) {
                    ban[x][e] = 1;
                    ban[e][x] = 1;
                }
                euler(notbad);
                if(ans.size() - 1 + odd.size() - decos- 1 == m) {
                    ans.pb(-1);
                    for(auto x : odd) if(x != notbad && x != e) {
                        ans.pb(x);
                        ans.pb(e);
                    }
                    win();
                }
                for(auto x : odd) if(x != notbad) {
                    ban[x][e] = 0;
                    ban[e][x] = 0;
                }
            }
            for(auto newbad : g[e]) {
                if(isbad[newbad]) continue;
                for(auto x : odd) {
                    ban[x][e] = 1;
                    ban[e][x] = 1;
                }
                ban[e][newbad] = 1;
                ban[newbad][e] = 1;
                euler(newbad);
                if(ans.size() - 1 + odd.size()- decos + 1 == m) {
                    ans.pb(-1);
                    for(auto x : odd) if(x != e) {
                        ans.pb(x);
                        ans.pb(e);
                    }
                    ans.pb(newbad);
                    ans.pb(e);
                    win();
                }
                ban[e][newbad] = 0;
                ban[newbad][e] = 0;
                for(auto x : odd) {
                    ban[x][e] = 0;
                    ban[e][x] = 0;
                }
            }
        }
    }
    printf("0\n");
}