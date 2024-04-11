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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int N = 1000500;
int n;
vvi g;
int vres[N];
int aval[N];
int tp[N];
int p1[N];
int p2[N];

bool used[N];
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


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d\n", &n);
    g.resize(n);
    char c;
    forn(i,0,n) {
        scanf("%c", &c);
        int u,v;
        if(c == 'A') {
            scanf("%c%c %d %d\n", &c, &c, &u, &v);
            tp[i] = 0;
            u--; v--;
            g[u].pb(i);
            g[v].pb(i);
            p1[i] = u;
            p2[i] = v;
        }
        else if(c=='I') {
            scanf("%c %d\n", &c, &u);
            tp[i] = 4;
            vres[i] = u;
        }
        else if(c=='X') {
            scanf("%c%c %d %d\n", &c, &c, &u, &v);
            tp[i] = 2;
            u--; v--;
            g[u].pb(i);
            g[v].pb(i);
            p1[i] = u;
            p2[i] = v;
        }
        else if(c=='O') {
            scanf("%c %d %d\n", &c, &u, &v);
            tp[i] = 1;
            u--; v--;
            g[u].pb(i);
            g[v].pb(i);
            p1[i] = u;
            p2[i] = v;
        }
        else if(c=='N') {
            scanf("%c%c %d\n", &c, &c, &u);
            tp[i] = 3;
            u--;
            g[u].pb(i);;
            p1[i] = u;
        }
    }
    topological_sort();
    forn(ind, 0, n) {
        int i = ts[ind];
        if(tp[i] == 0) vres[i] = vres[p1[i]]&vres[p2[i]];
        else if(tp[i] == 1) vres[i] = vres[p1[i]]|vres[p2[i]];
        else if(tp[i] == 2) vres[i] = vres[p1[i]]^vres[p2[i]];
        else if(tp[i] == 3) vres[i] = !vres[p1[i]];
    }
    int ans = vres[0];
    aval[0] = 1;
    for(int ind = n-1; ind >= 0; ind--) {
        int i = ts[ind];
        if(aval[i]) {
            if(tp[i] == 0) {
                if(vres[i] == 1) {
                    aval[p1[i]] = 1;
                    aval[p2[i]] = 1;
                }
                else {
                    if(vres[p1[i]] == 1) aval[p2[i]] = 1;
                    if(vres[p2[i]] == 1) aval[p1[i]] = 1;
                }
            }
            if(tp[i] == 1) {
                if(vres[i] == 0) {
                    aval[p1[i]] = 1;
                    aval[p2[i]] = 1;
                }
                else {
                    if(vres[p1[i]] == 0) aval[p2[i]] = 1;
                    if(vres[p2[i]] == 0) aval[p1[i]] = 1;
                }
            }
            if(tp[i] == 2) {
                aval[p1[i]] = 1;
                aval[p2[i]] = 1;
            }
            if(tp[i] == 3) aval[p1[i]] = 1;
        }
    }
    forn(i,0,n) if(tp[i] == 4) printf("%d", aval[i]^ans);
    
    
}