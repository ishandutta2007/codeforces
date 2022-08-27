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

bool lucky(int m) {
    while(m>0) {
        if(m%10 != 4 && m%10!=7) return false;
        m/=10;
    }
    return true;
}
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
const int A  = 100500;
int bnum[A];
vi bpos[A];

ll pr(ll len) {
    return len*(len+1)/2;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    vi lind;
    vi indl(n,0);
    CoordinateCompressor comp;
    forn(i,0,n) {
        if(lucky(a[i])) lind.pb(i);
        comp.add(a[i]);
    }
    for(auto x : lind) indl[x] = 1;
    comp.init();
    int m = comp.len();
    forn(i,0,n) a[i] = comp.comp(a[i]);
    vi numl(m,0);
    for(auto x : lind) numl[a[x]] = 1;
    int pt = 0;
    unsigned long long ans = 0;
    vi lto(n+1);
    vi rto(n+1);
    for(auto x : lind) bpos[a[x]].pb(x);
    forn(r,0,n) {
        if(indl[r]) pt++;
        forn(i,0,pt) bnum[a[lind[i]]]++;
        vi wall;
        wall.pb(r);
        forn(i,pt,lind.size()) {
            int ind = lind[i];
            if(bnum[a[ind]] > 0) wall.pb(ind);
        }
        wall.pb(n);
        ll cur = 0;
        rto[wall[0]] = wall[1];
        forn(i,1,wall.size()) {
            ll len = wall[i] - wall[i-1] - 1;
            cur += len*(len+1)/2;
            lto[wall[i]] = wall[i-1];
            if(i+1<wall.size()) rto[wall[i]] = wall[i+1];
        }
        int last = -1;
        forn(l,0,pt) {
            int ind = lind[l];
            ll lp = ind - last;
            last  = ind;
            ans += cur*lp;
            bnum[a[ind]]--;
            if(bnum[a[ind]] == 0) {
                for(auto pos : bpos[a[ind]]) if(pos > r) {
                    int lpos = lto[pos];
                    int rpos = rto[pos];
                    cur -= pr(pos-lpos-1) + pr(rpos-pos-1);
                    cur += pr(rpos-lpos-1);
                    rto[lpos] = rpos;
                    lto[rpos] = lpos;
                }
            }
        }
        ll lp = r - last;
        ans += cur*lp;
    }
    cout<<ans;
    
}