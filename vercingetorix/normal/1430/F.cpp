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
    int n,k;
    scanf("%d %d", &n, &k);
    ll INF = 1e18;
    vi l(n), r(n), a(n);
    forn(i,0,n) scanf("%d %d %d", &l[i], &r[i], &a[i]);
    ll sum = 0;
    for(auto x : a) sum+=x;
    ll ans = INF;
    vll d(n+1, INF);
    d[0] = 0;
    forn(s,0,n) {
        if(d[s] == INF) continue;
        ll left = k;
        int bad = 0;
        forn(p,s,n) {
            ll can = left;
            if(r[p] > l[p]) can += ll(r[p]-l[p])*k;
            if(can < a[p]) {
                bad = 1;
                break;
            }
            left = (can - a[p])%k;
            if(p<n-1) {
                if(l[p+1]>r[p] || (r[p]>l[p] && can - k >= a[p])) d[p+1] = min(d[p+1], d[s]+left);
            }
        }
        if(bad == 0) ans = min(ans, d[s]);
    }
    ans += sum;
    if(ans >= INF) ans = -1;
    cout<<ans;
    
    
}