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

const long long mod = 998244353;
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

const int A = 10000200;
ll d2[A];
ll id21[A];

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a) {
    ll x, y;
    ll g = gcd (a, mod, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % mod + mod) % mod;
        return x;
    }
}
ll kpow(ll a, ll d) {
    if (d==0) return 1;
    ll x = kpow(a,d/2);
    x = x*x%mod;
    if (d%2==1) x*=a;
    return x%mod;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d2[0] = 1;
    forn(i,1,A) {
        d2[i] = 2*d2[i-1];
        if(d2[i] >= mod) d2[i]-=mod;
    }
    ll i2= (mod+1)/2;
    forn(i,1,A) id21[i] = invmod(d2[i]-1);
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        ll ans = 0;
        int n,k,x;
        scanf("%d %d %d", &n, &k, &x);
        if(x==0) {
            if(n>k) {
                printf("0\n");
                continue;
            }
            ans = 1;
            forn(i,0,n) {
                ans = ans*(d2[k]-d2[i]+mod)%mod;
            }
            printf("%lld\n", ans);
            continue;
        }
        ll num = 1;
        ll dnss = id21[k];
        ll d2ns = kpow(2, n);
        num = dnss;
        forn(s,0,min(k,n) +  1) {
            ans = (ans + num*(d2[k] - d2[s] + mod))%mod;
//            num = num*(mod + d2[k] - d2[s]) % mod;
//            dnss = dnss*(d2ns-1)%mod*id21[s+1]%mod;
            num = num*(mod + d2[k] - d2[s]) % mod * (d2ns-1)%mod*id21[s+1]%mod;
            if(d2ns&1) d2ns = (d2ns + mod)/2;
            else d2ns/=2;
//            d2ns= d2ns*i2%mod;
        }
        printf("%lld\n", ans);
    }
    
}