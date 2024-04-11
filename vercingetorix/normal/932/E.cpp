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
ll kpow(ll a, ll d, ll modulo) {
    if (d==0) return 1;
    ll x = kpow(a,d/2,modulo);
    x = x*x%modulo;
    if (d%2==1) x*=a;
    return x%modulo;
}

const int N = 5051;
ll nfac[N];
ll ifac[N];
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

ll cnk(int n, int k) {
    return nfac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    nfac[0] = 1;
    ifac[0] = 1;
    forn(i,1,N) {
        nfac[i] = nfac[i-1]*i%mod;
        ifac[i] = invmod(nfac[i], mod);
    }
    int n,k;
    cin>>n>>k;
    if(n<=k){
        ll ans = 0;
        forn(l,1,n+1) {
            ans += cnk(n,l)*kpow(l,k,mod)%mod;
        }
        cout<<ans%mod;
        exit(0);
    }
    
    ll i2 = (mod+1)/2;
    vll cur;
    cur.pb(kpow(2,n,mod)-1);
    forn(i,0,k) cur.pb((cur.back()+1)*i2%mod-1);
    while(cur.size() > 1) {
        forn(i,0,cur.size() - 1) {
            cur[i] = (n-i)*(cur[i]+mod-cur[i+1])%mod;
        }
        cur.pop_back();
    }
    cout<<cur[0];
    
    
    
}