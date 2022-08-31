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
class CoordinateCompressor {
public:
    vll xc;
    vll xx;
    
    inline void add(ll x) {
        xx.pb(x);
    }
    
    void init() {
        xc.clear();
        srt(xx);
        forn(i,0,xx.size()) if(i==0 || xx[i] != xx[i-1]) xc.pb(xx[i]);
    }
    
    inline int comp(const ll x) {
        return lower_bound(all(xc), x) - xc.begin();
    }
    
    inline int len() {
        return xc.size();
    }
};
class stree {
public:
    vi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
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
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  max(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = max(t[v], new_val);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  max(t[v*2], t[v*2+1]);
        }
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    ll a,b,c,d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    vi x(n),y(n);
    vll u(n), v(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
        u[i] = -a*x[i] + b*y[i];
        v[i] = -c*x[i] + d*y[i];
    }
    CoordinateCompressor compu, compv;
    for(auto q : u) compu.add(q);
    for(auto q : v) compv.add(q);
    compv.init();
    compu.init();
    vi good(n,0);
    forn(i,0,n) {
        if(u[i] > 0 && v[i] < 0) good[i] = 1;
    }
    forn(i,0,n) u[i] = compu.comp(u[i]);
    forn(i,0,n) v[i] = compv.comp(v[i]);
    stree st;
    st.build(vi(n,0), 1, 0, n-1);
    vpi q;
    forn(i,0,n) if(good[i]) q.pb(mp(u[i], i));
    srt(q);
    int r = 0;
    while(r < q.size()) {
        int r2 = r+1;
        while(r2 < q.size() && q[r2].first == q[r].first) r2++;
        vi upd;
        forn(it,r,r2) {
            int i = q[it].second;
            upd.pb(st.get(1, 0, n-1, v[i]+1, n-1)+1);
        }
        forn(it,r,r2) {
            st.update(1, 0, n-1, v[q[it].second], upd[it-r]);
        }
        r = r2;
    }
    cout<<st.get(1, 0, n-1, 0, n-1);
    
    
}