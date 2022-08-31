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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    int t;
//    read(t);
//    forn(ifa,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        vvi g(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u,&v);
        u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    readv(t,n);
    forn(i,0,n) t[i]--;
    vpi e;
    forn(i,0,n) e.pb(mp(t[i], i));
    srt(e);
    vi nb(n, 0);
    int can = 1;
    forn(i,0,n) {
        for(auto u : g[i]) {
            nb[t[u]] = 1;
        }
        if(nb[t[i]]) {
            can = 0;
        }
        forn(j,0,t[i]) if(nb[j] == 0) {
            can = 0;
            break;
        }
        for(auto u : g[i]) {
            nb[t[u]] = 0;
        }
    }
    if(can ==0) printf("-1\n");
    else {
        for(auto x : e) printf("%d ", x.second+1);
    }
        
//    }
    
    
}