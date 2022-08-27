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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    vll sum;
    ll cur = 0;
    forn(i,0,n) {
        sum.pb(cur);
        if(a[i] > 0) cur += a[i];
    }
    vpll d;
    forn(i,0,n) d.pb(mp(a[i], i));
    sort(all(d));
    int pt = 0;
    ll ans = -1e18;
    int l = 0;
    int r = n-1;
    while(pt < n) {
        int pr = pt+1;
        while(pr<n && d[pt].first == d[pr].first) pr++;
        if(pr - pt > 1) {
            int bi = d[pr-1].second;
            ll cand = d[pt].first;
            if(d[pt].first < 0) cand += d[pt].first;
            for(int i = pr-2; i>=pt; i--) {
                if(cand + sum[bi] - sum[d[i].second] > ans) {
                    ans = cand + sum[bi] - sum[d[i].second];
                    l = d[i].second;
                    r = bi;
                }
                if(sum[d[i].second] > sum[bi]) {
                    bi = d[i].second;
                }
            }
        }
        pt = pr;
    }
    vi del;
    forn(i,0,l) del.pb(i+1);
    forn(i,l+1,r) if(a[i] < 0) del.pb(i+1);
    forn(i,r+1,n) del.pb(i+1);
    printf("%lld %d\n", ans, del.size());
    for(auto x : del) printf("%d ", x);
    
}