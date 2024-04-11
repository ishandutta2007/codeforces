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

const long long mod = 1220703125;
//const ll mod = 390625;
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
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll mod2 = 12288;
    vi f(2, 0);
    f[1] = 1;
    int m = 1<<13;
    vi have(m, 0);
    int cnt = 0;
    forn(i,0,1000000) {
        if(i>0 && f[i]==0 && f[i+1] == 1) {
            break;
        }
        f.pb((f[i] + f[i+1])%m);
    }
    ll need;
    cin>>need;
    ll n5 = need%mod;
    const ll p = 1097376068;
    ll n5rev = n5*invmod(p, mod)%mod;
    ll mn5 = (mod-n5)%mod;
    ll mn5rev = (mod-n5rev)%mod;
    ll a = 0;
    ll b = 1;
    vll can;
    if(n5 == 0) {
        forn(i,0,4) can.pb(mod*i);
    }
    else
    forn(i,0,mod) {
        if(a == n5) can.pb(i);
        if(a == n5rev) can.pb(mod+i);
        if(a == mn5) can.pb(mod*2+i);
        if(a == mn5rev) can.pb(mod*3+i);
        swap(a,b);
        b+=a;
        if(b>=mod) b-=mod;
    }
    vll can2;
    forn(i,0,mod2) if(f[i] == need%(1<<13)) can2.pb(i);
    const ll INF = 1e18;
    ll ans = INF;
    for(auto x : can) {
        ll cur = x;
        forn(i,0,12288) {
            for(auto y : can2) if(cur%mod2 == y) {
                ans = min(ans, cur);
            }
            cur += 4*mod;
        }
    }
    if(ans == INF) ans = -1;
    cout<<ans;
}