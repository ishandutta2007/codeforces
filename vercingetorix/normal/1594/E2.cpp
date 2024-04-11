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
int k;
vll d2;
set<ll> bad;
map<ll, int> ban;
map<ll, vll> res;
int getlev(ll x) {
    return upper_bound(all(d2), x) - d2.begin();
}

void unite(vll & a, vll & b, vll & to) {
    forn(i,0,6) to[i] = 0;
    forn(i,0,6) forn(j,0,6) forn(k,0,6) {
        if(k!=i && k!=j && (k+3)%6!=i && (k+3)%6!=j) {
            to[k]=(to[k] + a[i]*b[j])%mod;
        }
    }
}

vll e;

void resolve(ll v) {
    int l = getlev(v);
    vll cur(6, 1);
    if(l < k) {
        vll a(6, e[k-l-1]);
        vll b(6, e[k-l-1]);
        if(bad.find(v*2)!=bad.end()) a=res[v*2];
        if(bad.find(v*2+1)!=bad.end()) b=res[v*2+1];
        unite(a, b, cur);
    }
    if(ban[v] != -1) {
        forn(i,0,6) if(i!=ban[v]) cur[i] = 0;
    }
    res[v] = cur;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d2.pb(1);
    forn(i,0,61) d2.pb(d2.back() * 2);
    scanf("%d", &k);
    ll ans = 1;
    
    e.pb(1);
    forn(i,0,k-1) {
        ans = ans*ans%mod*16%mod;
        e.pb(ans);
    }
    
    bad.insert(1);
    ban[1] = -1;
    
    int n;
    scanf("%d\n", &n);
    char c[100];
    while(n--) {
        ll v;
        scanf("%lld %s", &v, c);
        int col = 0;
        if(c[0] == 'w') col = 0;
        if(c[0] == 'y') col = 3;
        if(c[0] == 'g') col = 1;
        if(c[0] == 'b') col = 4;
        if(c[0] == 'r') col = 2;
        if(c[0] == 'o') col = 5;
        ban[v] = col;
        bad.insert(v);
        while(v > 1) {
            v /= 2;
            if(bad.find(v) == bad.end()) {
                bad.insert(v);
                ban[v] = -1;
            }
        }
    }
    vll ord;
    for(auto x : bad) ord.pb(x);
    for(auto x : bad) res[x] = vll(6,0);
    reverse(all(ord));
    for(auto v : ord) resolve(v);
    ll pr = 0;
    forn(i,0,6) pr+=res[1][i];
    cout<<pr%mod;
    
    
}