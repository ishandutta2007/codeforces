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
vll pfac,ipfac;
vll p100;
vll sum, ksum;

ll get(int l, int r) {
    ll A = pfac[r]*(r-l+1)%mod;
    if(l>0) A = A*ipfac[l-1] % mod;
    ll C = sum[r];
    if(l > 0) {
        C = (C + mod - sum[l-1]) % mod;
        C = C*ipfac[l-1]%mod;
    }
    ll B = ksum[r];
    if(l>0) {
        B = (B+mod-ksum[l-1])%mod;
        B = B*ipfac[l-1]%mod;
        B = (B + mod - C*(l-1)%mod) % mod;
    }
    else {
        B = (B+C)%mod;
    }
    return (A+B)*invmod((mod+1-C), mod) % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    readv(p,n);
    ll i100 = invmod(100, mod);
    for(auto x : p) p100.pb(ll(x)*i100%mod);
    ll cur = 1;
    forn(i,0,n) {
        cur = cur*p100[i] % mod;
        pfac.pb(cur);
        ipfac.pb(invmod(cur, mod));
    }
    cur = 0;
    ll cur2 = 0;
    forn(i,0,n) {
        ll ap = (mod + 1 - p100[i]) % mod;
        if(i > 0) ap = ap * pfac[i-1] % mod;
        cur = (cur + ap) % mod;
        cur2 = (cur2 + ap * (i)) % mod;
        sum.pb(cur);
        ksum.pb(cur2);
    }
    
    set<int> cp;
    cp.insert(0);
    cp.insert(n);
    ll ans = get(0,n-1);
    forn(i,0,q) {
        int u;
        scanf("%d", &u);
        u--;
        auto it = cp.lower_bound(u);
        if(*it == u) {
            it--;
            int l = *it;
            it++;
            it++;
            int r = *it;
            cp.erase(u);
            ans = (ans - get(l, u-1) - get(u, r-1) + get(l, r-1) + mod + mod) % mod;
        }
        else {
            int r = *it;
            it--;
            int l = *it;
            cp.insert(u);
            ans = (ans + get(l, u-1) + get(u, r-1) - get(l, r-1) + mod + mod) % mod;
        }
        printf("%lld\n", ans);
    }
}