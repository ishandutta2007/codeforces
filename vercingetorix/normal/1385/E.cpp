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
const int MAXN = 200500;
int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> ans;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ans.begin(), ans.end());
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int m;
        vpi e;
        scanf("%d %d", &n, &m);
        forn(i,0,n) g[i].clear();
        forn(i,0,m) {
            int t,u,v;
            scanf("%d %d %d", &t, &u, &v);
            u--; v--;
            if(t == 1) g[u].pb(v);
            else e.pb(mp(u,v));
        }
        ans.clear();
        topological_sort();
        vi ord(n);
        forn(i,0,n) ord[ans[i]] = i;
        int can = 1;
        forn(i,0,n) for(auto u : g[i]) if(ord[u] < ord[i]) can =0 ;
        if(can == 0) printf("NO\n");
        else {
            printf("YES\n");
            forn(i,0,n) for(auto u : g[i]) printf("%d %d\n", i+1, u+1);
            for(auto x : e) {
                int u = x.first;
                int v = x.second;
                if(ord[u] > ord[v]) swap(u,v);
                printf("%d %d\n", u+1, v+1);
            }
        }
        
    }
    
    
}