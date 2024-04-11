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
#define readvll(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
    scanf("%lld %lld", &n, &m);
    readvll(a,n);
//    n = 200000;
//    m = 5000000;
//    vll a(n, ll(m)*(m+1)/2);
    ll ans = 0;
    for(ll l = 1; l <= m; l++) {
        if(l*n > m) break;
        ll mx = ll(m)*l - ll(l)*(l-1)/2*n;
        forn(i,0,n-1) {
            mx = min(mx, a[i] + m - l*(i+1));
        }
        vll b = a;
        b[n-1] = min(b[n-1], mx);
        for(int i = n-2; i>=0; i--) {
            b[i] = min(b[i], b[i+1] - l);
        }
        ll mn = l + ll(l)*(l-1)/2*n;
        if(b[0] < mn) continue;
        ll cand = 0;
        for(auto x : b) cand+=x;
        ans = max(ans, cand);
    }
    cout<<ans;
}