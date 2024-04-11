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

#define pb push_back
#define mp make_pair
const ll A = 100000;
set<ll> ecode;
vi nb[A];
int n,m;
void add_edge(pi x) {
    int u = x.first;
    int v = x.second;
    if(u > v) {
        nb[v].pb(u);
        nb[u].pb(n+v);
    }
    else {
        nb[u].pb(v);
        nb[v].pb(u+n);
    }
}
int ban[A];
int st[A];
int col[A];
vi nbtr[A];

vector<int> lst[A];
int parent[A];
int res[A];

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
        res[a] = min(res[a], res[b]);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        
    }
}

int root;
void dfs(int v, int p, int s) {
    st[v] = 1;
    for(auto u : nbtr[v]) {
        if(ban[u] || u == p) continue;
        dfs(u,v,s);
        st[v] += st[u];
    }
    if(root == -1 && 2*st[v]>=s) root = v;
}

void gocentr(int v, int cur) {
    dfs(v,-1,0);
    root = -1;
    dfs(v,-1,st[v]);
    col[root] = cur;
    ban[root] = 1;
    for(auto x : nbtr[root]) if(!ban[x]) gocentr(x, cur+1);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &m);
    vi deg(n,0);
    vpi e;
    forn(i,0,m) {
        int a,b;
        scanf("%d %d", &a, &b);
        a--; b--;
        deg[a]++;
        deg[b]++;
        if(a>b) swap(a,b);
        e.pb(mp(a,b));
        ecode.insert(A*a+b);
    }
    set<pi> vd;
    forn(i,0,n) vd.insert(mp(deg[i], i));
    vi l(n), r(n);
    forn(i,0,n) {
        r[i] = (i+1)%n;
        l[(i+1)%n] = i;
    }
    vpi ne;
    forn(i,0,n-3) {
        auto it = vd.begin();
        int u = l[it->second];
        int v = r[it->second];
        ll code = A*u+v;
        if(u>v) code = A*v+u;
        vd.erase(it);
        r[u] = v;
        l[v] = u;
        if(ecode.find(code) == ecode.end()) ne.pb(mp(u,v));
        else {
            vd.erase(mp(deg[u], u));
            vd.erase(mp(deg[v], v));
            deg[u]--;
            deg[v]--;
            vd.insert(mp(deg[u], u));
            vd.insert(mp(deg[v], v));
        }
        
    }
    for(auto x : e) add_edge(x);
    for(auto x : ne) add_edge(x);
    forn(i,0,n) add_edge(mp(i, (i+1)%n));
    forn(i,0,n) sort(all(nb[i]));
    int cnt = 0;
    set<ll> done;
    map<ll, int> triind;
    vll tri;
    map<ll, pi> etopt;
    
    forn(i,0,n) {
        ll a = i;
        int lind;
        forn(j,0,nb[i].size()-1) {
            ll b = nb[i][j]%n;
            ll c = nb[i][j+1]%n;
            vll ver;
            ver.pb(a); ver.pb(b); ver.pb(c);
            sort(all(ver));
            ll val = ver[0]*A*A+ver[1]*A+ver[2];
            if(done.find(val) == done.end()) {
                done.insert(val);
                triind[val] = cnt++;
                tri.pb(val);
            }
            int ind = triind[val];
            if(j > 0 && b<i) {
                nbtr[ind].pb(lind);
                nbtr[lind].pb(ind);
                ll ec = A*i+b;
                if(b<i) ec= A*b+i;
                etopt[ec] = mp(ind, lind);
            }
            lind = ind;
        }
    }
    
    gocentr(0, 1);
    forn(i,0,n-2) {
        make_set(i);
        res[i] = col[i];
    }
    for(auto x : ne) {
        int i = x.first;
        int b = x.second;
        ll ec = A*i+b;
        if(b<i) ec= A*b+i;
        union_sets(etopt[ec].first, etopt[ec].second);
    }
//    return 0;
    vector<pair<vi, int>> ans;
    forn(i,0,n-2) {
        if(!lst[i].empty()) {
            vi av;
            for(auto x : lst[i]) {
                ll u = tri[x];
                forn(j,0,3) {
                    av.pb(u%A);
                    u/=A;
                }
            }
            sort(all(av));
            vi areal;
            forn(j,0,av.size()) if(j==0 || av[j]!=av[j-1]) areal.pb(av[j]);
            sort(all(areal));
            reverse(all(areal));
            ans.pb(mp(areal, res[i]));
        }
    }
    sort(all(ans));
    for(auto x:ans) printf("%d ", x.second);
}