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

//const long long mod = 998244353;
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
ll mod;


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

const int A = 400500;
ll nfac[A];
ll ifac[A];

void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
}

ll get(ll nl, ll nr) {
    int n = nl+nr;
    ll ret = 0;
    forn(sum,0,nl+nr-1) {
        int ways = min(min(sum+1,int(nl+nr-1-sum)), (int)min(nl,nr));
        ret += nfac[n]*(sum)%mod*invmod(2*sum+4,mod)%mod*ways%mod;
    }
    ret += (nl*(nl-1)/2 + nr*(nr-1)/2)%mod *nfac[n]%mod*invmod(2,mod);
    return ret%mod*ifac[n]%mod;
}

ll get(ll n) {
    return n*(n-1)/2%mod*ifac[2]%mod;
}

map<int, int> cnt;

void go(int l, int r, int h) {
    if(l == r || h==1) cnt[r-l+1]++;
    else {
        int m = (l+r)/2;
        go(l,m,h-1);
        go(m+1,r,h-1);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d %lld", &n, &k, &mod);
    initfac();
    go(1,n, k);
    ll tot = 0;
    for(auto x : cnt) tot+=x.second;
    ll ans = 0;
    for(auto x : cnt) for(auto y : cnt) {
        if(x!=y) {
            ans += ll(x.second)*y.second%mod*get(x.first, y.first)%mod*ifac[2]%mod;
        }
        else {
            if(x.second > 1) {
                ans += ll(x.second)*(x.second - 1)%mod * get(x.first, x.first)%mod*ifac[2]%mod;
            }
            ans -= (tot-2)*x.second%mod*get(x.first)%mod;
        }
    }
    cout<<(ans%mod+mod)%mod<<endl;
}