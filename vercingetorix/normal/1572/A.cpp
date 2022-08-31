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

int n; //  
vvi g;
vb used;
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
    while(t--) {
        scanf("%d", &n);
        g.clear();
        g.resize(n);
        used = vb(n);
        ans.clear();
        vvi gr(n);
        forn(i,0,n) {
            int k;
            scanf("%d", &k);
            forn(j,0,k) {
                int nd;
                scanf("%d", &nd);
                nd--;
                g[nd].pb(i);
                gr[i].pb(nd);
            }
        }
        topological_sort();
        vi pos(n);
        forn(i,0,n) pos[ans[i]] = i;
        int can = 1;
        forn(i,0,n) {
            for(auto u : g[i]) {
                if(pos[u] < pos[i]) {
                    can = 0;
                }
            }
        }
        if(can == 0) {
            printf("-1\n");
            continue;
        }
        vi d(n, 0);
        int res = 0;
        forn(i,0,n) {
            d[ans[i]] = 1;
            for(auto u : gr[ans[i]]) {
                if(u < ans[i]) d[ans[i]] = max(d[ans[i]], d[u]);
                else d[ans[i]] = max(d[ans[i]], d[u] + 1);
            }
            res = max(res, d[ans[i]]);
        }
        printf("%d\n", res);
    }
    
    
}