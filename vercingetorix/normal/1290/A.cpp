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
    int t;
    read(t);
    while(t--) {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);
        readv(a,n);

        vi lc;
        int best = 0;
        forn(l,0,m) {
            int r = m-1-l;
            lc.pb(max(a[l], a[n-1-r]));
        }
        vvi d(m, vi(m));
        forn(i,0,m) d[i][i] = lc[i];
        forn(i,0,m) {
            forn(j,i+1,m) {
                d[i][j] = min(d[i][j-1], lc[j]);
            }
        }
        k = min(k, m-1);
        int l1 = m - 1 - k;
        int ans = 0;
        forn(i,0,m) {
            int r = i + l1;
            if(r < m) ans = max(ans, d[i][r]);
        }
        printf("%d\n", ans);
        
    }
    
    
}