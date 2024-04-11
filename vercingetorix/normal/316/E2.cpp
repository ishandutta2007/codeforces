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

const long long mod = 1000000000;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

struct m2 {
    m2() {forn(i,0,2) forn(j,0,2) x[i][j] = 0;};
    ll x[2][2];
};

m2 prod(m2 a, m2 b) {
    m2 c;
    forn(i,0,2) forn(j,0,2) {
        c.x[i][j] = (a.x[i][0]*b.x[0][j]+a.x[i][1]*b.x[1][j])%mod;
    }
    return c;
}

void mul(m2 & a, ll x) {
    forn(i,0,2) forn(j,0,2) a.x[i][j] = (a.x[i][j]*x)%mod;
}

m2 sum(m2 a, m2 b) {
    m2 c;
    forn(i,0,2) forn(j,0,2) {
        c.x[i][j] = (a.x[i][j]+b.x[i][j])%mod;
    }
    return c;
}

vector<m2> fp;
vector<m2> fpinv;

class stree {
public:
    vector<m2> t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr) {
            t[v] = fp[tl];
            mul(t[v], a[tl]);
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = sum(t[v*2], t[v*2+1]);
        }
    }
    
    void set (int v, int tl, int tr, int pos, int val) {
        if (pos == tl && tr == pos) {
            t[v] = fp[tl];
            mul(t[v], val);
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos,val);
            else set(v*2+1, tm+1, tr, pos,val);
            t[v] = sum(t[v*2], t[v*2+1]);
        }
    }
    
    m2 get (int v, int tl, int tr, int l, int r) {
        if(l>r) return m2();
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return sum(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
};

const int A = 200100;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    m2 fib;
    m2 finv;
    finv.x[0][0] = mod-1; finv.x[0][1] = 1;
    finv.x[1][0] = 1; finv.x[1][1] = 0;
    fib.x[0][0] = 0; fib.x[0][1] = 1;
    fib.x[1][0] = 1; fib.x[1][1] = 1;
    fp.resize(2);
    fpinv.resize(2);
    fp[0].x[0][0] = 1; fp[0].x[1][1] = 1;
    fp[0].x[0][1] = 0; fp[0].x[1][0] = 0;
    fp[1] = fib;
    fpinv[1] = finv;
    fpinv[0] = fp[0];
    m2 cur = fib;
    m2 curi = finv;
    forn(i,2,A+1) {
        cur = prod(cur, fib);
        curi = prod(curi, finv);
        fp.pb(cur);
        fpinv.pb(curi);
    }
    
    int n,m;
    scanf("%d %d", &n, &m);
    vi a(n);
    stree st;
    forn(i,0,n) scanf("%d", &a[i]);
    st.build(a, 1, 0, n-1);
    forn(i,0,m) {
        int t,x,y;
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1) {
            st.set(1, 0, n-1, x-1,y);
        }
        else if(t==2) {
            x--; y--;
            m2 res = st.get(1, 0, n-1, x, y);
            res = prod(res, fpinv[x]);
            ll ans = res.x[0][0] + res.x[1][0];
//            forn(j,0,y-x+1) ans += (f[j]*ll(a[x+j]))%mod;
            printf("%lld\n", ans%mod);
        }
    }
}