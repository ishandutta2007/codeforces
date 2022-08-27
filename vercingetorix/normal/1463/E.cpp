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

vvi g;

int n;
vb used;
vector<int> ts;
vi strong;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ts.push_back (v);
}

void topological_sort() {
    used =vb(n, false);
    ts.clear();
    for(auto i : strong)
        if (!used[i])
            dfs (i);
    reverse (ts.begin(), ts.end());
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int k;
    scanf("%d %d", &n, &k);
    forn(i,0,n) make_set(i);
    readv(p,n);
    forn(i,0,n) p[i]--;
    vi l(k), r(k);
    vi tl, tr;
    forn(i,0,n) {
        tl.pb(i);
        tr.pb(i);
    }
    forn(i,0,k) {
        scanf("%d %d", &l[i], &r[i]);
        l[i]--;
        r[i]--;
        tr[l[i]] = r[i];
        tl[r[i]] = l[i];
        if(find_set(l[i]) == find_set(r[i])) {
            cout<<0;
            exit(0);
        }
        union_sets(l[i], r[i]);
    }
    forn(i,0,n) if(find_set(i) == i) strong.pb(i);
    g.resize(n);
    forn(i,0,n) {
        if(p[i] != -1) {
            int u = find_set(p[i]);
            int v = find_set(i);
            if(u!=v) g[u].pb(v);
        }
    }
    topological_sort();
    vi ford;
    for(auto x : ts) {
        int v = x;
        while(tl[v] != v) v = tl[v];
        ford.pb(v);
        while(tr[v] != v) {
            v = tr[v];
            ford.pb(v);
        }
    }
    vi ord(n,0);
    forn(i,0,ford.size()) {
        ord[ford[i]] = i;
    }
    forn(i,0,n) {
        if(p[i] != -1) {
            if(ord[p[i]] > ord[i]) {
                cout<<0;
                exit(0);
            }
        }
    }
    for(auto x : ford) printf("%d ", x+1);
    
}