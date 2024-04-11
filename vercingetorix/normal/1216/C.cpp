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
    vi x(6), y(6);
    CoordinateCompressor comp;
    forn(i,0,6) {
        cin>>x[i]>>y[i];
        comp.add(x[i]);
        comp.add(y[i]);
        comp.add(x[i]+1);
        comp.add(y[i]+1);
        comp.add(x[i]-1);
        comp.add(y[i]-1);
    }
    comp.init();
    int l = comp.len();
    vvi a(l, vi(l, 0));
    forn(i,0,6) {
        x[i] = comp.comp(x[i]);
        y[i] = comp.comp(y[i]);
    }
    forn(i,x[0],x[1]) forn(j,y[0],y[1]) a[i][j] = 1;
    forn(i,x[2],x[3]) forn(j,y[2],y[3]) a[i][j] = 0;
    forn(i,x[4],x[5]) forn(j,y[4],y[5]) a[i][j] = 0;
    int can = 0;
    forn(i,0,l) forn(j,0,l) if(a[i][j] == 1) can = 1;
    if(can) printf("YES");
    else printf("NO");
    
    
}