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
int k,n;
vvpi g;
const int A = 300500;
int ansv[A];
int anse[A];
int pt;

void dfs(int v, int p, int odd) {
    for(auto u : g[v]) {
        if(u.first == p) continue;
        if(odd) {
            anse[u.second] = n + pt;
            ansv[u.first] = pt;
        }
        else {
            anse[u.second] = pt;
            ansv[u.first] = n + pt;
        }
        pt++;
        dfs(u.first, v, odd^1);
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        read(k);
        n = 1<<k;
        g = vvpi(1<<k);
        forn(i,0,(1<<k)-1) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u; --v;
            g[u].pb(mp(v, i));
            g[v].pb(mp(u, i));
        }
        ansv[0] = 1<<k;
        pt = 1;
        dfs(0, 0, 1);
        printf("1\n");
        forn(i,0,n) printf("%d ", ansv[i]);
        printf("\n");
        forn(i,0,n-1) printf("%d ", anse[i]);
        printf("\n");
    }
    
    
}