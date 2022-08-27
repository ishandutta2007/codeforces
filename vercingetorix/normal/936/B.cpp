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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vvi e;
vvi erev;
vi vis;

vi v1, v2;
int n,m;
void go(int v) {
    for(auto u : erev[v]) {
        if(v1[v] != -1 && v2[u] == -1) {
            v2[u] = v;
            go(u);
        }
        if(v2[v] != -1 && v1[u] == -1) {
            v1[u] = v;
            go(u);
        }
    }
}

void dfs2(int v) {
    for(auto u : e[v]) {
        if(!vis[u]) {
            vis[u] = 1;
            dfs2(u);
        }
    }
}

vi used;
vector<int> ans;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<e[v].size(); ++i) {
        int to = e[v][i];
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n); read(m);
    e.resize(n);
    erev.resize(n);
    forn(i,0,n) {
        int k;
        read(k);
        e[i].resize(k);
        forn(j,0,k) scanf("%d", &e[i][j]);
        forn(j,0,k) e[i][j]--;
        forn(j,0,k) erev[e[i][j]].pb(i);
    }
    vis = vi(n,0);
    used = vi(n,0);
    v1 = vi(n,-1);
    v2 = vi(n,-1);
    int s;
    
    read(s);
    s--;
    dfs2(s);
    forn(i,0,n) {
        if(e[i].size() == 0) {
            v2[i] = -2;
            go(i);
        }
    }
    if(v1[s] != -1) {
        vi res;
        res.pb(s);
        int cur = v1[s];
        res.pb(cur);
        while(v2[cur] != -2) {
            cur = v2[cur];
            res.pb(cur);
            cur = v1[cur];
            res.pb(cur);
        }
        printf("Win\n");
        for(auto x : res) printf("%d ", x+1);
        exit(0);
    }
    topological_sort();
    vi pos(n);
    forn(i,0,n) pos[ans[i]] = i;
    forn(i,0,n) for(auto j : e[i]) {
        if(vis[i] && vis[j] && pos[i] > pos[j]) {
            printf("Draw\n");
            exit(0);
        }
    }
    printf("Lose\n");
}