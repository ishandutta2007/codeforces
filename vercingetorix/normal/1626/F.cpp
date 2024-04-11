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
int n, a0, x,y,k,m;
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

const int A = 720720;
ll d[2][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>n>>a0>>x>>y>>k>>m;
    vll a;
    ll ans = 0;
    ll in = invmod(n, mod);
    ll ps = (mod+1-in)%mod;
    ll kin = in*k%mod;
    ll dn = 1;
    forn(i,0,k) dn = dn*n%mod;
    forn(i,0,n) {
        ans = (ans + a0/A*A*kin)%mod;
        a.pb(a0%A);
        a0 = (ll(a0)*x+y)%m;
    }
    forn(i,0,A) d[(k+1)%2][i] = 0;
    for(int l = k; l>=1; l--) {
        forn(i,0,A) {
            d[l%2][i] = (d[(l+1)%2][i]*ps+in*(i+d[(l+1)%2][i-i%l]))%mod;
        }
    }
    forn(i,0,n) ans += d[1][a[i]];
    cout<<ans%mod*dn%mod;
    
    
    
//    set<ll>f;
//    f.insert(gen()%m);
//    forn(i,1,18) {
//        vll add;
//        for(auto v : f) {
//            add.pb(v-v%i);
//        }
//        for(auto v : add) f.insert(v);
//    }
//    cout<<f.size();
    
    
    
    
}