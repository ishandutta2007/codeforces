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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair


ll sum1k1i_x(ll k, ll x) {
    return (x + (x*(x+1)/2)%mod * (k-1)) % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a,n);
    vpi x;
    forn(i,0,n) x.pb(mp(a[i], i));
    sort(all(x));
//    reverse(all(x));
    set<int> bbb;
    forn(i,-1,n+1) bbb.insert(i);
    ll ans = 0;
    for( auto px : x) {
        int i = px.second;
        bbb.erase(i);
        auto it = bbb.upper_bound(i);
        int r = *it;
        it--;
        int l = *it;
//        cout<<l<<' '<<r<<endl;
        ll a = i-l;
        ll b = r-i;
        if(a>b) swap(a,b);
        ll x1 = (a-1) / (k-1);
        ll x2 = (b-1) / (k-1);
        ll x3 = (a+b-1) / (k-1);
        ll cnt = ((a+b) * (x3-x2) + a * (x2-x1) + sum1k1i_x(k, x1) - sum1k1i_x(k, x3) + sum1k1i_x(k, x2) + mod) % mod;
        ans = (ans + cnt * ll(px.first)) % mod;
    }
    cout<<ans;
}