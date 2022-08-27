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
template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};
CoordinateCompressor comp;
#ifdef LOCAL
const int A = 20;
const int B = 5;
#else
const int A = 200500;
const int B = 320;
#endif
set<int> big;
int bn = 0;
map<int, int> bignum;
int small[A][B+10];
int snum[A];
int adef[A];
int tp[A];
int q1[A];
int q2[A];
int n,m;
vector<fenwick<int>> fensm;
vector<fenwick<int>> fenbig;

int getnum(int pos) {
    int v = comp.comp(adef[pos]);
    if(big.find(v) == big.end()) {
        int pt = 0;
        while(small[v][pt] != pos) pt++;
        return pt+1;
    }
    else {
        int ind = bignum[v];
        return fenbig[ind].get(pos);
    }
}

void del(int pos) {
    int val = adef[pos];
    int v = comp.comp(val);
    if(big.find(v) != big.end()) {
        int ind = bignum[v];
        fenbig[ind].modify(pos, -1);
    }
    else {
        int pt = 0;
        while(small[v][pt] != pos) pt++;
        forn(i,pt,snum[v]) fensm[i+1].modify(small[v][i], -1);
        forn(i,pt,snum[v]-1) {
            small[v][i] = small[v][i+1];
        }
        snum[v]--;
        forn(i,pt,snum[v]) fensm[i+1].modify(small[v][i], 1);
    }
}

void add(int pos) {
    int val = adef[pos];
    int v = comp.comp(val);
    if(big.find(v) != big.end()) {
        int ind = bignum[v];
        fenbig[ind].modify(pos, 1);
    }
    else {
        int pt = 0;
        while(pt<snum[v] && small[v][pt] < pos) pt++;
        forn(i,pt,snum[v]) fensm[i+1].modify(small[v][i], -1);
        for(int i = snum[v]; i>pt; i--) {
            small[v][i] = small[v][i-1];
        }
        small[v][pt] = pos;
        snum[v]++;
        forn(i,pt,snum[v]) fensm[i+1].modify(small[v][i], 1);
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    map<int, int> cnt;
    map<int, vi> pd;
    read(n);
    forn(i,0,n) scanf("%d", &adef[i]);
    forn(i,0,n) {
        cnt[adef[i]]++;
        pd[adef[i]].pb(i);
    }
    read(m);
    forn(i,0,m) {
        scanf("%d %d %d", &tp[i], &q1[i], &q2[i]);
        q2[i]--;
        if(tp[i] == 1) cnt[q1[i]]++;
    }
    for(auto x : cnt) comp.add(x.first);
    comp.init();
    forn(i,0,B) fensm.emplace_back(n);
    for(auto x : cnt) {
        if(x.second >= B) {
            int v = comp.comp(x.first);
            big.insert(v);
            bignum[v] = bn++;
            fenbig.emplace_back(n);
            for(auto pos : pd[x.first]) fenbig.back().modify(pos, 1);
        }
        else {
            int v = comp.comp(x.first);
            int cur = 0;
            for(auto pos : pd[x.first]) {
                small[v][snum[v]++] = pos;
                cur++;
                fensm[cur].modify(pos, 1);
            }
        }
    }
    
    forn(i,0,m) {
        if(tp[i] == 1) {
            int val = q1[i];
            int pos = q2[i];
            del(pos);
            adef[pos] = val;
            add(pos);
        }
        else {
            int pos = q2[i];
            if(q1[i] == 1) printf("%d\n", adef[pos]);
            else if(q1[i] %2 == 0) {
                printf("%d\n", getnum(pos));
            }
            else {
                int num = getnum(pos);
                int ans = 0;
                forn(i,0,fenbig.size()) if(fenbig[i].get(pos) >= num) ans++;
                if(num < B) ans += fensm[num].get(pos);
                printf("%d\n", ans);
            }
        }
    }
    
    
}