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

struct sega {
    ll l,r,sum,mx;
    sega(ll l=0, ll r = 0, ll sum = 0, ll mx = 0) : l(l),r(r),sum(sum),mx(mx) {};
};

sega combine(const sega & a, const sega & b) {
    return sega(max(a.l, a.sum+b.l), max(b.r,b.sum+a.r), a.sum+b.sum, max({a.mx, b.mx, a.r+b.l}));
}

sega zerosega;

sega d[1<<9][1<<9];

sega line[1<<18];
void simp(int r) {
    if(r == 1) return;
    forn(i,0,r/2) {
        line[i] = combine(line[i*2], line[i*2+1]);
    }
    simp(r/2);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,1<<n);
    int k = min(n,9);
    forn(pref,0,1<<(n-k)) {
        forn(mix,0,1<<k) {
            forn(i,0,1<<k) {
                int j = i^mix;
                int val = a[(pref<<k) + j];
                line[i] = sega(max(0,val),max(0,val),val,max(0,val));
            }
            simp(1<<k);
            d[pref][mix] = line[0];
        }
    }
    int q;
    read(q);
    int cur = 0;
    while(q--) {
        int cc;
        read(cc);
        cur ^= (1<<cc);
        int pref = cur >> k;
        int suf = cur ^ (pref<<k);
//        printf("%d %d %d\n", cur, pref, suf);
        forn(i,0,1<<(n-k)) {
            line[i] = d[i^pref][suf];
        }
        simp(1<<(n-k));
        printf("%lld\n", line[0].mx);
    }
    
    
}