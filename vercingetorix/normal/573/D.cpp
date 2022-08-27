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
const int A = 30000;

ll av[A];
ll bv[A];
int p[A];
const ll INF = 1e18;
struct sega {
    ll d[3][3];
    int l,r;
    sega(int pos = -1) : l(pos), r(pos) {
        forn(i,0,3) forn(j,0,3) d[i][j] = -INF;
        if(pos != -1) {
            d[1][0] = 0;
            d[0][1] = 0;
            d[1][1] = 0;
            if(p[pos] != pos) d[0][0] = av[pos] * bv[pos];
        }
    }
};

sega combine(const sega & a, const sega & b) {
    if(a.l == -1) return b;
    if(b.r == -1) return a;
    sega ret;
    ret.l = a.l;
    ret.r = b.r;
    int lena = a.r-a.l+1;
    int lenb = b.r-b.l+1;
    forn(ra,1,3) forn(lb,1,3) {
        if(ra + lb > 3) continue;
        ll add = -1;
        if(ra + lb == 2) {
            if(p[a.r] != b.l && p[b.l] != a.r) add = av[a.r]*bv[b.l] + av[b.l]*bv[a.r];
        }
        else {
            int l = b.l-ra;
            int r = a.r+lb;
            if(p[l] != l+1 && p[l+1] != r && p[r] != l) add=max(add, av[l]*bv[l+1] + av[l+1]*bv[r] + av[r]*bv[l]);
            if(p[r] != l+1 && p[l+1] != l && p[l] != r) add=max(add, av[r]*bv[l+1] + av[l+1]*bv[l] + av[l]*bv[r]);
        }
        if(add<0) continue;
        forn(la,0,min(3, lena+1-ra)) forn(rb,0,min(3, lenb+1- lb)) {
            if(a.d[la][ra] >= 0 && b.d[lb][rb] >= 0) {
                ret.d[la][rb] = max(ret.d[la][rb], a.d[la][ra] + b.d[lb][rb] + add);
            }
        }
    }
    forn(la,0,min(3, lena+1)) forn(rb,0,min(3, lenb+1)) {
        if(a.d[la][0] >= 0 && b.d[0][rb] >= 0) {
            ret.d[la][rb] = max(ret.d[la][rb], a.d[la][0] + b.d[0][rb]);
        }
    }
    if(lena == 1) {
        forn(rb,0,min(3, lenb)) {
            if(b.d[1][rb] >= 0) ret.d[2][rb] = max(ret.d[2][rb], b.d[1][rb]);
        }
    }
    if(lenb == 1) {
        forn(la,0,min(3, lena)) {
            if(a.d[la][1] >= 0) ret.d[la][2] = max(ret.d[la][2], a.d[la][1]);
        }
    }
    return ret;
}
int n;
class stree {
public:
    vector<sega> t;
    int s;
    void build (int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
        }
        if (tl == tr)
            t[v] = sega(tl);
        else {
            int tm = (tl + tr) / 2;
            build (v*2, tl, tm);
            build (v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    sega get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  combine(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos) {
        if (tl == tr)
            t[v] = sega(tl);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos);
            else
                update (v*2+1, tm+1, tr, pos);
            t[v] =  combine(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    readv(b,n);
    vpi ai;
    forn(i,0,n) ai.pb(mp(a[i], i));
    srtrev(ai);
    vpi bi;
    forn(i,0,n) bi.pb(mp(b[i], i));
    srtrev(bi);
    forn(i,0,n) {
        av[i] = ai[i].first;
        bv[i] = bi[i].first;
    }
    vi orda(n);
    forn(i,0,n) orda[ai[i].second] = i;
    vi ordb(n);
    forn(i,0,n) ordb[bi[i].second] = i;
    forn(i,0,n) p[orda[i]] = ordb[i];
//    forn(i,0,n) cout<<p[i]<<' ';
    stree st;
    st.build(1, 0, n-1);
    while(m--) {
        int u,v;
        scanf("%d %d", &u, &v);
        u = orda[u-1];
        v = orda[v-1];
        swap(p[u], p[v]);
        st.update(1, 0, n-1, u);
        st.update(1, 0, n-1, v);
        printf("%lld\n", st.t[1].d[0][0]);
    }
}