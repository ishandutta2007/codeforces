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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
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
    if(a==0) return 0;
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m,k;
    scanf("%lld %lld %lld", &n, &m, &k);
    int d = gcd(n, m);
    readv(a,n);
    readv(b,m);
    ll ans = 0;
    map<int, int> w;
    forn(i,0,n) w[a[i]] = i+1;
    ll md = m/d;
    vi irr(md, n);
    ll tirr = 0;
    forn(j,0,m) if(w[b[j]] != 0) {
        int i = w[b[j]] - 1;
        if(i%d != j%d) continue;
        ll id = i/d;
        ll jd = j/d;
        
        ll l = invmod((n/d)%md, md)%md * (jd-id+md*n)%md;
//        forn(p, 0, d) {
            irr[l]--;
//        }
    }
    forn(i,0,md) tirr += irr[i];
    if(k>tirr) {
        ans += md*n * ((k-tirr)/tirr);
        k = tirr+k%tirr;
        
    }
    ll s = 0;
    while(irr[(s/n)%md] < k) {
        k -= irr[(s/n)%md];
        s += n;
    }
    while(k > 0) {
        if(a[s%n] != b[s%m]) k--;
        s++;
    }
    cout<<ans+s;
    
    
}