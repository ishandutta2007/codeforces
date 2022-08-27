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

const long long mod = 998244353;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair

vll basis;

void add(ll x) {
    for(auto & y : basis) x = min(x, x^y);
    if(x != 0) {
        for(auto & y : basis) y = min(y, x^y);
        basis.pb(x);
    }
}
vll ans;

vll rest;

void stupid(ll cur, int k, int num) {
    if(k==rest.size()) {
        ans[num + __builtin_popcountll(cur)]++;
    }
    else {
        stupid(cur^rest[k], k+1, num+1);
        stupid(cur, k+1, num);
    }
}
vi ms;
vll d2(1,1);
ll d[50][33000];
void dyn(int fs) {
    d[0][0] = 1;
    forn(i,0,rest.size()) {
        ll x = rest[i];
        for(int t = i; t>=0; t--) {
            forn(f,0,d2[fs]) d[t+1][f^x] = (d[t+1][f^x] + d[t][f])%mod;
        }
    }
    forn(i,0,d2[fs]) {
        int b = __builtin_popcountll(i);
        forn(j,0,rest.size()+1) ans[j+b] = (ans[j+b] + d[j][i]) % mod;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(i,0,60) d2.pb(d2.back()*2);
    int n,m;
    scanf("%d %d", &n, &m);
    ans = vll(m+1, 0);
    readv(a,n);
    for(auto x : a) add(x);
    vi minor(60, 0);
    for(auto x : basis) {
        forn(i,0,60) if(x&d2[i]) minor[i] = 1;
    }
    vi bg;
    for(auto x : basis) {
        forn(i,0,60) if((x^d2[i])<d2[i]) {
            minor[i] = 0;
            bg.pb(i);
        }
    }
    
    forn(i,0,60) if(minor[i]) ms.pb(i);
    vi mto(60);
    forn(i,0,ms.size()) mto[ms[i]] = i;
    
    for(auto x : basis) {
        ll cur= 0;
        for(auto i : ms) if((d2[i]&x)>0) cur += d2[mto[i]];
        rest.pb(cur);
    }
    if(basis.size() <= 25) {
        stupid(0, 0, 0);
    }
    else {
        dyn(ms.size());
    }
    ll td2 = 1;
    forn(i,0,n-basis.size()) td2 = td2*2%mod;

    forn(i,0,m+1) printf("%lld ", ans[i]*td2%mod);
}