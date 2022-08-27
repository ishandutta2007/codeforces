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
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    CoordinateCompressor comp;
    int n,m;
    scanf("%d %d", &n, &m);
    readv(x,n);
    srt(x);
    comp.add(1);
    comp.add(1000000000);
    for(auto xx : x) comp.add(xx);
    for(auto xx : x) comp.add(xx+1);
    vector<pair<pi, int>> q;
    forn(i,0,m) {
        int x1,x2,y;
        scanf("%d %d %d", &x1, &x2, &y);
        q.pb(mp(mp(x1,x2), y));
        comp.add(x1-1);
        comp.add(x1);
        comp.add(x2);
        comp.add(x2+1);
    }
    comp.add(1000000001);
    comp.init();
    vi bl(comp.len(), 0);
    for(auto a : x) bl[comp.comp(a+1)]++;
    int cur = 0;
    for(auto ev : q) {
        if(ev.first.first == 1) {
            cur++;
            bl[comp.comp(ev.first.second+1)]--;
        }
    }
    int ans = n+m;
    forn(i,0,comp.len() - 1) {
        cur += bl[i];
        ans = min(ans, cur);
    }
    cout<<ans;
    
    
}