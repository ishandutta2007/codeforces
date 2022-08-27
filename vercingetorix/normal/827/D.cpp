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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int MAXN = 200000;
vector<int> lst[MAXN];
int parent[MAXN];
int curv;
set<pi> e[MAXN];
vi ans;
vi u,v;
vi c;

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
        for(auto edge : e[b]) {
            int to = edge.first;
            int ind = edge.second;
            e[to].erase(mp(b, ind));
            if (to == a) {
                ans[ind] = curv - 1;
            }
            else {
                e[to].insert(mp(a,ind));
                e[a].insert(mp(to, ind));
            }
        }
        e[b].clear();
    }
}

vi par[18];
vi lev;
vvpi nb;
void dfs(int v, int p) {
    par[0][v] = p;
    for(auto u : nb[v]) {
        if (u.first == p) continue;
        lev[u.first] = lev[v] + 1;
        dfs(u.first, v);
    }
}
vi d2(1,1);
int lca(int a, int b) {
    for(int i = 17; i >= 0; i--) {
        if(lev[a] >= lev[b] + d2[i]) a=par[i][a];
        if(lev[b] >= lev[a] + d2[i]) b=par[i][b];
    }
    if (a==b) return a;
    for(int i = 17; i >= 0; i--) {
        if(par[i][a] != par[i][b]) {
            a=par[i][a];
            b=par[i][b];
        }
    }
    return par[0][a];
}

multiset<int> inc[MAXN];
multiset<int> decr[MAXN];

multiset<int> dfsans(int v, int p) {
    multiset<int> res;
    for(auto u : nb[v]) {
        if (u.first == p) continue;
        multiset<int> cand = dfsans(u.first, v);
        if(!cand.empty()) ans[u.second] = min(ans[u.second], *cand.begin() - 1);
        if(cand.size() > res.size()) swap(cand, res);
        for (auto x : cand) res.insert(x);
    }
    for(auto x : decr[v]) res.erase(res.find(x));
    for(auto x : inc[v]) res.insert(x);
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,20) d2.pb(d2.back()*2);
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,n) make_set(i);
    c.resize(m);
    u.resize(m);
    v.resize(m);
    vi used(m,0);
    vpi ev;
    const int INF = 2e9;
    ans = vi(m,INF);
    nb.resize(n);
    forn(i,0,m) {
        scanf("%d %d %d", &u[i], &v[i], &c[i]);
        u[i]--; v[i]--;
        e[u[i]].insert(mp(v[i], i));
        e[v[i]].insert(mp(u[i], i));
        ev.pb(mp(c[i], i));

    }
    sort(all(ev));
    vi ost;
    for(auto x : ev) {
        curv = x.first;
        int a = u[x.second];
        int b = v[x.second];
        a = find_set(a);
        b = find_set(b);
        if (a == b) continue;
        ost.pb(x.second);
        used[x.second] = 1;
        e[a].erase(mp(b, x.second));
        e[b].erase(mp(a, x.second));
        union_sets(a, b);
        
    }
    forn(i,0,18) par[i].resize(n);
    for(auto i : ost) {
        nb[u[i]].pb(mp(v[i], i));
        nb[v[i]].pb(mp(u[i], i));
    }
    lev=vi(n,0);
    lev[0] = 0;
    dfs(0,0);
    forn(l,1,18) forn(i,0,n) {
        par[l][i] = par[l-1][par[l-1][i]];
    }
    forn(i,0,m) {
        if(used[i]) continue;
        int a = u[i];
        int b = v[i];
        int ab = lca(a,b);
        if(a!=ab) {
            inc[a].insert(c[i]);
            decr[ab].insert(c[i]);
        }
        if(b!=ab) {
            inc[b].insert(c[i]);
            decr[ab].insert(c[i]);
        }
    }
    dfsans(0, -1);
    
    
    
    forn(i,0,m) if(ans[i] == INF) ans[i] = -1;
    for(auto x : ans) printf("%d ", x);
}