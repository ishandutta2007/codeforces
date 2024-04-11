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
int d[11][100];
clock_t start_clock;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    start_clock = clock();
    int n,k;
    scanf("%d %d", &n, &k);
    vvi a(n, vi(n));
    forn(i,0,n) forn(j,0,n) scanf("%d", &a[i][j]);
    int ans = 2e9;
    forn(it,0,14000) {
        if (double(clock() - start_clock) / CLOCKS_PER_SEC > 2.6) break;
        forn(i,0,k+1) forn(j,0,n) d[i][j] = 2e9;
        d[0][0] = 0;
        vvi l(2);
        l[0].pb(0);
        forn(i,1,n) l[gen()%2].pb(i);
        if(l[1].empty()) continue;
        forn(s,1,k+1) {
            for(auto v : l[s%2]) for(auto u : l[1-s%2]) {
                d[s][v] = min(d[s][v], d[s-1][u] + a[u][v]);
            }
        }
        ans = min(ans, d[k][0]);
    }
    cout<<ans;
    
    
    
}