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
const int LIMIT = 1000000;
vi dv[LIMIT+1];
vi pd[LIMIT+1];
ll cnt[LIMIT+1];
vll d2;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d2.pb(1);
    forn(i,1,201000) d2.pb(d2.back()*2%mod);
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
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
    dv[1].pb(1);
    forn(i,2,LIMIT+1) {
        int x = i;
        int pr = mindiv[i];
        int dpr = pr;
        x/=pr;
        while(x%pr == 0) {
            x/=pr;
            dpr*=pr;
        }
        pd[i] = pd[x];
        pd[i].pb(pr);
        while(dpr>0) {
            for(auto y : dv[x]) dv[i].pb(y*dpr);
            dpr/=pr;
        }
    }
    int n;
    scanf("%d", &n);
    
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        for(auto y : dv[x]) cnt[y]++;
    }
    forn(i,1,LIMIT+1) {
        if(cnt[i] > 0) cnt[i] = d2[cnt[i]-1]*cnt[i]%mod;
    }
    ll ans = 0;
    for(int i = LIMIT; i>1; i--) {
        for(auto x : dv[i]) if(x!=i) cnt[x] = (cnt[x] + mod - cnt[i])%mod;
        ans += (cnt[i]*i)%mod;
    }
    printf("%lld", ans%mod);

    
    
}