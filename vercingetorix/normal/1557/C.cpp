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

ll pmod(ll a, ll k) {
    if(k == 0) return 1;
    ll res = pmod(a, k/2);
    res = res*res%mod;
    if(k%2) res = res*a%mod;
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n,k;
        scanf("%lld %lld", &n, &k);
        if(n%2 == 1) {
            printf("%lld\n", pmod(pmod(2,n-1)+1, k));
        }
        else {
            ll a = pmod(2, n-1) - 1;
            vll dega(1,1);
            forn(i,0,k) dega.pb(dega.back()*a%mod);
            ll b = (a+1)*2 % mod;
            vll degb(1,1);
            forn(i,0,k) degb.pb(degb.back()*b%mod);
            ll ans = dega[k];
            forn(i,0,k) {
                ans = (ans + dega[i]*degb[k-1-i])%mod;
            }
            printf("%lld\n", ans);
        }
//        else
//        if(n%2 == 1) {
//            printf("%lld\n", (pmod(2, n*k-k) + pmod(2, n*k-n+1) + mod - pmod(2, (n-1)*(k-1)))%mod);
//        }
//        else {
//            printf("%lld\n", pmod(2,n*k-k));
//        }
    }
    
}