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

ll c2(ll x) {
    return x*(x-1)/2;
}

ll c3(ll x) {
    return x*(x-1)*(x-2)/6;
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
        int n;
        scanf("%d\n", &n);
        vi a(n), b(n);
        forn(i,0,n) scanf("%d %d", &a[i], &b[i]);
        vll ca(n+1, 0), cb(n+1, 0);
        forn(i,0,n) {
            ca[a[i]]++;
            cb[b[i]]++;
        }
        ll ans = ll(n)*(n-1)*(n-2)/6;
//        forn(i,1,n+1) {
//            ans -= c3(ca[i]);
//            ans -= c3(cb[i]);
//            ans -= c2(ca[i])*(n-ca[i]);
//            ans -= c2(cb[i])*(n-cb[i]);
//        }
        forn(i,0,n) {
            ans -= (ca[a[i]]-1)*(cb[b[i]] - 1);
        }
        printf("%lld\n", ans);
    }
    
    
}