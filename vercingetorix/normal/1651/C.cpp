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
        readv(a,n);
        readv(b,n);
        ll b1 = abs(b[0]-a[0]);
        ll b2 = abs(b.back()-a[0]);
        forn(i,0,n) {
            b1 = min(b1, (ll)abs(b[0]-a[i]));
            b2 = min(b2, (ll)abs(b[n-1]-a[i]));
        }
        ll a1 = abs(b[0]-a[0]);
        ll a2 = abs(a.back()-b[0]);
        forn(i,0,n) {
            a1 = min(a1, (ll)abs(a[0]-b[i]));
            a2 = min(a2, (ll)abs(a[n-1]-b[i]));
        }
        ll ans = abs(a[0]-b[0]) + abs(a.back() - b.back());
        ans = min(ans, (ll)abs(a[0]-b.back()) + abs(a.back() - b[0]));
        ans = min(ans, abs(a[0]-b[0]) + a2 + b2);
        ans = min(ans, abs(a.back()-b[0]) + a1 + b2);
        ans = min(ans, abs(a[0]-b.back()) + a2 + b1);
        ans = min(ans, abs(a.back()-b.back()) + a1 + b1);
        ans = min(ans, a1+a2+b1+b2);
        printf("%lld\n", ans);
    }
    
    
}