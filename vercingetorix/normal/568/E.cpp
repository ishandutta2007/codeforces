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
//class CoordinateCompressor {
//public:
//    vi xc;
//    vi xx;
//
//    inline void add(int x) {
//        xx.pb(x);
//    }
//
//    void init() {
//        xc.clear();
//        srt(xx);
//        forn(i,0,xx.size()) if(i==0 || xx[i] != xx[i-1]) xc.pb(xx[i]);
//    }
//
//    inline int comp(const int x) {
//        return lower_bound(all(xc), x) - xc.begin();
//    }
//
//    inline int len() {
//        return xc.size();
//    }
//};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    CoordinateCompressor comp;
    int n;
    read(n);
//    vi a;
//    forn(i,1,n+1) a.pb(i);
    readv(a,n);
//    for(auto x : a) comp.add(x);
    int m;
    read(m);
//    vi b;
//    forn(i,1,m+1) b.pb(i);
    readv(b,m);
//    for(auto x : b) comp.add(x);
//    comp.add(-1);
//    comp.init();
//    forn(i,0,n) a[i] = comp.comp(a[i]);
//    forn(i,0,m) b[i] = comp.comp(b[i]);
    srt(b);
//    int l = comp.len();
//    vi hb(l,0);
//    for(auto x : b) hb[x] = 1;
    map<pi, pi> prev;
    set<pi> inc;
    set<int> check;
    for(auto x : b) check.insert(x);
    inc.insert(mp(-1,-1));
    const int INF = 2e9;
    pi was;
    auto add = [&] (int v, int pos) {
        auto it = inc.lower_bound(mp(v, 0));
        if(it!=inc.end() && it->first == v) {
            return v+1;
        }
        it--;
        if(it->second == pos) prev[mp(v,pos)] = was;
        else prev[mp(v,pos)] = *it;
        it++;
        int lim = INF;
        if(it!=inc.end()) {
            lim = it->first+1;
            was = *it;
            inc.erase(it);            
        }
        inc.insert(mp(v, pos));
        auto it2 = lower_bound(all(b), v+1);
        if(it2!=b.end() && *it2 <= lim) check.insert(*it2);
        return lim;
    };
    forn(i,0,n) {
        if(a[i] == -1) {
            int lim = -INF;
            vi uf;
            for(auto x : check) uf.pb(x);
            check.clear();
            for(auto x : uf) {
                if(x>=lim) lim = max(lim, add(x, i));
            }
//            auto it = check.end();
//            vi uf;
//            for(auto x : check) uf.pb(x);
//            reverse(all(uf));
//            check.clear();
//            for(auto x : uf) add(x,i);
        }
        else {
            add(a[i], i);
        }
    }
    multiset<int> left;
    for(auto x : b) left.insert(x);
    auto it = inc.end();
    --it;
    auto cur = *it;
    while(cur.second != -1) {
//        cout<<cur.first<<' '<<cur.second<<endl;
        int pos = cur.second;
        int v = cur.first;
        if(a[pos] == -1) {
            a[pos] = v;
            left.erase(left.find(v));
        }
        cur = prev[cur];
    }
    for(int i = n-1; i>=0; i--) {
        if(a[i] == -1) {
            a[i] = *left.begin();
            left.erase(left.begin());
        }
    }
//    cout<<inc.size()-1<<endl;
//    for(auto x : inc) cout<<x.first<<' '<<x.second<<'\n';
    forn(i,0,n) printf("%d ", a[i]);
    
    
}