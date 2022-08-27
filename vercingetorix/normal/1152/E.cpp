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

vector<set<pi>> g;

void die() {
    cout<<-1;
    exit(0);
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

const int A = 100500;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

vi ord;
int rep[A];
void dfs(int v) {
    while(!g[v].empty()) {
        auto it = g[v].begin();
        auto cur = *it;
        g[v].erase(it);
        g[cur.first].erase(mp(v, cur.second));
        dfs(cur.first);
        ord.pb(v);
        while(rep[v]) {
            ord.pb(v);
            rep[v]--;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(b,n-1);
    readv(c,n-1);
    CoordinateCompressor comp;
    forn(i,0,n-1) {
        comp.add(b[i]);
        comp.add(c[i]);
    }
    comp.init();
    if(comp.len() > n) die();
    int l = comp.len();
    if(l == 1) {
        forn(i,0,n) printf("%d ", comp.xc[0]);
        exit(0);
    }
    forn(i,0,l) make_set(i);
    forn(i,0,n-1) {
        b[i] = comp.comp(b[i]);
        c[i] = comp.comp(c[i]);
        union_sets(b[i], c[i]);
    }
    forn(i,0,l) if(find_set(i) != find_set(0)) die();
    g.resize(l);
    vi deg(l,0);
    forn(i,0,n-1) {
        if(c[i] == b[i]) rep[b[i]]++;
        else {
            g[b[i]].insert(mp(c[i], i));
            g[c[i]].insert(mp(b[i], i));
        }
        if(b[i] > c[i]) die();
        deg[c[i]]++;
        deg[b[i]]++;
    }
    vi odd;
    forn(i,0,l) if(deg[i]%2) odd.pb(i);
    if(odd.size() > 2) die();
    if(odd.size() == 2) {
        g[odd[0]].insert(mp(odd[1], -1));
        g[odd[1]].insert(mp(odd[0], -1));
    }
    dfs(0);
    if(odd.size() == 2) {
        forn(i,1,ord.size()) {
            if((ord[i] == odd[1] && ord[i-1] == odd[0]) || (ord[i] == odd[0] && ord[i-1] == odd[1])) {
                rotate(ord.begin(), ord.begin() + i, ord.end());
                break;
            }
        }
    }
    else ord.pb(ord[0]);
    forn(i,0,n) printf("%d ", comp.xc[ord[i]]);
    
    
}