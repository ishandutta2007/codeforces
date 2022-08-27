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

const long long mod = 998244353;
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
const int A = 300500;
int pref[41][A];
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

ll nfac[A];
ll ifac[A];
ll in[A];

void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) in[i] = ifac[i]*nfac[i-1]%mod;
}

ll cnk(int n, int k) {
    if(k<0 || k>n) return 0;
    return nfac[n]*ifac[k]%mod*ifac[n-k]%mod;
}
int shift[A];
int d[1<<20];
int touch[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    int n,m;
    scanf("%d %d", &n, &m);
    vi l(n), r(n);
    forn(i,0,n) {
        scanf("%d %d", &l[i], &r[i]);
        shift[l[i]]++;
        shift[r[i]+1]--;
    }
    int cur = 0;
    forn(i,0,n+1) {
        cur += shift[i];
        forn(dec,0,41) pref[dec][i] = cnk(cur-dec, i-dec);
    }
    forn(dec,0,41) forn(i,1,n+1) {
        pref[dec][i] += pref[dec][i-1];
        if(pref[dec][i] >= mod) pref[dec][i] -= mod;
    }
    vi u(m), v(m);
    forn(i,0,m) {
        scanf("%d %d", &u[i], &v[i]);
        u[i]--; v[i]--;
    }
    forn(mask,0,1<<m) {
        int dec = 0;
        int tl = 1;
        int tr = n;
        forn(bit,0,m) if(mask&(1<<bit)) {
            for(auto x : {u[bit],v[bit]}) if(touch[x] == 0) {
                tl = max(tl, l[x]);
                tr = min(tr, r[x]);
                touch[x] = 1;
                dec++;
            }
        }
        if(tl <= tr) {
            d[mask] = pref[dec][tr] + mod - pref[dec][tl-1];
            if(d[mask] >= mod) d[mask] -= mod;
        }
        forn(bit,0,m) if(mask&(1<<bit)) {
            touch[u[bit]] = 0;
            touch[v[bit]] = 0;
        }
    }
    forn(bit,0,m) forn(mask,0,1<<m) {
        if((mask&(1<<bit))==0) {
            d[mask] = d[mask] + mod - d[mask|(1<<bit)];
            if(d[mask]>=mod) d[mask] -= mod;
        }
    }
    cout<<d[0];
    
}