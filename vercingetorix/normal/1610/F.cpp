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
#ifdef LOCAL
const int A = 20;
#else
const int A = 300500;
#endif
vpi g[2][A];
int del[2*A];
int ord[2*A];
int vis[A];
vpi e;
vpi from;
vi to;

void go(int v, int w, int side) {
    if(!g[w][v].empty()) {
        int u = g[w][v][0].first;
        if(!vis[u]) {
            vis[u] = 1;
            int en = g[w][v][0].second;
            int sto = side;
            if(en<0) sto^=1;
            ord[abs(en)] = sto;
            go(u, w^1, side);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    e.pb(mp(-1,-1));
    forn(i,1,m+1) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; w--;
        g[w][u].pb(mp(v,i));
        g[w][v].pb(mp(u,-i));
        e.pb(mp(u, v));
    }
    int ans = 0;
    int curm = m+1;
    forn(i,0,n) if(g[0][i].size() % 2 == 1) ans++;
    forn(i,0,n) {
        forn(w,0,2) {
            forn(j,0,g[w][i].size()) {
                if(del[abs(g[w][i][j].second)]) {
                    swap(g[w][i][j], g[w][i].back());
                    g[w][i].pop_back();
                    j--;
                }
            }
            while(g[w][i].size() > 1) {
                auto e1 = g[w][i].back();
                g[w][i].pop_back();
                auto e2 = g[w][i].back();
                g[w][i].pop_back();
                from.pb(mp(-e1.second, e2.second));
                del[abs(e1.second)] = 1;
                del[abs(e2.second)] = 1;
                to.pb(curm);
                if(e1.first != e2.first) {
                    g[w][e1.first].pb(mp(e2.first, curm));
                    g[w][e2.first].pb(mp(e1.first, -curm));
                }
                else ord[curm] = 0;
                curm++;
            }
        }
    }
    forn(i,0,n) {
        forn(w,0,2) {
            forn(j,0,g[w][i].size()) {
                if(del[abs(g[w][i][j].second)]) {
                    swap(g[w][i][j], g[w][i].back());
                    g[w][i].pop_back();
                    j--;
                }
            }
        }
    }
    forn(i,0,n) if(vis[i] == 0) {
        go(i,0,0);
        go(i,1,1);
    }
    while(!to.empty()) {
        int side = ord[to.back()];
        to.pop_back();
        pi fr = from.back();
        from.pop_back();
        if(fr.first < 0) ord[-fr.first] = side^1;
        else ord[fr.first] = side;
        if(fr.second < 0) ord[-fr.second] = side^1;
        else ord[fr.second] = side;
    }
    printf("%d\n", ans);
    forn(i,1,m+1) printf("%d", ord[i]+1);
    
    
    
}