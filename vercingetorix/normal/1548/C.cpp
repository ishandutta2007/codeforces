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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int A = 1000001;
    int n, q;
    scanf("%d %d", &n, &q);
    vll imod(3*A+1,0);
    forn(i,1,3*A+1) imod[i] = invmod(i, mod);
    ll curc = 1;
    vll a;
    forn(i,0,3*n) {
        curc = curc*(3*n-i) % mod;
        curc = curc*imod[i+1] % mod;
        a.pb(curc);
    }
    for(int i = 3*n-1; i>=2; i--) {
        a[i-1] = (a[i-1] + 3*(mod-a[i]))%mod;
        a[i-2] = (a[i-2] + 3*(mod-a[i]))%mod;
    }
    forn(i,0,3*n-2) a[i] = a[i+2];
    a.pop_back();
    a.pop_back();
    forn(it,0,3) {
        a.pb(a.back());
        for(int i = a.size() - 2; i >= 1; i--) a[i] = (a[i] + a[i-1])%mod;
    }
    forn(i,0,q) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", a[x]);
    }
    
}