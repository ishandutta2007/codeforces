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
        auto it = lower_bound(all(xc), x);
        if(it == xc.end() || *it != x) return -1;
        else return it - xc.begin();
    }
    
    inline int len() {
        return xc.size();
    }
};
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
const int MAXN = 200500;
vpi pt[MAXN];
int decr[MAXN];
CoordinateCompressor comp,comp2;
int n = 0;
void aplus(int x, int y, int val) {
    ll d = gcd(x,y);
    int loc = comp2.comp(((ll(x)/d) << 20) + (y)/d);
    if(loc != -1) decr[loc] += val;
}

void add(int x, int y) {
    n++;
    int w = comp.comp(ll(x)*x + ll(y)*y);
    forn(i,0,pt[w].size()) {
        int x2 = pt[w][i].first;
        int y2 = pt[w][i].second;
        aplus(x+x2, y + y2, 2);
    }
    pt[w].pb(mp(x, y));
    aplus(x, y, 1);
}

void rem(int x, int y) {
    n--;
    int w = comp.comp(ll(x)*x + ll(y)*y);
    int loc = 0;
    while(pt[w][loc] != mp(x,y)) loc++;
    swap(pt[w][loc], pt[w].back());
    pt[w].pop_back();
    forn(i,0,pt[w].size()) {
        int x2 = pt[w][i].first;
        int y2 = pt[w][i].second;
        aplus(x+x2, y + y2, -2);
    }
    aplus(x, y, -1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    read(q);
    vi t(q), x(q), y(q);
    
    forn(i,0,q) {
        scanf("%d %d %d", &t[i], &x[i], &y[i]);
        if(t[i] == 1) {
            comp.add(ll(x[i])*x[i] + ll(y[i])*y[i]);
        }
        if(t[i] == 3) {
            ll dd = gcd(x[i], y[i]);
            x[i] /= dd;
            y[i] /= dd;
            comp2.add((ll(x[i])<<20) + y[i]);
        }
    }
    comp.init();
    comp2.init();
    forn(i,0,q) {
        if(t[i] == 1) add(x[i], y[i]);
        else if(t[i] == 2) rem(x[i], y[i]);
        else if(t[i] == 3) {
            int loc = comp2.comp((ll(x[i])<<20) + y[i]);
            printf("%d\n", n - decr[loc]);
        }
    }
    
    
    
}