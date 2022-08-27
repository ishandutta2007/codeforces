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
vvi g;

int n, l;
vi tin, tout;
int timer;
vector < vector<int> > up;
vi lev;

void dfs (int v, int p, int curl) {
    lev[v] = curl;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v, curl+1);
    }
    tout[v] = ++timer;
}

vi maj;
vi st;
int go(int v, int p) {
    st[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        st[v] += go(u,v);
    }
    for(auto u : g[v]) {
        if(st[u]*2 >= n) maj[v] = u;
    }
    return st[v];
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int dist(int a, int b) {
    int c = lca(a,b);
    return lev[a]+lev[b]-2*lev[c];
}

vi getpath(int a, int b) {
    int c  = lca(a,b);
    vi ret;
    vi rev;
    while(a!=c) {
        ret.pb(a);
        a = up[a][0];
    }
    while(b!=c) {
        rev.pb(b);
        b = up[b][0];
    }
    reverse(all(rev));
    ret.pb(c);
    for(auto x : rev) ret.pb(x);
    return ret;
}

ll todist(vi & x) {
    ll ret = 0;
    forn(i,0,n) if(x[i] > i) ret += dist(x[i], i);
    return ret;
}

vpi prmin;
int greed(int v, int p) {
    vi stray;
    for(auto u : g[v]) {
        if(u==p) continue;
        int ret = greed(u, v);
        if(ret != -1) stray.pb(ret);
    }
    stray.pb(v);
    while(stray.size() >= 2) {
        int p = stray.size();
        prmin.pb(mp(stray[p-1], stray[p-2]));
        stray.pop_back();
        stray.pop_back();
    }
    int ret = -1;
    if(stray.size() == 1) ret = stray[0];
    return ret;
}
vi tomin;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    l = 1;
    while ((1<<l) <= n)  ++l;
    tin.resize (n),  tout.resize (n),  up.resize (n);
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    lev.resize(n);
    st = vi(n,0);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n==2) {
        if(k!=1) cout<<"NO\n";
        else {
            cout<<"YES\n";
            cout<<"1 2\n";
        }
        exit(0);
    }
    forn(i,0,n) maj.pb(i);
    go(0,0);
    int root = 0;
    while(maj[root] != root) root = maj[root];
    
    dfs (root,root,0);
    ll mx = 0;
    forn(i,0,n) mx += lev[i];
    vpi ord;
    forn(i,0,n) ord.pb(mp(tin[i],i));
    sort(all(ord));
    vpi prmax;
    forn(i,0,n/2) prmax.pb(mp(ord[i].second, ord[i+n/2].second));
    greed(root, root);
    ll mn = 0;
    forn(i,0,n/2) {
        mn += dist(prmin[i].first, prmin[i].second);
    }
//    cout<<"AFFA";
    
    vi tomax(n);
    tomin.resize(n);
    forn(i,0,n/2) {
        tomin[prmin[i].first] = prmin[i].second;
        tomin[prmin[i].second] = prmin[i].first;
        tomax[prmax[i].first] = prmax[i].second;
        tomax[prmax[i].second] = prmax[i].first;
    }
    if(k%2!=mn%2 || k < mn || k > mx) {
        cout<<"NO\n";
        exit(0);
    }
    int eq = 0;
    while(1) {
        if(eq == n) break;
        if(tomin[eq] == tomax[eq]) {
            eq++;
            continue;
        }
//        vi tomid = tomin;
        int cp = tomin[tomax[eq]];
        int neq = tomin[eq];
        int xeq = tomax[eq];
        if(mn == k) break;
        swap(tomin[cp], tomin[eq]);
        swap(tomin[xeq], tomin[neq]);
        ll md = mn - dist(eq, neq) - dist(xeq, cp) + dist(eq,xeq) + dist(cp, neq);
        if(md == k) break;
        else if (md < k) {
            eq++;
            mn = md;
            continue;
        }
        else {
            swap(tomin[cp], tomin[eq]);
            swap(tomin[xeq], tomin[neq]);
            vi path = getpath(eq, cp);
            for(auto x : path) {
                if(x==tomin[eq]) {
                    eq = tomin[eq];
                    path = getpath(eq, cp);
                    break;
                }
            }
            int q = path.size();
            forn(i,0,q-1) {
                int a = path[i];
                int b = path[i+1];
                int ca = tomin[a];
                int cb = tomin[b];
                swap(tomin[a], tomin[b]);
                swap(tomin[ca], tomin[cb]);
                if(ca!=b)mn += dist(a,cb) + dist(b,ca) - dist(a,ca) - dist(b,cb);
                if(mn == k) {
                    printf("YES\n");
                    forn(i,0,n) {
                        if(tomin[i] > i) printf("%d %d\n", i+1, tomin[i]+1);
                    }
                    exit(0);
                }
            }
            for(int i = q-3;i>=0;i--) {
                int a = path[i];
                int b = path[i+1];
                int ca = tomin[a];
                int cb = tomin[b];
                swap(tomin[a], tomin[b]);
                swap(tomin[ca], tomin[cb]);
                if(ca!=b)mn += dist(a,cb) + dist(b,ca) - dist(a,ca) - dist(b,cb);
                if(mn == k) {
                    printf("YES\n");
                    forn(i,0,n) {
                        if(tomin[i] > i) printf("%d %d\n", i+1, tomin[i]+1);
                    }
                    exit(0);
                }
            }
            printf("NO\n");
            exit(0);
        }
    }
    printf("YES\n");
    forn(i,0,n) {
        if(tomin[i] > i) printf("%d %d\n", i+1, tomin[i]+1);
    }
    
    
}