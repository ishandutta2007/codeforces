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

const long long modulo = 1000000007;
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

ll powM(ll k, ll n) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = powM(k, n/2);
    return (((x*x)%modulo)*powM(k, n%2)) % modulo;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vll a(n);
    ll sum = 0;
    forn(i,0,n) {
        scanf("%lld", &a[i]);
        sum+=a[i];
    }
    if(sum==1) {
        cout<<0;
        return 0;
    }
    const int A = 101000;
    vll ank(A);
    ank[1] = (sum-1)*invmod(sum, mod)%mod;
    ll diff = (invmod(sum, mod)- 1)%mod;
    forn(i,2,min((int)sum+1, A)) {
        diff = (diff + invmod(sum-i+1, mod)) % mod;
        ank[i] = (ank[i-1] - diff + mod)%mod;
    }
    ll ans = 0;
    forn(i,0,n) {
        ans += ank[a[i]];
    }
    ans = ans%mod*(sum-1)%mod;
    cout<<ans;
    
    
}