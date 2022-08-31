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

const long long mod = 998244353 ;
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


const int A = 20000;
ll nfac[A];
ll ifac[A];

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
void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
}

ll cnk(int n, int k) {
    return nfac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    int n,k;
    scanf("%d %d\n", &n, &k);
    char c[50060];
    scanf("%s", c);
    string s(c);
    vi pref;
    int sum = 0;
    pref.pb(sum);
    for(auto x : s) {
        sum+=x-'0';
        pref.pb(sum);
    }
    ll ans = 1;
    if(pref.back() < k) {
        cout<<1;
        exit(0);
    }
    forn(l,0,n) {
        forn(r,l,n) {
            if(pref[r+1] - pref[l] > k) continue;
            int len = r-l+1;
            int c1 = pref[r+1] - pref[l];
            int c0 = len - c1;
            if(s[l] != s[r]) ans += cnk(c1+c0-2, c1-1);
            else {
                if(s[l] == '1') {
                    if(c0 < 2) continue;
                    else c0 -= 2;
                }
                else if(s[l] == '0') {
                    if(c1 < 2) continue;
                    else c1 -= 2;
                }
                ans += cnk(c1+c0, c1);
            }
        }
    }
    cout<<ans%mod;
    
}