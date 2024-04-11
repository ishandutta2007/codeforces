#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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

const int INF = 1e8;
struct sega {
    sega() {};
    sega(int mn, pi mx, int ab2, int c2d) : mn(mn), mx(mx), ab2(ab2), c2d(c2d) {};
    int mn;
    pi mx;
    int ab2;
    int c2d;
};

sega combine(sega l, sega r) {
    if(l.mn == INF) return r;
    else if(r.mn == INF) return l;
    int nab2 = max(max(l.ab2, r.ab2), l.mx.first - 2*r.mn);
    int nc2d = max(max(l.c2d, r.c2d), -2*l.mn + r.mx.first);
    return sega(min(l.mn, r.mn), max(l.mx, r.mx), nab2, nc2d);
}

const sega em(INF,mp(-INF, -1),-INF, -INF);

class stree {
public:
    vector<sega> t;
    vi pp;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            pp = vi(a.size() * 4, 0);
        }
        if (tl == tr) {
            t[v] = sega(a[tl], mp(a[tl],tl), -a[tl], -a[tl]);
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v].mn += pp[v];
        t[v].mx.first += pp[v];
        t[v].ab2 -= pp[v];
        t[v].c2d -= pp[v];
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            pp[v] += val;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    sega get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return em;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        sega ret =  combine(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = combine(t[v*2], t[v*2+1]);
        return ret;
    }
};
int n,q;

stree st;
int diam() {
    sega f = st.get(1, 0, n, 0, n);
    int m = f.mx.second;
    sega l = st.get(1, 0, n, 0, m);
    sega r = st.get(1, 0, n, m, n);
    return max(f.mx.first + l.ab2, f.mx.first + r.c2d);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d %d\n", &n, &q);
    char c[200500];
    scanf("%s", c);
    vi a(1,0);
    n = 2*(n-1);
    forn(i,0,n) if(c[i] == '(') a.pb(a.back() + 1);
    else a.pb(a.back() - 1);
    st.build(a, 1, 0, n);
    printf("%d\n", diam());
    forn(i,0,q) {
        int l,r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        if(l>r) swap(l,r);
        if(c[l] != c[r]) {
            if(c[l] == '(') {
                st.update(1, 0, n, l+1, r, -2);
//                forn(j,l+1,r+1) a[j] -= 2;
            }
            else {
                st.update(1, 0, n, l+1, r, 2);
//                forn(j,l+1,r+1) a[j] += 2;
            }
            swap(c[l], c[r]);
        }
        printf("%d\n", diam());
    }
    
}