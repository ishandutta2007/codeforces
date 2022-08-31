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

ll s2(ll a, ll k) {
    ll big = a%k;
    ll sm = k-big;
    ll ss = a/k;
    return big*(ss+1)*(ss+1) + sm*ss*ss;
}
ll ans = 0;
ll get(ll a, ll dec) {
    ll l = 0;
    ll r = a;
    while(r - l > 1) {
        ll m = (r+l)/2;
        ll cur = s2(a, m) - s2(a, m + 1);
        if(cur >= dec) l = m;
        else r = m;
    }
    ans += r-1;
    return s2(a, r);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    for(int i = n-1; i>0; i--) a[i] -= a[i-1];
    ll l = 1;
    ll r = 1e18;
    ll nd;
    scanf("%lld", &nd);
    while(r - l > 1) {
        ll m = (r+l)/2;
        ll cand = 0;
        forn(i,0,n) cand += get(a[i], m);
        if(cand <= nd) l = m;
        else r = m;
    }
    ll cur = 0;
    ans = 0;
    forn(i,0,n) cur += get(a[i], r);
    if(cur > nd) ans += (cur-nd+l-1)/l;
    cout<<ans;
    
    
}