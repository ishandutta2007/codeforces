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
const int A = 200000;
int par[18][A];
ll s1[18][A];
ll s0[18][A];
vi ch[18][A];
int lvl[A];

int lca(int a, int b) {
    for(int i = 17; i >= 0; i--) {
        if(lvl[b]-lvl[a] >= 1<<i) b=par[i][b];
        if(lvl[a]-lvl[b] >= 1<<i) a=par[i][a];
    }
    if(a==b) return a;
    for(int i = 17; i >= 0; i--) {
        if(par[i][a] != par[i][b]) {
            a=par[i][a];
            b=par[i][b];
        }
    }
    return par[0][a];
}

vi q[A];
vi qa,qb,qc;

void dfs(int v) {
    for(auto u : ch[1][v]) {
        dfs(u);
        s0[0][v] += s1[0][u];
    }
    for(auto ind : q[v]) {
        int a = qa[ind];
        int b = qb[ind];
        int c = qc[ind];
        ll cand = c + s0[0][v];
        for(int i = 17; i>=0; i--) {
            if(lvl[a] - lvl[v] >= (1<<i)) {
                cand += s0[i][a] - s1[i][a];
                a = par[i][a];
            }
            if(lvl[b] - lvl[v] >=  (1<<i)) {
                cand += s0[i][b] - s1[i][b];
                b = par[i][b];
            }
        }
        s1[0][v] = max(s1[0][v], cand);
    }
    
    s1[0][v] = max(s1[0][v], s0[0][v]);
    forn(l,1,18) {
        for(auto u : ch[l][v]) {
            s1[l][u] = s1[l-1][u] + s1[l-1][par[l-1][u]];
            s0[l][u] = s0[l-1][u] + s0[l-1][par[l-1][u]];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    read(n);
    read(m);
    qa.resize(m);
    qb.resize(m);
    qc.resize(m);
    par[0][0] = 0;
    lvl[0] = 0;
    forn(i,1,n) {
        scanf("%d", &par[0][i]);
        par[0][i]--;
        ch[1][par[0][i]].pb(i);
        lvl[i] = 1+lvl[par[0][i]];
    }
    
    forn(l,1,18) forn(i,0,n) {
        par[l][i] = par[l-1][par[l-1][i]];
        if(l>1) {
            for(auto x : ch[l-1][i]) {
                for(auto u : ch[l-1][x]) for(auto lol : ch[1][u]) ch[l][i].pb(lol);
            }
        }
    }
    forn(i,0,m) {
        scanf("%d %d %d", &qa[i], &qb[i], &qc[i]);
        qa[i]--; qb[i]--;
        q[lca(qa[i], qb[i])].pb(i);
    }
    dfs(0);
    printf("%lld\n", s1[0][0]);
    
    
}