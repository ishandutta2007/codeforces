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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef std::vector<vpll> vvpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 100100;
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

vvi nb;
vi diam;
set<pi> done;
map<pi, double> ans;
vvi dist;
vvpll gdist;
int n,m,q;
int A = 300;

bool big(int v) {
    return lst[v].size() > A;
}

struct b2 {
    int a = 0, b = 0;
    void upd(int c) {
        if(c >= a) {
            b = a;
            a = c;
        }
        else if(c > b) {
            b = c;
        }
    }
    int res() {
        return a + b;
    }
};
vector<b2> w;
vll wtot;
vd ans1,ans2;

void dfsd(int v, int p) {
    for(auto u : nb[v]) {
        if (u == p) continue;
        dfsd(u,v);
//        bd[v] = max(bd[v], 1+bd[u]);
        w[v].upd(1+w[u].a);
    }
}

void dfsu(int v, int p) {
    for(auto u : nb[v]) {
        if (u == p) continue;
        int wd = w[u].a + 1;
        if (wd == w[v].a) w[u].upd(w[v].b+1);
        else w[u].upd(w[v].a+1);
        dfsu(u,v);
    }
    diam[find_set(v)] = max(diam[find_set(v)], w[v].res());
    dist[find_set(v)].pb(w[v].a);
}

void get_dist(int v) {
    dfsd(v, -1);
    dfsu(v, -1);
}

void pre() {
    dist.resize(n);
    ans1.resize(n);
    ans2.resize(n);
    gdist.resize(n);
    diam.resize(n);
    wtot.resize(n);
    w.resize(n);
    forn(i,0,n) if(lst[i].size() > 0) get_dist(i);
    forn(i,0,n) sort(all(dist[i]));
    forn(i,0,n) {
        int last = -1;
        for(auto x : dist[i]) {
            if(x==last) gdist[i].back().second++;
            else {
                last = x;
                gdist[i].pb(mp(last,1));
            }
        }
    }
    forn(v,0,n) for(auto x : gdist[v]) wtot[v] += (x.first+1) * x.second;
    forn(v,0,n) {
        if(gdist[v].size() > 0) {
            ll cnt = dist[v].size();
            ll cmax = gdist[v].back().second;
            ans1[v] = (cnt)*diam[v] + cmax;
            ans1[v] /= cnt;
        }
    }
    
//    forn(i,0,n) if(big(i)) {
//        get_dist(i);
//    }
}

void build(int u, int v) {
    if(dist[u].size() == 1){
        double res = ans1[v];
        done.insert(mp(u,v));
        done.insert(mp(v,u));
        ans[mp(u,v)] = res;
        ans[mp(v,u)] = res;
        return;
    }
    if(dist[v].size() == 1){
        double res = ans1[u];
        done.insert(mp(u,v));
        done.insert(mp(v,u));
        ans[mp(u,v)] = res;
        ans[mp(v,u)] = res;
        return;
    }
//    if(dist[u].size() == 2){
//        double res = ans2[v];
//        done.insert(mp(u,v));
//        done.insert(mp(v,u));
//        ans[mp(u,v)] = res;
//        ans[mp(v,u)] = res;
//        return;
//    }
//    if(dist[v].size() == 2){
//        double res = ans2[u];
//        done.insert(mp(u,v));
//        done.insert(mp(v,u));
//        ans[mp(u,v)] = res;
//        ans[mp(v,u)] = res;
//        return;
//    }
    ll was = max(diam[u], diam[v]);
    int pt = 0;
    if(gdist[u].size() < gdist[v].size()) swap(u,v);
    ll cntless = 0;
    ll cntmore = dist[v].size();
    ll tot = wtot[v];
    ll tres = 0;
    
    for(int i = gdist[u].size() - 1; i >= 0; i--) {
        while(pt < gdist[v].size() && gdist[v][pt].first + 1 + gdist[u][i].first <= was) {
            pll x = gdist[v][pt];
            tot -= (x.first+1) * x.second;
            pt++;
            cntless += x.second;
            cntmore -= x.second;
        }
        tres += (gdist[u][i].first * cntmore + tot + was * cntless) * gdist[u][i].second;
    }
    
    double res = (ld)tres / ((ll) dist[u].size() * (ll) dist[v].size());
    done.insert(mp(u,v));
    done.insert(mp(v,u));
    ans[mp(u,v)] = res;
    ans[mp(v,u)] = res;
}

double get(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u > v) swap(u,v);
    if (u == v) return -1;
    if (done.find(mp(u,v)) != done.end()) return ans[mp(u,v)];
    build(u, v);
    return ans[mp(u,v)];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &m, &q);
    nb.resize(n);
    forn(i,0,n) make_set(i);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].pb(v);
        nb[v].pb(u);
        union_sets(u, v);
    }
    pre();
    forn(i,0,q) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        printf("%.10lf\n", get(u,v));
    }
}