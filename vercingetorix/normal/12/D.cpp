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
    vi xc;
    vi xx;
    
    inline void add(int x) {
        xx.pb(x);
    }
    
    void init() {
        xc.clear();
        srt(xx);
        forn(i,0,xx.size()) if(i==0 || xx[i] != xx[i-1]) xc.pb(xx[i]);
    }
    
    inline int comp(const int x) {
        return lower_bound(all(xc), x) - xc.begin();
    }
    
    inline int len() {
        return xc.size();
    }
};

class stree {
public:
    vi t;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n,0);
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
            t[v] = max(t[v],new_val);
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
    read(n);
    readv(a,n);
    readv(b,n);
    readv(c,n);
    CoordinateCompressor comp;
    forn(i,0,n) comp.add(b[i]);
    comp.init();
    forn(i,0,n) b[i] = comp.comp(b[i]);
    vector<pair<int, pi>> q;
    forn(i,0,n) q.pb(mp(-a[i], mp(b[i], c[i])));
    int m = comp.len();
    srt(q);
    int pt = 0;
    int ans = 0;
    stree st;
    st.build(m, 1, 0, m-1);
    while(pt < q.size()) {
        int pr = pt+1;
        while(pr < q.size() && q[pr].first == q[pt].first) pr++;
        forn(i,pt,pr) {
            if(st.get(1, 0, m-1, q[i].second.first + 1, m-1) > q[i].second.second) ans++;
        }
        forn(i,pt,pr) st.update(1, 0, m-1, q[i].second.first, q[i].second.second);
        pt = pr;
    }
    cout<<ans;
    
    
}