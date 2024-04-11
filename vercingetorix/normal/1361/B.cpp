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
ll kpow(ll a, ll d, ll modulo) {
    if (d==0) return 1;
    ll x = kpow(a,d/2,modulo);
    x = x*x%modulo;
    if (d%2==1) x*=a;
    return x%modulo;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,p;
        scanf("%d %d", &n, &p);
        map<int, int> deg;
        readv(a,n);
        srtrev(a);
//        for(auto x : a) deg[-x]++;
        int inf = 0;
        ll mindiff = 0;
        int lp = -1;
        for(auto x : a) {
            if(p>1 && mindiff > 0) {
                if(lp - x > 20) {
                    mindiff = mindiff * kpow(p, lp-x, mod) % mod;
                    inf = 1;
                }
                else {
                    forn(i,0,lp-x) {
                        mindiff *= p;
                        if(mindiff > 1e9) {
                            mindiff %= mod;
                            inf = 1;
                        }
                    }
                }
            }
            lp = x;
            if(inf) {
                mindiff = (mindiff + mod - 1)%mod;
            }
            else {
                mindiff = abs(mindiff-1);
            }
        }
        mindiff = mindiff * kpow(p, lp, mod) % mod;
        printf("%lld\n", mindiff);
        
    }
    
    
}