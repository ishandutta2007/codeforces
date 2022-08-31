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

vll imod;



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    int t;
//    read(t);
//    forn(ifa,0,t) {
    int n;
    scanf("%d", &n);
    readv(a,n);
    ll sum = 0;
    forn(i,0,n) sum += a[i];
    if(sum %n != 0) {
        printf("0\n");
        exit(0);
    }
    ll av = sum / n;
    int l = 0;
    int r = 0;
    map<int, int> cnt;
    forn(i,0,n) {
        if(ll(a[i]) > av) r++;
        if(ll(a[i]) < av) l++;
        cnt[a[i]]++;
    }
    ll ans = 1;
    for(int i = n; i> l+r; i--) {
        ans = ans * i % mod;
    }
    if(l == 1 || r == 1||l==0) {
        for(int i= l+r;  i > 0; i--) {
            ans = ans * i % mod;
        }
    }
    else {
        for(int i= l;  i > 0; i--) {
            ans = ans * i % mod;
        }
        for(int i= r;  i > 0; i--) {
            ans = ans * i % mod;
        }
        ans = ans*2%mod;
    }
    imod.pb(0);
    forn(i,1,100500) imod.pb(invmod(i, mod));
    for(auto x : cnt) {
        for(int i= x.second;  i > 0; i--) {
            ans = ans * imod[i] % mod;
        }
    }
    cout<<ans;
    
    
    
}