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

const long long mod = 1000000009;
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
ll kpow(ll a, ll d) {
    if (d==0) return 1;
    ll x = kpow(a,d/2);
    x = x*x%mod;
    if (d%2==1) x*=a;
    return x%mod;
}
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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,a,b,k;
    scanf("%d %d %d %d\n", &n, &a, &b, &k);
    char c[100500];
    scanf("%s", c);
    
    
    vll da(1,1);
    forn(i,0,k+1) da.pb(da.back() * a%mod);
    vll db(1,1);
    forn(i,0,k+1) db.pb(db.back() * b%mod);
    ll ba = b*invmod(a, mod)%mod;
    if(kpow(ba, k) == 1) {
        ll ans = 0;
        forn(i,0,k) if(c[i] == '+') ans+= da[k-1-i]*db[i]%mod;
        else ans-= da[k-1-i]*db[i]%mod;
        ans = (ans%mod+mod)%mod;
//        ans = ans * kpow(a, n)%mod;
        ans = ans * (n+1)/k % mod;
        cout<<ans;
        
        exit(0);
    }
    ll A = kpow(a, n+1-k) * (mod+1-kpow(ba, n+1))%mod*invmod((mod+1-kpow(ba,k))%mod, mod)%mod;
    ll ans = 0;
    forn(i,0,k) {
        if(c[i] == '+') ans += A*da[k-1-i]%mod*db[i]%mod;
        else ans += mod-A*da[k-1-i]%mod*db[i]%mod;
    }
    cout<<ans%mod;
}