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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        vi c(n), p(n);
        forn(i,0,n) scanf("%d %d", &c[i], &p[i]);
        CoordinateCompressor comp;
        for(auto x : c) comp.add(x);
        comp.init();
        vll shiftc(n+1,0);
        vll shift(n+1,0);
        forn(i,0,n) {
            int mid = comp.comp(c[i]);
            int l = comp.comp(c[i] - p[i]);
            int r = comp.comp(c[i] + p[i] + 1) -  1;
            shiftc[l]++;
            shiftc[mid+1]--;
            shift[l] += p[i] - c[i];
            shift[mid+1] -= p[i] - c[i];
            shiftc[mid+1]--;
            shiftc[r+1]++;
            shift[mid+1] += p[i] + c[i];
            shift[r+1] -= p[i] + c[i];
        }
        vll over(n+1,0);
        ll cur = 0;
        ll curc = 0;
        forn(i,0,comp.len()) {
            cur  += shift[i];
            curc += shiftc[i];
            ll val  =  curc*comp.xc[i] + cur;
            if(val > m)  over[i]  = val - m;
//            cout<<over[i]<<' ';
        }
        vll need(n+1,0);
        int l = comp.len();
        ll add = -1e18;
        forn(i,0,l) {
            if(over[i] > 0) add = max(add, over[i] - comp.xc[i]);
            need[i] =  max(need[i], comp.xc[i] +  add);
        }
        add = -1e18;
        for(int i = l-1; i>=0; i--) {
            if(over[i] > 0) add = max(add, over[i] + comp.xc[i]);
            need[i] =  max(need[i], -comp.xc[i] +  add);
        }
        string ans(n,'0');
        forn(i,0,n) {
            int mid = comp.comp(c[i]);
            if(p[i] >= need[mid]) ans[i] = '1';
        }
//        cout<<'\n';
        printf("%s\n", ans.c_str());
    }
    
    
}