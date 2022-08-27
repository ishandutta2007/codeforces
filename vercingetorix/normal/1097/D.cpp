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

vvll mmul(vvll & a, vvll & b) {
    vvll c(a.size(), vll(a.size(), 0));
    int k = a.size();
    forn(i,0,k) forn(j,0,k) {
        forn(p,0,k) c[i][j] = (c[i][j] + a[i][p] * b[p][j]) % mod;
    }
    return c;
}

vvll mpow(vvll & a, int k) {
    if(k == 1) return a;
    vvll ret = mpow(a, k/2);
    ret = mmul(ret, ret);
    if(k%2 == 1) ret = mmul(ret, a);
    return ret;
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
    ll n,k;
    cin>>n>>k;
    vvll a(50, vll(50, 0));
    forn(i,0,50) forn(j,i,50) a[i][j] = invmod(j+1, mod);
    a = mpow(a, k);
    vpll q;
    set<ll> div;
    for(ll i = 1; i*i<=n; i++) {
        if(n%i == 0) {
            div.insert(i);
            div.insert(n/i);
        }
    }
    for(ll i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            q.pb(mp(i,1));
            n/=i;
            while(n%i==0) {
                q.back().second++;
                n/=i;
            }
        }
    }
    if(n>1) q.pb(mp(n,1));
    ll ans = 0;
    for(auto x : div) {
        ll p = 1;
        ll m = x;
        for(auto pr : q) {
            int deg = 0;
            while(m%pr.first == 0) {
                m/=pr.first;
                deg++;
            }
            p = p*a[deg][pr.second]%mod;
        }
        ans = (ans+x%mod*p)%mod;
    }
    cout<<ans;
    
    
}