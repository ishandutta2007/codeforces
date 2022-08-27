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
const int A = 100500;
//bitset<A> a[A];
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

vi a[A];
vi pos[2*A];
int isbig[2*A];
const int B = 320;
int bc[2*B][A];
int bigloc[2*A];
int touch[A];

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
        CoordinateCompressor comp;
        forn(i,0,n) {
            int k;
            scanf("%d", &k);
            a[i].resize(k);
            forn(j,0,k) {
                scanf("%d", &a[i][j]);
                comp.add(a[i][j]);
            }
        }
        comp.init();
        forn(i,0,n) forn(j,0,a[i].size()) {
            a[i][j] = comp.comp(a[i][j]);
            pos[a[i][j]].pb(i);
        }
        int l = comp.len();
        vi big;
        forn(i,0,l) if(pos[i].size() >= B) {
            bigloc[i] = big.size();
            big.pb(i);
        }
        for(auto x : big) isbig[x] = 1;
        forn(it,0,big.size()) {
            for(auto x : pos[big[it]]) bc[it][x] = 1;
        }
        int done = 0;
        
        forn(f,0,l) {
            forn(i,0,big.size()) {
                if(isbig[f] && f <= big[i]) continue;
                vi occ;
                for(auto x : pos[f]) if(bc[i][x]) occ.pb(x);
                if(occ.size() > 1) {
                    done = 1;
                    printf("%d %d\n", occ[0]+1, occ[1]+1);
                    break;
                }
            }
            if(done) break;
        }
        
        if(!done)
        forn(f,0,n) {
            for(auto x : a[f]) if(!isbig[x]) {
                for(auto y : pos[x]) if(y!=f) {
                    if(touch[y]) {
                        done = 1;
                        printf("%d %d\n", f+1, y+1);
                        break;
                    }
                    touch[y] = 1;
                }
                if(done) break;
            }
            for(auto x : a[f]) if(!isbig[x]) for(auto y : pos[x]) touch[y] = 0;
            if(done) break;
        }
        
        if(!done) printf("-1\n");
        
        forn(it,0,big.size()) {
            for(auto x : pos[big[it]]) bc[it][x] = 0;
        }
        for(auto x : big) isbig[x] = 0;
        forn(i,0,n) a[i].clear();
        forn(i,0,l) pos[i].clear();
    }
    
    
}