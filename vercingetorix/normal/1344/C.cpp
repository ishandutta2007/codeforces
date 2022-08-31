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
int parent[MAXN];
int rk[MAXN];
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
int n;
vector<int> g[MAXN];
vector<int> grev[MAXN];
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

vi lm1;
vi lm2;

void dfs1(int v, int cur) {
    if(lm1[v] <= cur) return;
    lm1[v] = cur;
    for(auto u : g[v]) dfs1(u,cur);
}

void dfs2(int v, int cur) {
    if(lm2[v] <= cur) return;
    lm2[v] = cur;
    for(auto u : grev[v]) dfs2(u,cur);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d", &n, &m);
    forn(i,0,n) make_set(i);
    vi cnt(n,0);
    string res(n, 'A');
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].pb(v);
        grev[v].pb(u);
        union_sets(u, v);
//        res[max(u,v)] = 'E';
    }
    forn(i,0,n) cnt[find_set(i)]++;
    topological_sort();
    vi w(n);
    forn(i,0,n) w[ans[i]] = i;
    forn(v,0,n) {
        for(auto u : g[v]) {
            if(w[u] < w[v]) {
                cout<<-1;
                return 0;
            }
        }
    }
    int INF = n+2;
    lm1 = vi(n,INF);
    lm2 = vi(n,INF);
    forn(i,0,n) {
        if(lm1[i] == INF) dfs1(i, i);
        if(lm2[i] == INF) dfs2(i, i);
    }
//    string res;
//    reverse(all(ans));
    int acnt  = 0;
    forn(i,0,n) {
//        if(res[i] == 'A') acnt++;
        if(lm1[i] == i && lm2[i] == i) acnt++;
        else res[i] = 'E';
    }
    printf("%d\n", acnt);
    printf("%s", res.c_str());
}