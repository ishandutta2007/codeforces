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

const long long mod = 998244353 ;
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
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    const int A = 2021;
//    ll nk[A][A];
//    forn(i,0,A) {
//        nk[i][0] = 1;
//        if(i>0) nk[0][i] = 0;
//    }
//    forn(i,1,A) {
//        forn(j,1,A) nk[i][j] = (nk[i-1][j-1] + nk[i-1][j])%mod;
//    }
    const int A = 200500;
    vll nfac(1,1);
    forn(i,1,A) nfac.pb(nfac.back() * i % mod);
    vll ifac;
    for(auto x : nfac) ifac.pb(invmod(x, mod));
    int n,k;
    scanf("%d %d", &n, &k);
    readv(h,n);
    if(n == 1 || k==1) {
        cout<<0;
        exit(0);
    }
    vll dk2(1,1);
    forn(i,0,n+10) dk2.pb(dk2.back()*(k-2)%mod);
    int fr = 0;
    forn(i,0,n) {
        if(h[i] == h[(i+1)%n]) fr++;
    }
    int m = n-fr;
    ll ans = 0;
    ll dk = 1;
    forn(i,0,m) dk = dk*k%mod;
    for(int k = 0; k*2 <= m; k++) {
        dk = (dk + mod - ifac[k]*ifac[k]%mod*nfac[m]%mod*ifac[m-2*k]%mod*dk2[m-2*k]%mod)%mod;
    }
    ans = dk * invmod(2, mod) % mod;
//    forn(w,1,m+1) {
//        forn(l,0,w) {
//            if(w+l > m) break;
//            ans = (ans + nk[m][w] * nk[m-w][l] % mod * dk2[m-l-w])%mod;
//        }
//    }
    forn(i,0,fr) ans = ans * k % mod;
    cout<<ans;
    
    
    
}