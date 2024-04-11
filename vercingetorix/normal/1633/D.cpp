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
const int A = 1001;
int d[A];

const int B = A*13;int e[B];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    const int INF = 1e9;
    forn(i,0,A) d[i] = INF;
    d[1] = 0;
    forn(s,1,A) {
        forn(x,1,s+1) if(s + s/x < A) d[s+s/x] = min(d[s+s/x], d[s]+1);
    }
//    forn(i,1,A) cout<<i<<' '<<d[i]<<'\n';
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,k;
        scanf("%d %d", &n, &k);
        readv(b,n);
        readv(c,n);
        forn(i,0,B) e[i] = 0;
        k = min(k, B-1);
        forn(i,0,n) {
            int cur = d[b[i]];
            for(int was = k-cur; was >= 0; was--) {
                e[was + cur] = max(e[was+cur], e[was] + c[i]);
            }
        }
        int ans = 0;
        forn(i,0,k+1) ans = max(ans, e[i]);
        printf("%d\n", ans);
    }
    
    
}