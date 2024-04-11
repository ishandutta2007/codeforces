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

map<ll, ll> F;

ll f(ll n) {
    if (F.count(n)) return F[n];
    ll k=n/2;
    if (n%2==0) { // n=2*k
        return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod;
    } else { // n=2*k+1
        return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) %mod;
    }
}

void mul(vll & p, ll c) {
    ll mem = 0;
    forn(i,0,p.size()) {
        swap(p[i], mem);
        p[i] = (p[i] + mem*c)%mod;
    }
    p.pb(mem);
}
const int AC = 200;
const int BC = 200;
ll cnk[AC][BC];

void initcnk() {
    forn(i,0,AC) cnk[i][0] = 1;
    forn(i,1,AC) forn(j,1,BC) {
        cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];
        if(cnk[i][j] >= mod) cnk[i][j] -= mod;
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initcnk();
    F[0] = F[1] = 1;
//    cout<<f(4);
    ll n;
    int k;
    cin>>n>>k;
    vll d(k+1, 0);
    vll p(1,1);
    d[0] = (f(n+2) +mod - 2)%mod;
    forn(l,1,k+1) {
        ll lik = 1;
        forn(i,0,l) lik=lik*(2+i)%mod;
        mul(p, l+1);
        forn(i,0,l) d[l] -= (d[i]*p[i])%mod;
        d[l] -= lik;
        d[l] = (d[l]%mod + mod)%mod;
        forn(l1,0,l+1) {
            int l2 = l-l1;
            ll mult = 1;
            forn(i,0,l1) {
                mult = mult * ((n+l+2-i) %mod)%mod;
            }
            forn(i,1,l2+1) {
                mult = mult * (mod - i) %mod;
            }
            ll num = n+l+3-l1+l2;
            mult = mult*cnk[l][l1]%mod;
            d[l] += f(num-1)*mult%mod;
            if(l1 == 0) d[l] -= f(l2)*mult%mod;
        }
        d[l] = (d[l]%mod + mod)%mod;
    }
    cout<<d[k];
}