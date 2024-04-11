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
typedef std::vector<ld> vd;
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

struct Line {
    mutable ld k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ld inf = 1/.0;
    ld div(ld a, ld b) { // floored division
        return a/b; }
//        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ld k, ld m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ld query(ld x) {
        //        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
    
    ld over(ld x) {
        return lower_bound(x)->p;
    }
    
    pair<ld, ld> pos(ld x) {
        auto l = *lower_bound(x);
        return mp(-l.k, -l.m);
    }
};
const ld eps = 1e-12;

bool equ(pair<ld, ld> a, pair<ld, ld> b) {
    return abs(a.first - b.first) < eps && abs(a.second - b.second) < eps;
}

ld stepk(ld x, ll k, pair<ld, ld> op) {
    return pow(1-op.first, k)*x + op.second/(1-op.first)*(1-pow(op.first, k));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    LineContainer aa;
//    auto u = aa.lower_bound(ld(100));
//    auto v = aa.begin();
//    cout<<u-v;
//    exit(0);
    
    int n;
    ll t;
    scanf("%d %lld", &n, &t);
    vi a(n), b(n);
    vector<double> p(n);
    forn(i,0,n) scanf("%d %d %lf", &a[i], &b[i], &p[i]);
    ld M = 0;
    forn(i,0,n) M = max(M, (ld)p[i]*b[i]);
    vector<pair<ld, ld>> wab;
    LineContainer lc;
    forn(i,0,n) {
        lc.add(p[i]-1, -M+p[i]*a[i]);
    }
    ll curt = 0;
    ld Mn = 0;
    vll d2(1,1);
    forn(i,0,40) d2.pb(d2.back() * 2);
    while(curt < t) {
//        curt++;
//        Mn=-lc.query(Mn);
//        continue;
//        return pow(1-op.first, k)*x + op.second/(1-op.first)*(1-pow(op.first, k));
        
        pair<ld, ld> op = lc.pos(Mn);
        ld fill = lc.over(Mn);
        vd pop(1,1-op.first);
        vd pp(1,op.first);
        forn(i,1,36) pop.pb(pop.back()*pop.back());
        forn(i,1,36) pp.pb(pp.back()*pp.back());
        for(int i = 35; i>=0; i--) {
            if(curt+d2[i] > t) continue;
            ld nx = pp[i] * Mn + op.second/pop[0] * (1-pp[i]);
//            if(equ(lc.pos(nx), op)) {
            if(nx < fill) {
                Mn = nx;
                curt += d2[i];
            }
        }
        if(curt < t) {
            ld nx = pp[0] * Mn + op.second/pop[0] * (1-pp[0]);
            Mn = nx;
            curt++;
        }
//        ll l = curt;
//        ll r = t + 1;
//        while(r-l > 1) {
//            ll m = (r+l)/2;
//            ld nx = stepk(Mn, m-curt, op);
//            if(equ(lc.pos(nx), op)) l = m;
//            else r = m;
//        }
//        if(r>t) r= t;
//        Mn = stepk(Mn, r-curt, op);
//        curt = r;
    }
    printf("%.12lf", (double)(t*M-Mn));
//    srt(wab);
    
    
}