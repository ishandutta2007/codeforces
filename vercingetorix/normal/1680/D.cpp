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

ll solve(vi & a, ll k) {
    int n = a.size();
    vll psum(n+1,0);
    vll p0(n+1,0);
    forn(i,0,n) {
        psum[i+1] = psum[i] + a[i];
        p0[i+1] = p0[i] + (a[i] == 0);
    }
    ll ret = 0;
    forn(pl, 0, n) {
        forn(pr, pl+1, n) {
            ll sl = psum[pl+1];
            ll nl = p0[pl+1];
            ll sm = psum[pr + 1] - psum[pl + 1];
            ll nm = p0[pr + 1] - p0[pl + 1];
            ll sr = psum[n] - psum[pr+1];
            ll nr = p0[n] - p0[pr+1];
            ll l1 = sl - nl*k;
            ll r1 = sl + nl*k;
            ll l2 = sm - nm*k;
            ll r2 = sm + nm*k;
            ll l3 = sr - nr*k;
            ll r3 = sr + nr*k;
            if(l1 > 0 || l3 > 0) continue;
            r3 = min(r3,0ll);
            r1 = min(r1,0ll);
            if(-r3 - r1 > r2 || l2 > -l3 - l1) continue;
            ret = max(ret, min(r2, -l3 - l1));
        }
    }
    return ret + 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a,n);
    ll sum = 0;
    int c0 = 0;
    ll l = 0;
    ll r = 0;
    forn(i,0,n) {
        sum += a[i];
        if(a[i] == 0) c0++;
        l = min(l,sum);
        r = max(r,sum);
    }
    if(ll(c0)*k < abs(sum)) {
        cout<<-1;
        exit(0);
    }
    else if(n==1) {
        cout<<1;
        exit(0);
    }
    else {
        ll ans = solve(a,k);
//        reverse(all(a));
        forn(i,0,n) a[i] = -a[i];
        ans = max(ans, solve(a,k));
        cout<<ans;
    }
    
}