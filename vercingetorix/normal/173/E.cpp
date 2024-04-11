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
    
    T get(int l, int r) {
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};

class stree {
public:
    vi t;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n, 0);
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  max(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  max(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(r, n);
    readv(a, n);
    vpi as, rs;
    forn(i,0,n) {
        as.pb(mp(a[i], i));
        rs.pb(mp(r[i], i));
    }
    srt(as);
    srt(rs);
    vi aloc(n);
    forn(i,0,n) aloc[as[i].second] = i;
    fenwick<int> bage(n);
    int pt = 0;
    vi gs(n,0);
    while(pt < n) {
        int pr = pt+1;
        while(pr < n && rs[pr].first == rs[pt].first) pr++;
        forn(i,pt,pr) bage.modify(aloc[rs[i].second], 1);
        forn(i,pt,pr) {
            int curage = a[rs[i].second];
            int r = (lower_bound(all(as), mp(curage+k+1,0)) - as.begin()) - 1;
            int l = (lower_bound(all(as), mp(curage-k,0)) - as.begin());
            gs[rs[i].second] = bage.get(l, r);
        }
        pt = pr;
    }
//    forn(i,0,n) printf("%d\n", gs[i]);
    stree st;
    st.build(n, 1, 0, n-1);
    reverse(all(rs));
    int m;
    scanf("%d", &m);
    vi ans(m, -1);
    vpi q;
    vi x(m), y(m);
    forn(i,0,m) {
        scanf("%d %d", &x[i], &y[i]);
        x[i]--;
        y[i]--;
        q.pb(mp(max(r[x[i]], r[y[i]]), i));
    }
    srtrev(q);
    pt = 0;
    for(auto cur : q) {
        while(pt < n && rs[pt].first >= cur.first) {
            int ind = rs[pt].second;
            st.update(1, 0, n-1, aloc[ind], gs[ind]);
            pt++;
        }
        int ar = max(a[x[cur.second]], a[y[cur.second]]);
        int al = min(a[x[cur.second]], a[y[cur.second]]);
        int r = (lower_bound(all(as), mp(al+k+1,0)) - as.begin()) - 1;
        int l = (lower_bound(all(as), mp(ar-k,0)) - as.begin());
        int best = st.get(1, 0, n-1, l, r);
        if(best > 0) ans[cur.second] = best;
    }
    forn(i,0,m) printf("%d\n", ans[i]);
    
}