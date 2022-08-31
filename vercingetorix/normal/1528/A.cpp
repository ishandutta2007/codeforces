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
vvi a;
vvi g;

vll go(int v, int p) {
    vvll chr;
    vi ch;
    for(auto u : g[v]) if(u!=p) {
        chr.pb(go(u,v));
        ch.pb(u);
    }
    vll ret(2,0);
    forn(j,0,ch.size()) {
        forn(i,0,2) {
            ll best = 0;
            forn(k,0,2) {
                ll cand = abs(a[i][v] - a[k][ch[j]]) + chr[j][k];
                best = max(cand, best);
            }
            ret[i] += best;
        }
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        a = vvi(2, vi(n));
        forn(i,0,n) scanf("%d %d", &a[0][i], &a[1][i]);
        g = vvi(n);
        forn(i,0,n- 1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        auto x = go(0, -1);
        printf("%lld\n", max(x[0], x[1]));
        
    }
    
}