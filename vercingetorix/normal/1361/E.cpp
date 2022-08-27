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
vvi g;
const int A = 100500;
int tl[A];
int tr[A];
int timer;
int vis[A];
int par[A];
void dfslr(int v) {
    vis[v] = 1;
    tl[v] = timer++;
    for(auto u : g[v]) {
        if(vis[u] == 0) {
            par[u] = v;
            dfslr(u);
        }
    }
    tr[v] = timer-1;
}

vi ans;
vvi ch;
int add[A];
int dead[A];
int up = 0;

//void dfs1(int v) {
//    for(auto u : ch[v]) {
//        dfs1(u);
//    }
//    for(auto u : g[v]) if(par[u] != v) {
//        up++;
//        add[u]--;
//    }
//    up += add[v];
//    if(up > 1) dead[v] = 1;
//}
//
vi ord;
void dfs2(int v) {
    ord.pb(v);
    for(auto u : ch[v]) {
        dfs2(u);
    }
}

//vvi gr;

//void dfs2(int v) {
//    dead[v] = 1;
//    for(auto u : gr[v]) {
//        if(dead[u] == 0) dfs2(u);
//    }
//}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        g.clear();
        g.resize(n);
        ch.clear();
        ch.resize(n);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            --u; --v;
            g[u].pb(v);
        }
        vi ver;
        forn(i,0,n) ver.pb(i);
        shuffle(all(ver), gen);
        int root = -1;
        forn(i,0,min(30, n)) {
            int candroot = ver[i];
            timer = 0;
            forn(j,0,n) vis[j] = 0;
            par[candroot] = candroot;
            dfslr(candroot);
            if(timer != n) continue;
            int bad = 0;
            forn(u,0,n) for(auto v : g[u]) {
                if((par[v] == u) || (tl[u] >= tl[v] && tr[u] <= tr[v])) {
                    continue;
                }
                else {
                    bad = 1;
                    break;
                }
            }
            if(bad == 0) {
                root = candroot;
                break;
            }
        }
        if(root == -1) {
            printf("-1\n");
            continue;
        }
        forn(i,0,n) if(i != root) ch[par[i]].pb(i);
        forn(i,0,n) add[i] = 0;
        forn(i,0,n) dead[i] = 0;
        fenwick<int> fen(n);
        fenwick<ll> fen2(n);
        forn(u,0,n) for(auto v : g[u]) if(par[v] != u) {
            fen.modify(tl[u], 1);
            fen.modify(tl[v], -1);
            fen2.modify(tl[u], v);
            fen2.modify(tl[v], -v);
        }
        ord.clear();
        dfs2(root);
        forn(i,1,n) {
            int v = ord[i];
            if(fen.get(tl[v], tr[v]) != 1) {
                dead[v] = 1;
            }
            else {
                int u = fen2.get(tl[v], tr[v]);
                if(dead[u]) dead[v] = 1;
            }
        }
        ans.clear();
        forn(i,0,n) if(dead[i] == 0) ans.pb(i);
        if(ans.size() * 5 < n) {
            printf("-1\n");
            continue;
        }
        for(auto x : ans) printf("%d ", 1+x);
        printf("\n");
        
        
        
        
    }
    
    
}