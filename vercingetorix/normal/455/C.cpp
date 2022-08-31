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
const int A = 300500;
int parent[A];
int rk[A];
int ans[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
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
        ans[a] = max({(ans[a] + 1)/2 + 1 + (ans[b] + 1) / 2, ans[a], ans[b]});
    }
}

vi g[A];
int vis[A];

int curlen;

int dfs(int v, int p) {
    vi l2(2,0);
    for(auto u : g[v]) {
        if(u==p) continue;
        int cur = dfs(u, v);
        if(cur >= l2[0]) {
            l2[1] = l2[0];
            l2[0] = cur;
        }
        else if(cur >= l2[1]) l2[1] = cur;
    }
    curlen = max(curlen, l2[0] + l2[1]);
    return l2[0] + 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);
    forn(i,0,n) make_set(i);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
        union_sets(u, v);
    }
    forn(i,0,n) if(i == find_set(i)) {
        curlen = 0;
        dfs(i,i);
        ans[i] = curlen;
    }
    while(q--) {
        int tp;
        scanf("%d", &tp);
        if(tp == 1) {
            int v;
            scanf("%d", &v);
            printf("%d\n", ans[find_set(v-1)]);
        }
        else {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            union_sets(u, v);
        }
    }
    
}