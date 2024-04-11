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
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}
int n;
vvi g;
vb used;
vector<int> ts;

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
    for (int i=0; i<n; ++i)
        used[i] = false;
    ts.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ts.begin(), ts.end());
}
ll d[600];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,p;
    scanf("%d %d %d", &n, &m, &p);
    g.resize(n);
    used.resize(n);
    vi in(n,0);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        in[v]++;
    }
    vi s,t;
    forn(i,0,n) if(in[i] == 0) s.pb(i);
    forn(i,0,n) if(g[i].size() == 0) t.pb(i);
    topological_sort();
    int k = s.size();
    vvll a(k, vll(k, 0));
    forn(it,0,k) {
        int x = s[it];
        forn(i,0,n) d[i] = 0;
        d[x] = 1;
        for(auto u : ts) {
            for(auto v : g[u]) {
                d[v] += d[u];
                if(d[v] >= p) d[v]-=p;
            }
        }
        forn(j,0,k) a[it][j] = d[t[j]];
    }
    ll det = 1;
    n =k;
    for (int i=0; i<n; ++i) {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (a[j][i] > a[k][i])
                k = j;
        if (a[k][i] == 0) {
            det = 0;
            break;
        }
        swap (a[i], a[k]);
        if (i != k)
            det = (p-det)%p;
        det = det*a[i][i]%p;
        ll inv = invmod(a[i][i], p);
        for (int j=i+1; j<n; ++j)
            a[i][j] = a[i][j]*inv%p;
        for (int j=0; j<n; ++j)
            if (j != i && a[j][i] != 0)
                for (int k=i+1; k<n; ++k) {
                    a[j][k] = (a[j][k] + p - a[i][k]*a[j][i]%p)%p;
                }
    }
    cout<<det;
    
}