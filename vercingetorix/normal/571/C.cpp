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
#ifdef LOCAL
const int A = 20;
#else
const int A  =200500;
#endif
vpi g[A];
int par[A];
vi loc[A];
int done[A];
int vis[A];
int ans[A];
int cool[A];

int sg(int x) {
    return x<0? -1 : 1;
}

void dfsdone(int v) {
    for(auto u : g[v]) {
        if(vis[u.first] == 0) {
            vis[u.first] = 1;
            if(done[u.first] == 0) {
                done[u.first] = 1;
                ans[abs(u.second)] = -sg(u.second);
            }
            dfsdone(u.first);
        }
    }
}

void no() {
    printf("NO\n");
    exit(0);
}

vpi cycle;

bool dfs(int v, int p) {
    cool[v] = 1;
    for(auto u : g[v]) {
        if(abs(u.second)==p) continue;
        if(cool[u.first]) {
            done[v] = 1;
            cycle.pb(u);
            return true;
        }
        if(dfs(u.first,abs(u.second))) {
            done[v] = 1;
            cycle.pb(u);
            return true;
        }
    }
    return false;
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,m+1) ans[i] = -1;
    
    forn(i,1,n+1) {
        int k;
        scanf("%d", &k);
        forn(it,0,k) {
            int x;
            scanf("%d", &x);
            loc[abs(x)].pb(x/abs(x)*i);
        }
    }
    forn(i,1,m+1) {
        if(loc[i].empty()) continue;
        else if(loc[i].size() == 1 || abs(loc[i][0]) == abs(loc[i][1])) {
            done[abs(loc[i][0])] = 1;
            if(loc[i][0] > 0) ans[i] = 1;
        }
        else {
            if(sg(loc[i][0]) == sg(loc[i][1])) {
                done[abs(loc[i][0])] = 1;
                done[abs(loc[i][1])] = 1;
                if(loc[i][0] > 0) ans[i] = 1;
            }
            else {
                int v = abs(loc[i][0]);
                int u = abs(loc[i][1]);
                if(loc[i][0] > 0) {
                    g[v].pb(mp(u, i));
                    g[u].pb(mp(v, -i));
                }
                else {
                    g[v].pb(mp(u, -i));
                    g[u].pb(mp(v, i));
                }
            }
        }
    }
    forn(i,1,n+1) if(done[i] && vis[i] == 0) dfsdone(i);
    forn(i,1,n+1) {
        if(!done[i]) {
            cycle.clear();
            if(!dfs(i,0)) no();
            for(auto x : cycle) {
                ans[abs(x.second)] = sg(x.second);
            }
            dfsdone(i);
        }
    }
    printf("YES\n");
    string s;
    forn(i,1,m+1) if(ans[i] == -1) s.pb('0');
    else s.pb('1');
    printf("%s\n", s.c_str());
        
    
    
}