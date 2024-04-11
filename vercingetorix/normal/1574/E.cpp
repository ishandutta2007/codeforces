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

const long long mod = 998244353;
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
int badrows = 0;
int badcols = 0;
int freecols, freerows;

class Line {
public:
    Line() {};
    vi t = vi(2,0);
    set<pll> a;
    void set(ll pos, ll val) {
        auto it = a.lower_bound(mp(pos, 0));
        if(it!=a.end() && it->first == pos) {
            t[(pos+it->second)%2]--;
            a.erase(it);
        }
        t[(pos + val)%2]++;
        a.insert(mp(pos, val));
    }
    
    void clear(ll pos) {
        auto it = a.lower_bound(mp(pos, 0));
        if(it!=a.end() && it->first == pos) {
            t[(pos+it->second)%2]--;
            a.erase(it);
        }
    }
    
    int bad() {
        if(t[0] > 0 && t[1] > 0) return 1;
        else return 0;
    }
    
    int free() {
        if(t[0] + t[1] == 0) return 1;
        else return 0;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);
    vector<Line> rows(n);
    vector<Line> cols(m);
    Line mb;
    vll d2(1,1);
    forn(i,0,1000500) d2.pb(d2.back() * 2 % mod);
    
    freerows = n;
    freecols = m;
    forn(idt,0,q) {
        int x,y,v;
        scanf("%d %d %d", &x, &y, &v);
        x--; y--;
        ll xy = ll(x)*(2*m+1) + y;
        freerows -= rows[x].free();
        badrows -= rows[x].bad();
        freecols -= cols[y].free();
        badcols -= cols[y].bad();
        if(v==-1) {
            rows[x].clear(y);
            cols[y].clear(x);
            mb.clear(xy);
        }
        else {
            rows[x].set(y, v);
            cols[y].set(x, v);
            mb.set(xy, v);
        }
        freerows += rows[x].free();
        badrows += rows[x].bad();
        freecols += cols[y].free();
        badcols += cols[y].bad();
        ll ans = 0;
        if(badcols == 0) ans += d2[freecols];
        if(badrows == 0) ans += d2[freerows];
        if(mb.bad() == 0) ans += mod-1;
        if(mb.free()) ans += mod-1;
        ans %= mod;
        printf("%lld\n", ans);
    }
    
    
}