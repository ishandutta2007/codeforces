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
ll cn, ck;
ll curc;
vll imod(310500);
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
void adjust(ll n, ll k) {
    while(ck > k) {
        curc = curc*ck%mod;
        curc = curc*imod[cn-ck+1]%mod;
        ck--;
    }
    while(cn < n) {
        curc = curc * (cn+1)%mod;
        curc = curc * imod[cn-ck+1]%mod;
        cn++;
    }
    while(ck < k) {
        curc = curc * (cn-ck)%mod;
        curc = curc * imod[ck+1]%mod;
        ck++;
    }
    while(cn > n) {
        curc = curc * (cn-ck) %mod;
        curc = curc *imod[cn] % mod;
        cn--;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,1, 300100) imod[i] = invmod(i, mod);
    int t=1;
//    scanf("%d", &t);
    cn = 1;
    ck = 0;
    curc = 1;
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,2*n);
        adjust(2*n, n);
        ll ans = 0;
        srt(a);
        forn(i,0,n) ans += a[n+i]-a[i];
        ans = (mod+ans%mod)%mod;
        ans = ans*curc%mod;
        cout<<ans;
        
        
    }
    
}