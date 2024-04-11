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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(p,n);
    readv(x,m);
    srt(x);
    vll h;
    forn(i,0,n) h.pb(ll(100)*i);
    ll ans = 0;
    auto it = lower_bound(all(h), x[0]) - h.begin();
    ll cand = 0;
    forn(i,0,it) cand += p[i];
    ans = cand;
    it = lower_bound(all(h), x.back() + 1) - h.begin();
    cand = 0;
    forn(i,it,n) cand += p[i];
    ans = max(ans, cand);
    forn(j,1,m) {
        ll l = x[j-1];
        ll r = x[j];
        ll len = (r-l)/2;
        if(len*2 == r-l) len--;
        len /= 100;
        len++;
        int pl = lower_bound(all(h), l+1) - h.begin();
        int pr = int(lower_bound(all(h), r) - h.begin()) - 1;
        ll cur = 0;
        if(pr >= pl) {
            int cr = min((ll)pr, pl + len-1);
            forn(i,pl,cr+1) cur += p[i];
            ans = max(cur, ans);
            forn(er,cr+1,pr+1) {
                cur += p[er];
                cur -= p[er-len];
                ans = max(cur, ans);
            }
        }
    }
    printf("%lld\n", ans);
    
    
}