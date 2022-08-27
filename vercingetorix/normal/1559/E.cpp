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

const long long mod = 998244353 ;
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
int n,m;
int curm;
int ml = 0;
void mul(vi & a, int k) {
    vi b(k+1,0);
    for(auto x : a) b.pb(x);
    forn(i,0,a.size()) b[i] = (b[i] + mod - a[i])%mod;
    int mem = b.back();
    b.pop_back();
    for(int i = (int)b.size() -1; i>=0; i--) {
        b[i] += mem;
        swap(b[i], mem);
        mem%=mod;
    }
    while(b.size() > curm-ml+1) b.pop_back();
    a = std::move(b);
}
vi l,r;

ll get(int d) {
    vi a(1,1);
    curm = m/d;
    ml = 0;
    forn(i,0,n) {
        int curr = r[i]-r[i]%d;
        if(curr < l[i]) return 0;
        int curl = l[i];
        if(curl % d > 0) curl = curl + d - curl%d;
        curl /= d;
        curr /= d;
        ml += curl;
        if(ml > curm) return 0;
        mul(a, curr-curl);
    }
    ll ret= 0;
    forn(i,0,min(curm -ml+1, (int)a.size())) ret += a[i];
    return ret%mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 100000;
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    
    scanf("%d %d", &n, &m);
    vi sf(m+1, 0);
    vi odd(m+1, 0);
    vvi divs(m+1);
    divs[1].pb(1);
    sf[1] = 1;
    odd[1] = 0;
    forn(i,2,m+1) {
        int pp = mindiv[i];
        if(i/pp % pp == 0) continue;
        if(sf[i/pp]) {
            sf[i] = 1;
            odd[i] = 1-odd[i/pp];
            for(auto x : divs[i/pp]) {
                divs[i].pb(x);
                divs[i].pb(x*pp);
            }
        }
    }
    vi a(1,1);
    int ml = 0;
    l.resize(n);
    r.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &l[i], &r[i]);
    }
    vll du(1,0);
    ll ans = 0;
//    forn(i,1,m+1) du.pb(get(i));
    forn(i,1,m+1) {
        if(sf[i]) {
            ll cur = get(i);
            if(odd[i]) ans = (ans + mod - cur%mod)%mod;
            else ans = (ans + cur)%mod;
        }
    }
    cout<<ans;
//    forn(i,0,m+1) cout<<i<<' '<<du[i]<<endl;
//
}