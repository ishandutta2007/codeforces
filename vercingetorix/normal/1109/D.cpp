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

vll imod;

class cnk {
public:
    ll curc, ck, cn;
    void adjust(ll n, ll k) {
        if(k>n) {
            curc = 0;
            return;
        }
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
};


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    imod.pb(0);
    forn(i,1,1000500) imod.pb(invmod(i, mod));
    vll fac(1,1);
    forn(i,1,1000500) fac.pb(fac.back()*i%mod);
    int n,m;
    scanf("%d %d", &n, &m);
    cnk c;
    c.cn = m-1;
    c.ck = 0;
    c.curc = 1;
    ll ans = 0;
    ll cf = 1;
    vll dn(1,1);
    forn(i,1,1000500) dn.pb(dn.back() * n % mod);
    vll dm(1,1);
    forn(i,1,1000500) dm.pb(dm.back() * m % mod);
    forn(k,0,n-1) {
        if(k+1 > m) break;
        c.adjust(m-1, k);
        ll p = c.curc * cf % mod;
        cf = cf*(n-2-k)%mod;
        int vl = n- 2 - k;
        int comp = vl+1;
        if(comp == 1) {
            ans = (ans + p)%mod;
        }
        else ans = (ans + p*(k+2)%mod*dn[comp-2]%mod*dm[comp-1])%mod;
    }
    cout<<ans;
    
    
}