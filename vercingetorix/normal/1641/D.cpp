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

const int A = 100010;
int cnt[5*A];
const int B = 320;
int bignum[A*5];
int bn = 0;
bitset<A> big[2000];
vi pos[A*5];
bitset<A> def;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    CoordinateCompressor comp;
    int n,m;
    scanf("%d %d", &n, &m);
    vvi a(n, vi(m));
    vi w(n);
    
    forn(i,0,n) {
        forn(j,0,m) scanf("%d", &a[i][j]);
        scanf("%d", &w[i]);
        forn(j,0,m) comp.add(a[i][j]);
    }
    vpi ord;
    forn(i,0,n) ord.pb(mp(w[i], i));
    srt(ord);
    vvi b(n);
    forn(i,0,n) b[i] = a[ord[i].second];
    swap(a,b);
    b.clear();
    srt(w);
    comp.init();
    forn(i,0,n) forn(j,0,m) a[i][j] = comp.comp(a[i][j]);
    int l = comp.len();
    forn(i,0,n) forn(j,0,m) cnt[a[i][j]]++;
    forn(i,0,l) bignum[i] = -1;
    forn(i,0,l) if(cnt[i] >= B) bignum[i] = bn++;
    forn(i,0,n) forn(j,0,m) {
        if(bignum[a[i][j]] >= 0) big[bignum[a[i][j]]][i] = 1;
        else pos[a[i][j]].pb(i);
    }
    forn(i,0,bn) big[i] = ~big[i];
    def = ~def;
    const int INF = 2e9 + 5000;
    int ans = INF;
    forn(i,0,n) {
        bitset<A> cur = def;
        forn(j,0,m) {
            if(bignum[a[i][j]] >= 0) cur &= big[bignum[a[i][j]]];
            else {
                for(auto ind : pos[a[i][j]]) cur[ind] = 0;
            }
        }
        int j = cur._Find_first();
        if(j<n) ans = min(ans, w[i]+w[j]);
    }
    if(ans == INF) ans = -1;
    cout<<ans;
    
    
}