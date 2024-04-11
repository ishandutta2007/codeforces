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
vi p;
int n,m;
vi ans;
vi ans1;
void win(int cur) {
    ans.pb(cur);
    while(cur != 0) {
        cur = p[cur];
        ans.pb(cur);
    }
    reverse(all(ans));
    
}

void pr() {
    printf("%d\n", ans.size() - 1);
    for(auto x : ans) printf("%d ", x+1);
    exit(0);
}
const int A = 300500;
int parent[A];
int rk[A];
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
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    vvi g(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    deque<int> q;
    q.pb(0);
    p = vi (n, -1);
    vi d(n,n+14);
    p[0] = 0;
    vi vis;
    d[0] = 0;
    vi can(n,0);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(auto u : g[v]) {
            if(p[u] == -1) {
                p[u] = v;
                d[u] = d[v] + 1;
                q.pb(u);
            }
        }
    }
    if(d[n-1] <= 4) {
        win(n-1);
        pr();
    }
    vi mark(n,0);
    mark[0] = 1;
    for(auto u : g[0]) mark[u] = 1;
    for(auto v : g[0]) {
        for(auto u : g[v]) if(mark[u] == 0) {
            ans.pb(0);
            ans.pb(v);
            ans.pb(u);
            ans.pb(0);
            ans.pb(n-1);
            pr();
        }
    }
    for(auto x : g[0]) make_set(x);
    for(auto v : g[0]) for(auto u : g[v]) if(u!=0) union_sets(u, v);
    vvi ver(n);
    for(auto v : g[0]) ver[find_set(v)].pb(v);
    for(auto v : g[0]) if(!ver[v].empty()) {
        for(auto u : ver[v]) {
            if(g[u].size() != ver[v].size()) {
                mark = vi(n,0);
                mark[u] = 1;
                for(auto z : g[u]) mark[z] = 1;
                for(auto z : g[u]) if(z != 0) for(auto y : g[z]) if(!mark[y]) {
                    ans.pb(0);
                    ans.pb(u);
                    ans.pb(z);
                    ans.pb(y);
                    ans.pb(u);
                    ans.pb(n-1);
                    pr();
                }
            }
        }
    }
//    if(!ans1.empty()) {
//        swap(ans,ans1);
//        pr();
//    }
    printf("-1\n");
    
    
    
    
}