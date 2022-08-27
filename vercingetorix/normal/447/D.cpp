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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,p;
    scanf("%d %d %d %d", &n, &m, &k, &p);
    vvi a(n, vi(m));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
    multiset<ll> best;
    forn(i,0,n) {
        ll sum = 0;
        forn(j,0,m) sum+=a[i][j];
        best.insert(-sum);
    }
    vll r(k+1,0);
    forn(i,1,k+1) {
        auto it = best.begin();
        r[i] = r[i-1] - *it;
        ll add = *it + p*m;
        best.erase(it);
        best.insert(add);
    }
    best.clear();
    forn(j,0,m) {
        ll sum = 0;
        forn(i,0,n) sum+=a[i][j];
        best.insert(-sum);
    }
    vll c(k+1, 0);
    forn(i,1,k+1) {
        auto it = best.begin();
        c[i] = c[i-1] - *it;
        ll add = *it + p*n;
        best.erase(it);
        best.insert(add);
    }
    ll ans = -1e18;
    forn(tl,0,k+1) {
        ans = max(ans, r[tl] + c[k-tl] - ll(tl)*(k-tl)*p);
    }
    cout<<ans;
    
    
}