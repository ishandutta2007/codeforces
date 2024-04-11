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
vpll split(ll l, ll r) {
    vpll ret;
    ll cur = l;
    ll d2 = 1;
    int deg = 0;
    r++;
    while(1) {
        while(cur%(2*d2) == 0 && cur + 2*d2 <= r) {
            d2*=2;
            deg++;
        }
        if(cur + d2 > r) break;
        ret.pb(mp(cur, deg));
        cur += d2;
    }
    while(deg > 0) {
        d2 /= 2;
        deg--;
        if(cur + d2 <= r) {
            ret.pb(mp(cur, deg));
            cur+=d2;
        }
    }
    return ret;
}

const int A= 41;
ll cnk[A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,A) cnk[i][0] = 1;
    forn(i,1,A) forn(j,1,A) cnk[i][j] = cnk[i-1][j] + cnk[i-1][j-1];
    ll n,t;
    cin>>n>>t;
    auto x = split(1, n+1);
    vll cnt(60,0);
    cnt[1]--;
    for(auto y : x) {
        int add = __builtin_popcountll(y.first);
        forn(k,0,y.second+1) cnt[add+k] += cnk[y.second][k];
    }
    forn(i,1,60) if(1ll<<(i-1) == t) {
        cout<<cnt[i];
        exit(0);
    }
    cout<<0;
    
    
}