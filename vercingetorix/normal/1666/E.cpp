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
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = 1e18;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        //        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int len,n;
    scanf("%d %d", &len, &n);
    readv(a,n);
    int x = len/n;
    int y = (len+n-1)/n;
    int xl = 0;
    int xr = x+1;
    while(xr - xl > 1) {
        ll xm = (xl + xr)/2;
        LineContainer lc;
        lc.add(xm, 0);
        int bad = 0;
        forn(i,0,n) {
            if(lc.query(i) > a[i]) {
                bad = 1;
                break;
            }
            lc.add(xm, a[i]-xm-i*xm);
        }
        if(lc.query(n) > len) bad = 1;
        if(bad) xr = xm;
        else xl = xm;
    }
    int yl = y-1;
    int yr = len;
    while(yr - yl > 1) {
        ll ym = (yr + yl)/2;
        LineContainer lc;
        lc.add(-ym, -ym);
        int bad = 0;
        forn(i,0,n) {
            if(-lc.query(i) < a[i]) {
                bad = 1;
                break;
            }
            lc.add(-ym, -a[i]-ym+i*ym);
        }
        if(-lc.query(n) < len + ym) bad = 1;
        if(bad) yl = ym;
        else yr = ym;
    }
//    cout<<xl<<' '<<yr<<'\n';;
    vi l(n+1), r(n+1);
    l[0] = 0;
    r[0] = 0;
    a.pb(len);
    forn(i,0,n) {
        int nl = l[i] + xl;
        int nr = r[i] + yr;
        nl = max(nl, a[i]);
        nr = min(nr, a[i+1]);
        l[i+1] = nl;
        r[i+1] = nr;
    }
//    forn(i,0,n+1) {
//        cout<<l[i]<<' '<<r[i]<<'\n';
//        
//    }
//    cout<<'\n';
    vi rans(n+1,0);
    rans[n] = len;
    for(int i = n; i>=1; i--) {
        rans[i-1] = max(l[i-1], rans[i]-yr);
    }
    forn(i,0,n) {
        printf("%d %d\n", rans[i], rans[i+1]);
    }
    
    
}