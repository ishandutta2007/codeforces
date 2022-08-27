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

const int A = 2210;
int n;
ll cnk[A+1][A+1];
ll d2[A+1];

ll get(ll l, ll r, ll z, vll & lto, vll & rto) {
    if(r == 0) {
        if(z == 0) {
            lto[0] = 1;
            rto[0] = 1;
            return 1;
        }
        else return 0;
    }
    ll l2 = (l-z%2)/2 - A/2 + 10;
    l2 = max(l2,0ll);
    ll r2 = (r-z%2)/2;
    vll lto2(A,0);
    vll rto2(A,0);
    ll z2 = get(l2, r2, z/2, lto2, rto2) * d2[n-1] % mod;
    forn(i,0,A) {
        if(lto2[i]) {
            for(int tk = z%2; tk <= n; tk+=2) {
                ll cur = (l2+i)*2 + tk;
                if(cur < l) {
                    z2 -= lto2[i]*cnk[n][tk]%mod;
                }
                else if(cur < min(r+1, l + A)) {
                    lto[cur - l] += lto2[i]*cnk[n][tk]%mod;
                }
            }
        }
        if(rto2[i]) {
            for(int tk = z%2; tk <= n; tk+=2) {
                ll cur = (r2-i)*2 + tk;
                if(cur > r) {
                    z2 -= rto2[i]*cnk[n][tk]%mod;
                }
                else if(cur > max(r - A,l-1)) {
                    rto[r-cur] += rto2[i]*cnk[n][tk]%mod;
                }
            }
        }
    }
    forn(i,0,A) {
        rto[i] %= mod;
        lto[i] %= mod;
    }
    z2 = (z2%mod+mod)%mod;
    return z2;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d2[0] = 1;
    forn(i,1,A+1) d2[i] = d2[i-1]*2%mod;
    forn(n,0,A+1) {
        cnk[n][0] = 1;
        if(n>0) forn(k,1,A+1) cnk[n][k] = (cnk[n-1][k-1] + cnk[n-1][k])%mod;
    }
    ll l,r,z;
    cin>>n>>l>>r>>z;
    vll l0(A,0);
    vll r0(A,0);
    cout<<get(l,r,z,l0,r0);
    
    
    
}