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
const ll INF = 1e18;
class streemax {
public:
    vll t;
    int s;
    void build (const vll & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -INF;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  max(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
};

class streemin {
public:
    vll t;
    int s;
    void build (const vll & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INF;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  min(
                    get (v*2, tl, tm, l, min(r,tm)),
                    get (v*2+1, tm+1, tr, max(l,tm+1), r)
                    );
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vpi q;
        forn(i,0,n) q.pb(mp(a[i], i));
        set<int> ban;
        ban.insert(-1);
        ban.insert(n);
        srtrev(q);
        int good = 1;
        vll pref;
        for(auto x : a) pref.pb(x);
        forn(i,1,n) pref[i] += pref[i-1];
        streemax stx;
        streemin stn;
        stx.build(pref, 1, 0, n-1);
        stn.build(pref, 1, 0, n-1);
        forn(ita,0,n) {
            int i = q[ita].second;
            auto it = ban.lower_bound(i);
            int r = *it;
            --it;
            int l = *it;
            ll cur = stx.get(1, 0, n-1, i, r-1);
            ll dec = 0;
            if(i > 0) dec = stn.get(1, 0, n-1, max(l,0), i-1);
            if(l == -1) dec = min(dec, 0ll);
            if(cur - dec > q[ita].first) good = 0;
            ban.insert(i);
        }
        if(good) printf("YES\n");
        else printf("NO\n");
        
    }
    
    
}