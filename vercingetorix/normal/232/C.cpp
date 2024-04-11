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
vll ds;

ll dendi(int n) {
    return (n+1)/2;
}

pll ed(ll v, int n) {
    if(n==0) return mp(0,0);
    else if(n==1) {
        if(v == 1) return mp(0,1);
        else return mp(1,0);
    }
    if(v <= ds[n-1]) {
        auto was = ed(v, n-1);
        was.first = min(was.first, was.second + 2);
        was.second = min(was.first, was.second) + dendi(n-2) + 1;
        return was;
    }
    else {
        auto was = ed(v-ds[n-1], n-2);
        was.first++;
        return was;
    }
}

ll dist(ll u, ll v, int n) {
    if(u > v) swap(u,v);
    int k = n;
    while(max(u,v) <= ds[k-1]) k--;
    if(k == 1) return 1;
    if(u <= ds[k-1]) {
        auto du = ed(u, k-1);
        auto dv = ed(v-ds[k-1], k-2);
        du.first = min(du.first, du.second + 2);
        ll ans =  min(du.first, du.second) + dv.first + 1;
        if(k<n) ans = min(ans, dv.second + du.first + 2);
        return ans;
    }
    else {
        ll ans =  dist(u-ds[k-1], v-ds[k-1], k-2);
        if(k < n) {
            auto du = ed(u-ds[k-1], k-2);
            auto dv = ed(v-ds[k-1], k-2);
            ans = min(ans, du.first + 3 + dv.second);
            ans = min(ans, dv.first + 3 + du.second);
        }
        return ans;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ds.pb(1);
    ds.pb(2);
    forn(i,0,87) ds.pb(ds[i] + ds[i+1]);
//    cout<<ds.back();
    int ta;
    read(ta);
    int n;
    read(n);
    if(n>85) n = 85;
    forn(ifa,0,ta) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", dist(a,b,n));
    }
    
    
}