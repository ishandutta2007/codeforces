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

const long long mod = 998244353
;
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
ll kpow(ll a, ll d) {
    if (d==0) return 1;
    ll x = kpow(a,d/2);
    x = x*x%mod;
    if (d%2==1) x*=a;
    return x%mod;
}
//const int N = 6;
//ll d[N][N];
//ll d1[N];
//
//ll cnk[N][N];
const int N = 1000001;
ll fac[N];
ll ifac[N];
ll d3[N];
ll d3n[N];
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

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

ll cnk(int n, int k) {
    return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    fac[0] = 1;
    d3[0] = 1;
    d3n[0] = 1;
    forn(i,1,N) d3[i] = d3[i-1]*3%mod;
    forn(i,1,N) d3n[i] = d3n[i-1]*d3[n]%mod;
    forn(i,1,N) fac[i] = fac[i-1]*i%mod;
    ifac[N-1] = invmod(fac[N-1], mod);
    for(int i = N-2; i>=0; i--) ifac[i] = ifac[i+1]*(i+1)%mod;
    vll ak(n+1);
    forn(k,1,n+1) ak[k] = (3*kpow(d3[n-k]-1, n) + (d3[k]+mod-3)*d3n[n-k]) % mod * cnk(n,k) % mod;
    ll ans = 0;
    forn(k,1,n+1) ans += cnk(n,k)*d3[k]%mod*kpow(d3[n]+mod-3, n-k)%mod;
    forn(k,1,n+1) ans += ak[k]*((k%2)*2 - 1);
    cout<<(ans%mod + mod)%mod;
    
}