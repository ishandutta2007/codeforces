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

vi x, y;
const int A = 200500;
const int N = 100500;
//int kill[N];
int cntx[A];
int cnty[A];
vi xwas, ywas;
int ans = 0;

void solve(vi & ind) {
    set<pi> ax,ay;
    set<int> cutx, cuty;
    for(auto i : ind) {
//        kill[i] = 0;
        cntx[x[i]]++;
        cnty[y[i]]++;
        if(cntx[x[i]] == 1) xwas.pb(x[i]);
        if(cnty[y[i]] == 1) ywas.pb(y[i]);
        ax.insert(mp(x[i], i));
        ay.insert(mp(y[i], i));
    }
    srt(xwas);
    srt(ywas);
    for(auto px : xwas) if(px != xwas.back()) {
        if(cntx[px+1] == 0) cutx.insert(px+1);
    }
    for(auto py : ywas) if(py != ywas.back()) {
        if(cnty[py+1] == 0) cuty.insert(py+1);
    }
    vvi proc;
    auto delp = [&] (const vi & del) {
        proc.pb(del);
        for(auto i : del) {
            cntx[x[i]]--;
            if(cntx[x[i]] == 0 && cntx[x[i]-1] > 0) cutx.insert(x[i]);
            ax.erase(mp(x[i], i));
            
            cnty[y[i]]--;
            if(cnty[y[i]] == 0 && cnty[y[i]-1] > 0) cuty.insert(y[i]);
            ay.erase(mp(y[i], i));
        }
    };
    while(1) {
        int lx = ax.begin()->first;
        auto itax = ax.end();
        itax --;
        int rx = itax->first;
        int ly = ay.begin()->first;
        auto itay = ay.end();
        itay --;
        int ry = itay->first;
        
        while(!cutx.empty()) {
            auto it = cutx.begin();
            if(*it<lx) cutx.erase(it);
            else break;
        }
        while(!cutx.empty()) {
            auto it = cutx.end();
            it--;
            if(*it>rx) cutx.erase(it);
            else break;
        }
        if(!cutx.empty()) {
            auto itl = ax.begin();
            auto itr = ax.end();
            itr--;
            int cutl = *cutx.begin();
            auto itcut = cutx.end();
            itcut --;
            int cutr = *itcut;
            while(itl->first < cutl && itr->first > cutr) {
                itl++;
                itr--;
            }
            if(itl->first > cutl) {
                vi todel;
                while(itl != ax.begin()) {
                    itl--;
                    todel.pb(itl->second);
                }
                delp(todel);
                continue;
            }
            else {
                vi todel;
                while(1) {
                    itr++;
                    if(itr == ax.end()) break;
                    todel.pb(itr->second);
                }
                delp(todel);
                continue;
            }
        }
        
        while(!cuty.empty()) {
            auto it = cuty.begin();
            if(*it<ly) cuty.erase(it);
            else break;
        }
        while(!cuty.empty()) {
            auto it = cuty.end();
            it--;
            if(*it>ry) cuty.erase(it);
            else break;
        }
        if(!cuty.empty()) {
            auto itl = ay.begin();
            auto itr = ay.end();
            itr--;
            int cutl = *cuty.begin();
            auto itcut = cuty.end();
            itcut --;
            int cutr = *itcut;
            while(itl->first < cutl && itr->first > cutr) {
                itl++;
                itr--;
            }
            if(itl->first > cutl) {
                vi todel;
                while(itl != ay.begin()) {
                    itl--;
                    todel.pb(itl->second);
                }
                delp(todel);
                continue;
            }
            else {
                vi todel;
                while(1) {
                    itr++;
                    if(itr == ay.end()) break;
                    todel.pb(itr->second);
                }
                delp(todel);
                continue;
            }
        }
        break;
    }
    for(auto i : ind) {
        cntx[x[i]] = 0;
        cnty[y[i]] = 0;
    }
    ax.clear();
    ay.clear();
    cutx.clear();
    cuty.clear();
    xwas.clear();
    ywas.clear();
    ans++;
    for(auto chind : proc) solve(chind);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    CoordinateCompressor compx, compy;
    int n;
    read(n);
//    vi x(n), y(n);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
        compx.add(x[i]);
        compy.add(y[i]);
        compx.add(x[i]-1);
        compy.add(y[i]-1);
    }
    compx.init();
    compy.init();
    forn(i,0,n) {
        x[i] = compx.comp(x[i]);
        y[i] = compy.comp(y[i]);
    }
    vi full;
    forn(i,0,n) full.pb(i);
    solve(full);
    cout<<ans;
    
    
}