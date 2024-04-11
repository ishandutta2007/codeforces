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
const int MAXN = 200000;
set<pi> lst[MAXN];
int parent[MAXN];
vvi tear;
vi parto;
vi p;

void make_set (int v) {
    lst[v] = set<pi> ();
    lst[v].insert(mp(p[v],v));
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b, int tear_log = -1) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        for(auto v : lst[b]) {
            parent[v.second] = a;
            lst[a].insert(v);
            if(tear_log != -1) tear[tear_log].pb(v.second);
        }
        lst[b].clear();
        if(tear_log != -1) parto[tear_log] = b;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);
    p.resize(n);
    forn(i,0,n) scanf("%d", &p[i]);
    vi u(m), v(m);
    forn(i,0,m) {
        scanf("%d %d", &u[i], &v[i]);
        u[i]--; v[i]--;
    }
    vi tk(m,1);
    vi tp(q), a(q);
    forn(i,0,q) {
        scanf("%d %d", &tp[i], &a[i]);
        a[i]--;
        if(tp[i]==2) tk[a[i]] = 0;
    }
    forn(i,0,n) make_set(i);
    forn(i,0,m) if(tk[i]) union_sets(u[i], v[i]);
    tear.resize(q);
    parto.resize(q);
    for(int i = q-1; i>=0; i--) {
        if(tp[i] == 2) {
            union_sets(u[a[i]], v[a[i]], i);
        }
    }
    forn(i,0,q) {
        if(tp[i] == 1) {
            int v = parent[a[i]];
            auto pt = lst[v].end();
            pt--;
            auto x = *pt;
            int u = x.second;
            printf("%d\n", x.first);
            lst[v].erase(pt);
            p[u] = 0;
            lst[v].insert(mp(0,u));
        }
        else if (tear[i].size() > 0) {
            int nv = parto[i];
            int ov = parent[nv];
            for(auto v : tear[i]) {
                parent[v] = nv;
                lst[ov].erase(mp(p[v], v));
                lst[nv].insert(mp(p[v], v));
            }
        }
    }
    
}