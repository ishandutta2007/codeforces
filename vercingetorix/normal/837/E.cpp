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
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 1000000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vll p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    ll x,y;
    cin>>x>>y;
    ll dxy = gcd(x,y);
    x /= dxy;
    y /= dxy;
    vpll d;
    ll xwas = x;
    for(auto pr : p) {
        if(xwas%pr == 0) {
            d.pb(mp(pr, 1ll));
            xwas/=pr;
            while(xwas%pr == 0) {
                xwas/=pr;
                d.back().second++;
            }
        }
    }
    if(xwas > 1) d.pb(mp(xwas, 1ll));
    ll ans = 0;
    while (y > 0) {
        ll minstep = y;
        for(auto u : d) {
            minstep = min(minstep, y%u.first);
        }
        ans += minstep;
        y -= minstep;
        dxy = gcd(x,y);
        x /= dxy;
        y /= dxy;
        vpll nd;
        ll xwas = x;
        for(auto dpr : d) {
            ll pr = dpr.first;
            if(xwas%pr == 0) {
                nd.pb(mp(pr, 1ll));
                xwas/=pr;
                while(xwas%pr == 0) {
                    xwas/=pr;
                    nd.back().second++;
                }
            }
        }
        d = nd;
        
    }
    cout<<ans;
    
    
}