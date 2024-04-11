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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
const int MAXN = 100000;
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

const int A = 100000;
int par[17][A];
vi ch[A];
int lvl[A];
int tin[A];
int tout[A];
int t[A];
int curt = 0;

void dfsl(int v, int l) {
    lvl[v] = l;
    tin[v] = curt++;
    for(auto u : ch[v]) {
        dfsl(u, l+1);
    }
    tout[v] = curt++;
}

int lca(int a, int b) {
    for(int i = 16; i>=0; i--) {
        if(lvl[a]-lvl[b] >= 1<<i) a = par[i][a];
        if(lvl[b]-lvl[a] >= 1<<i) b = par[i][b];
    }
    if(a==b) return a;
    for(int i = 16; i>=0; i--) {
        if(par[i][a] != par[i][b]) {
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}

int p0[A];
int p1[A];

void dfs(int v) {
    for(auto u : ch[v]) {
        if(t[u] == 0) p0[u] = p0[v];
        else p1[u] = p1[v];
        dfs(u);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    forn(i,0,n) p0[i] = i;
    forn(i,0,n) p1[i] = i;
    forn(i,0,n) make_set(i);
    forn(i,0,n) {
        scanf("%d %d", &par[0][i], &t[i]);
        if(par[0][i] != -1) par[0][i] --;
        if(par[0][i] != -1) {
            union_sets(i, par[0][i]);
            ch[par[0][i]].pb(i);
        }
        else par[0][i] = i;
    }
    forn(l,1,17) forn(i,0,n) par[l][i] = par[l-1][par[l-1][i]];
    int q;
    forn(i,0,n) if(par[0][i] == i) dfsl(i,0);
    forn(i,0,n) if(par[0][i] == i) dfs(i);
    scanf("%d", &q);
    forn(i,0,q) {
        int qt,u,v;
        scanf("%d %d %d", &qt, &u, &v); u--; v--;
        if(find_set(u) != find_set(v) || u == v) {
            printf("NO\n");
            continue;
        }
        if(qt == 1) {
            if(tin[v] >= tin[u] && tout[v] <= tout[u] && lvl[p0[v]] <= lvl[u]) printf("YES\n");
            else printf("NO\n");
        }
        else {
            if(tin[v] >= tin[u] && tout[v] <= tout[u] && lvl[p1[v]] <= lvl[u]) printf("YES\n");
            else {
                int c = lca(u,v);
                if(c==u || c==v) printf("NO\n");
                else if(lvl[p0[u]] <= lvl[c] && lvl[p1[v]] <= lvl[c]) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    
}