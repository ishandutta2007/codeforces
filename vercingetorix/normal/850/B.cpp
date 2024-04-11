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

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    const int LIMIT = 1000010;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    vvi ad(LIMIT+1);
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
    forn(m,2,LIMIT+1) {
        int md = mindiv[m];
        int mwas = m;
        while(mwas % md == 0) mwas /= md;
        ad[m] = ad[mwas];
        ad[m].pb(md);
    }
    int n;
    ll x,y;
    scanf("%d %lld %lld", &n, &x, &y);
    vi cnt(LIMIT + 1, 0);
    vi a(n);
    if(x>=2*y) {
        forn(i,0,n) {
            scanf("%d", &a[i]);
            for(auto div : ad[a[i]]) cnt[div] += 2;
            for(auto div : ad[a[i] + 1]) cnt[div] += 1;
        }
        ll ans = 1e18;
        for(ll px : p) {
            if(cnt[px] >= n) {
                ll cand = 0;
                ll x106 = px * 1000000ll;
                forn(i,0,n) {
                    ll rest = (x106 - a[i]) % px;
                    cand += min(x, y*rest);
                }
                ans = min(ans, cand);
            }
        }
        cout<<ans;
    }
    else {
        vll cand(LIMIT + 1, (ll)n*x);
        forn(i,0,n) {
            scanf("%d", &a[i]);
            for(auto div : ad[a[i]]) cand[div] -= x;
            for(auto div : ad[a[i] + 1]) cand[div] += min(x, y) - x;
        }
        ll ans = 1e18;
        forn(i,1,LIMIT+1) ans = min(ans, cand[i]);
        cout<<ans;
    }
    
}