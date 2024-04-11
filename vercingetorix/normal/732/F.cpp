#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 400000;
int n,m;
vector<pi> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
vpi e;
vi isb;

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
                isb[g[v][i].second] = 1;
        }
    }
}

void find_bridges() {
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
}

vector<int> lst[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        
    }
}

vi usedor;

void dfs_or(int v, int ind) {
    usedor[v] = 1;
    for(auto u : g[v]) {
        if(find_set(u.first) != ind) continue;
        if(e[u.second].first != v) swap(e[u.second].first, e[u.second].second);
        if(!usedor[u.first]) dfs_or(u.first, ind);
    }
}

void orient(int ind) {
    dfs_or(lst[ind][0], ind);
}

vvpi nb;
vi par;
vi pari;
vi s2;
vi ord;
void dfs2(int v, int p) {
    ord.pb(v);
    for(auto u : nb[v]) {
        if(u.first == p) continue;
        par[u.first] = v;
        pari[u.first] =u.second;
        dfs2(u.first, v);
    }
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &m);
    forn(i,0,n) make_set(i);
    isb = vi(m,0);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x,&y);
        x--;
        y--;
        e.pb(mp(x,y));
        g[x].pb(mp(y,i));
        g[y].pb(mp(x,i));
    }
    usedor = vi(n,0);
    find_bridges();
    forn(i,0,m) {
        if(!isb[i]) union_sets(e[i].first, e[i].second);
    }
    forn(i,0,n) {
        if(lst[i].size() > 1) orient(i);
    }
    vi gtot(n,-1);
    int cur = 0;
    vi s;
    forn(i,0,n) {
        if(lst[i].size() > 0) {
            gtot[i] = cur;
            cur++;
            s.pb(lst[i].size());
        }
    }
    nb.resize(cur);
    par.resize(cur);
    pari.resize(cur);
    
    forn(i,0,m) {
        if (isb[i]) {
            nb[gtot[find_set(e[i].first)]].pb(mp(gtot[find_set(e[i].second)], i));
            nb[gtot[find_set(e[i].second)]].pb(mp(gtot[find_set(e[i].first)], i));
        }
    }
    dfs2(0,-1);
    reverse(all(ord));
    int l = 1;
    int r = n+1;
    while(r>l + 1) {
        int med = (r+l)/2;
        s2 = s;
        bool f= true;
        forn(i,0,ord.size()-1) {
            int x = ord[i];
            if(s2[x] >= med) {
                s2[par[x]] += s2[x];
            }
        }
        if(s2[ord.back()] >= med) l = med;
        else r= med;
    }
    forn(i,0,ord.size()-1) {
        int x = ord[i];
        int ind = pari[x];
        if(s[x] >= l) {
            s[par[x]] += s[x];
            if(gtot[find_set(e[ind].first)] == x) swap(e[ind].first, e[ind].second);
        }
        else {
            if(gtot[find_set(e[ind].first)] != x) swap(e[ind].first, e[ind].second);
        }
    }
    printf("%d\n", l);
    forn(i,0,m) {
        printf("%d %d\n", e[i].first +1, e[i].second+1);
    }
}