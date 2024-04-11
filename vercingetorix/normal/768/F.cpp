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
#define forn(i, a, b) for(int i = a; i < b; i++)

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
    gcd(a, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll f,w,h;
    cin>>f>>w>>h;
    if(f==0) {
        if(w<=h) cout<<0;
        else cout<<1;
        return 0;
    }
    if(w==0) {
        cout<<1;
        return 0;
    }
    ll cw1k1 = 1;
    ll cf1k = f+1;
    ll cwkh1k1 = 1;
    if(w<=h) cwkh1k1 = 0;
    ll p = 0;
    ll q = 0;
    for(ll k=1; k<=w; k++) {
        p = (p+cwkh1k1*cf1k)%mod;
        q = (q+cw1k1*cf1k)%mod;
        cf1k = (cf1k*(f+1-k))%mod;
        cf1k = (cf1k*invmod(k+1, mod))%mod;
        cw1k1 = (cw1k1*(w-k)) %mod;
        cw1k1 = (cw1k1*invmod(k,mod))%mod;
        if(cwkh1k1 != 0) {
            cwkh1k1 = (cwkh1k1 * invmod(k, mod)) % mod;
            forn(i,1,h+1) {
                cwkh1k1 = (cwkh1k1 * invmod(w-k*h-i, mod))%mod;
                cwkh1k1 = (cwkh1k1 * (w-(h+1)*k+1-i)) % mod;
            }
            cwkh1k1 = (cwkh1k1 * (w-(h+1)*k-h)) % mod;
        }
    }
    printf("%lld", p*invmod(q, mod)%mod);
    
}