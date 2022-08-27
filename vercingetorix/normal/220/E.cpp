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

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    
    T get(int l, int r) {
        if(l>r) return 0;
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};

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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    CoordinateCompressor comp;
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    readv(a,n);
    forn(i,0,n) comp.add(a[i]);
    comp.init();
    forn(i,0,n) a[i] = comp.comp(a[i]);
    int m = comp.len();
    fenwick<int> l(m);
    fenwick<int> r(m);
    l.modify(a[0], 1);
    r.modify(a[n-1], 1);
    int ptl = 0;
    int ptr = n-1;
    ll cur = 0;
    if(a[0] > a[n-1]) cur++;
    while(ptr > 1) {
        int nx = a[ptr-1];
        int add = l.get(nx+1, m-1) + r.get(0, nx-1);
        if(cur + add > k) break;
        ptr--;
        cur += add;
        r.modify(nx, 1);
    }
    ll ans = 0;
    while(ptl < n-1) {
        while(ptr<n && cur > k) {
            int nx = a[ptr];
            cur -= l.get(nx+1, m-1) + r.get(0, nx-1);
            r.modify(nx, -1);
            ptr++;
        }
        if(ptr == n) break;
        ans += n-ptr;
        ptl++;
        int nx = a[ptl];
        cur += l.get(nx+1, m-1) + r.get(0, nx-1);
        l.modify(nx, 1);
        if(ptl == ptr) {
            cur -= l.get(nx+1, m-1) + r.get(0, nx-1);
            r.modify(nx, -1);
            ptr++;
        }
    }
    cout<<ans;
    
    
    
}