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

const int A = 500;
ll nfac[A];
ll ifac[A];
ll in[A];
//ll fall[A];

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

ll d[A][A];
int n,k;
void go(int l) {
    for(int s = 2*k; s>=0; s--) {
        forn(was,0,k+1) {
            if(d[s][was] == 0) continue;
            ll dinv = 1;
            ll fall = 1;
            for(int tk = 1; tk*(l-1)+was<=k; tk++) {
                if(tk*l + s > n) break;
                forn(i,0,l) fall = fall*(n-s-(tk-1)*l-i)%mod;
                dinv = dinv*in[l]%mod;
                ll cur = fall*dinv%mod*ifac[tk]%mod;
                d[s + tk*l][was + tk*(l-1)] = (d[s + tk*l][was + tk*(l-1)] + d[s][was]*cur)%mod;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    scanf("%d %d", &n, &k);
//    fall[0] = 1;
//    forn(i,0,A-1) fall[i+1] = fall[i]*(n-i)%mod;
    d[0][0] = 1;
    forn(l,2,k+2) go(l);
    vll ans(2,0);
    ans[0] = 1;
    forn(j,1,k+1) {
        forn(s,0,A) ans[j%2] += d[s][j];
        ans[j%2] %= mod;
        printf("%lld ", ans[j%2]);
    }
    
    
}