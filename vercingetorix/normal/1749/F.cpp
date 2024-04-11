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
int l;
vector<int> tin, tout;
vi tl,tr;
int timer,timer2;
vector < vector<int> > up;
vvi g;

void dfs1 (int v, int p = 0) {
    tl[v] = timer2++;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs1 (to, v);
    }
    tr[v] = timer2-1;
    tout[v] = ++timer;
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

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    
    T get(int l, int r) {
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};

vector<fenwick<ll>> fen;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    tl.resize(n);
    tr.resize(n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs1 (0, 0);
    forn(i,0,21) fen.emplace_back(n);
    int q;
    read(q);
    while(q--) {
        int tp;
        read(tp);
        if(tp == 1) {
            int v;
            read(v);
            --v;
            ll res = 0;
            forn(i,0,21) {
                res += fen[i].get(tl[v], tr[v]);
                if(v == up[v][0]) break;
                v = up[v][0];
            }
            printf("%lld\n", res);
        }
        else {
            int a,b,k,d;
            scanf("%d %d %d %d", &a, &b, &k, &d);
            --a;
            --b;
            int c = lca(a, b);
            fen[d].modify(tl[a], k);
            fen[d].modify(tl[b], k);
            fen[d].modify(tl[c], -k);
            int pc = up[c][0];
            if(pc != c) fen[d].modify(tl[pc], -k);
            forn(s,0,d) {
                fen[s].modify(tl[c], k);
                if(pc!=c) fen[s].modify(tl[pc], -k);
            }
            forn(s,1,d+1) {
                if(pc == c) break;
                int ppc = up[pc][0];
                forn(to,0,d+1-s) {
                    fen[to].modify(tl[pc], k);
                    if(ppc != pc) fen[to].modify(tl[ppc], -k);
                    if(to > 0) {
                        fen[to-1].modify(tl[c], -k);
                        fen[to-1].modify(tl[pc], k);
                    }
                }
                c = pc;
                pc = ppc;
            }
        }
    }
    
}