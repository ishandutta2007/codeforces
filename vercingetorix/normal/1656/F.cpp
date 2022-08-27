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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a2,n);
        vll a;
        for(auto x : a2) a.pb(x);
        srt(a);
        ll cl = 0;
        forn(i,1,n) cl += a[0] + a[i];
        ll cr = 0;
        forn(i,0,n-1) cr += a[n-1] + a[i];
        if(cl >0 || cr < 0) printf("INF\n");
        else {
            ll ans = -2e18;
            ll k = cl;
            ll A = 0;
            forn(i,1,n) A += a[0]*a[i];
            ans = max(ans, A-k*a[0]);
            forn(m,1,n-1) {
                A -= a[0]*a[m];
                A += a[m]*a[n-1];
                k -= a[0];
                k += a[n-1];
                ans = max(ans, A-k*a[m]);
            }
            ans = max(ans, A-k*a[n-1]);
            printf("%lld\n", ans);
        }
    }
    
    
}