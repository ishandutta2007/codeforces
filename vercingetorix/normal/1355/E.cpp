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
    int n,a,r,m;
    scanf("%d %d %d %d", &n, &a, &r, &m);
    m = min(m,a+r);
    readv(h,n);
    srt(h);
    vll p;
    forn(i,0,n) p.pb(h[i]);
    forn(i,1,n) p[i]+=p[i-1];
    ll sum = p.back();
    ll ans = 2e18;
    auto check = [&] (ll l) {
        if(l<h[0]) l = h[0];
        if(l>h.back()) l = h.back();
        int md = lower_bound(all(h), l) - h.begin();
        ll sl = 0;
        if(md > 0) sl = p[md-1];
        ll sr = sum - sl;
        ll bot = ll(md)*l - sl;
        ll top = sr-ll(n-md)*l;
        ll tk = min(bot,top);
        bot-=tk;
        top-=tk;
        ll cand = tk*m+bot*a+top*r;
        ans = min(ans, cand);
    };
    forn(i,0,n) check(h[i]);
    ll mid = sum / n;
    check(mid);
    check(mid+1);
    cout<<ans;
    
    
}