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
vvi g;
const int A = 300500;
int parent[A];
int rk[A];
int s[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
    s[v] = 1;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
        s[a] += s[b];
    }
}
vi vis;
vi cnt(2,0);
int can;
vi col;

void dfs(int v, int ccol) {
    cnt[ccol]+=s[v];
    col[v] = ccol;
    vis[v] = 1;
    for(auto u : g[v]) {
        if(vis[u]) {
            if(col[u] == col[v]) {
                can = 0;
                return;
            }
        }
        else {
            dfs(u, 1-ccol);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    char c[100];
    while(t-- ) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        forn(i,0,n) make_set(i);
        g.clear();
        g.resize(n);
        vpi e;
        forn(i,0,m) {
            int u,v;
            scanf("%d %d %s", &u, &v, c);
            u--; v--;
            if(c[0] == 'c') union_sets(u, v);
            else e.pb(mp(u,v));
        }
        vis = vi (n,1);
        col.resize(n);
        forn(i,0,n) if(find_set(i) == i) vis[i] = 0;
        for(auto x : e) {
            g[find_set(x.first)].pb(find_set(x.second));
            g[find_set(x.second)].pb(find_set(x.first));
        }
        cnt[0] = 0;
        cnt[1] = 0;
        can = 1;
        int ans = 0;
        forn(i,0,n) {
            if(vis[i] == 0) {
                cnt[0] = 0;
                cnt[1] = 0;
                dfs(i, 0);
                ans += max(cnt[0], cnt[1]);
            }
        }
        if(can == 0) printf("-1\n");
        else printf("%d\n", ans);
        
        
        
        
    }
    
    
}