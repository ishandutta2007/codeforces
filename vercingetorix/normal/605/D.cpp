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
const int INF = 1e9;

class stree {
public:
    vpi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = mp(a[tl], tl);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return mp(INF, tl);
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  min(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = mp(new_val, tl);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  min(t[v*2], t[v*2+1]);
        }
    }
};
const int N = 400500;

vpi spell[N];
stree st;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vi a(n),b(n),c(n),d(n);
    CoordinateCompressor comp;
    comp.add(0);
    forn(i,0,n) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        comp.add(a[i]);
        comp.add(b[i]);
        comp.add(c[i]);
        comp.add(d[i]);
    }
    comp.init();
    forn(i,0,n) {
        a[i] = comp.comp(a[i]);
        b[i] = comp.comp(b[i]);
        c[i] = comp.comp(c[i]);
        d[i] = comp.comp(d[i]);
    }
    int m = comp.len();
//    vi dist(n+1,INF);
    vi p(n+1,-1);
    forn(i,0,n) spell[a[i]].pb(mp(b[i], i));
    forn(i,0,m) {srtrev(spell[i]);}
    vi ist;
    forn(i,0,m) {
        if(spell[i].empty()) ist.pb(INF);
        else ist.pb(spell[i].back().first);
    }
    st.build(ist, 1, 0, m-1);
    a.pb(0);
    b.pb(0);
    c.pb(0);
    d.pb(0);
    deque<int> q;
    q.pb(n);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        while(1) {
            auto tr = st.get(1, 0, m-1, 0, c[v]);
            if(tr.first <= d[v]) {
                while(!spell[tr.second].empty() && spell[tr.second].back().first <= d[v]) {
                    p[spell[tr.second].back().second] = v;
                    q.pb(spell[tr.second].back().second);
                    spell[tr.second].pop_back();
                }
                if(spell[tr.second].empty()) ist[tr.second] = INF;
                else ist[tr.second] = spell[tr.second].back().first;
                st.update(1, 0, m-1, tr.second, ist[tr.second]);
            }
            else break;
        }
    }
    if(p[n-1] == -1) printf("-1");
    else {
        vi ans;
        int cur = n-1;
        while(cur!=n) {
            ans.pb(cur);
            cur = p[cur];
        }
        reverse(all(ans));
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ",x+1);
//        printf("YES!");
    }
    
    
}