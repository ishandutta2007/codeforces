#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int INF = 2e9;
class stree {
public:
    int s;
    vpi t;
    vi lazy;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            s = a.size();
            t.resize(4*s);
            lazy.resize(4*s);
        }
        if (tl == tr) {
            t[v] = mp(a[tl], tl);
            lazy[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            lazy[v] = 0;
            t[v] = min(t[v*2], t[v*2 + 1]);
        }
    }
    
    void push(int v) {
        if (lazy[v] == 0) return;
        t[v].first += lazy[v];
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int add) {
        push(v);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = min(t[v*2], t[v*2 + 1]);
        }
    }
    
    pi gmin (int v, int tl, int tr, int l, int r) {
        push(v);
        if (l > r)
            return mp(INF, 0);
        if (l == tl && tr == r) {
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            pi ret = min(gmin(v*2, tl, tm, l, min(r,tm)),
                         gmin(v*2+1, tm+1, tr, max(l,tm+1), r));
            t[v] = min(t[v*2], t[v*2 + 1]);
            return ret;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    vi x(k), y(k);
    forn(i,0,k) {
        scanf("%d %d", &x[i], &y[i]);
        x[i] -- ; y[i] --;
    }
    int l = 0;
    int r = max(m,n);
    while(r-l > 0) {
        int med = (r+l)/2;
        set<int> vx, vy;
        for(auto cx : x) {
            if(cx-med-1 >= 0) vx.insert(cx-med-1);
            if(cx-med >= 0) vx.insert(cx-med);
            if(cx+med <n) vx.insert(cx+med);
            if(cx+med+1 <n) vx.insert(cx+med+1);
        }
        for(auto cx : y) {
            if(cx-med-1 >= 0) vy.insert(cx-med-1);
            if(cx-med >= 0) vy.insert(cx-med);
            if(cx+med <m) vy.insert(cx+med);
            if(cx+med+1 <m) vy.insert(cx+med+1);
        }
        vx.insert(0);
        vx.insert(n-1);
        vy.insert(0);
        vy.insert(m-1);
        map<int, int> xcond;
        map<int, int> ycond;
        int xnum=0, ynum=0;
        vi vvx, vvy;
        for(auto x : vx) vvx.pb(x);
        for(auto x : vy) vvy.pb(x);
        for(auto x : vx) xcond[x] = xnum++;
        for(auto x : vy) ycond[x] = ynum++;
        vector<pair<pi, pi>> evx;
        vector<pair<pi, pi>> evy;
        forn(i,0,k) {
            evx.pb(mp(mp(max(x[i]-med,0), 1), mp(ycond[max(y[i]-med,0)], ycond[min(y[i]+med,m-1)])));
            evx.pb(mp(mp(max(x[i]+med+1,0),-1), mp(ycond[max(y[i]-med,0)], ycond[min(y[i]+med,m-1)])));
            evy.pb(mp(mp(max(y[i]-med,0), 1), mp(xcond[max(x[i]-med,0)], xcond[min(x[i]+med,n-1)])));
            evy.pb(mp(mp(max(y[i]+med+1,0),-1), mp(xcond[max(x[i]-med,0)], xcond[min(x[i]+med,n-1)])));
        }
        sort(all(evx));
        sort(all(evy));
        vi a1(ynum,0);
        vi a2(xnum,0);
        stree st1;
        stree st2;
        st1.build(a1, 1, 0, ynum-1);
        st2.build(a2, 1, 0, xnum-1);
        int ptx = 0;
        int pty = 0;
        int xl = INF;
        int xr = -INF;
        int yl = INF;
        int yr = -INF;
        forn(i,0,xnum) {
            while(ptx<evx.size() && evx[ptx].first.first == vvx[i]) {
                st1.update(1, 0, ynum-1, evx[ptx].second.first, evx[ptx].second.second, evx[ptx].first.second);
                ptx++;
            }
            if(st1.gmin(1, 0, ynum-1, 0, ynum-1).first == 0) {
                xl = min(xl, vvx[i]);
                xr = max(xr, vvx[i]);
            }
        }
        forn(i,0,ynum) {
            while(pty<evy.size() && evy[pty].first.first == vvy[i]) {
                st2.update(1, 0, xnum-1, evy[pty].second.first, evy[pty].second.second, evy[pty].first.second);
                pty++;
            }
            if(st2.gmin(1, 0, xnum-1, 0, xnum-1).first == 0) {
                yl = min(yl, vvy[i]);
                yr = max(yr, vvy[i]);
            }
        }
        int cand = 0;
        if(xl < INF) {
            cand = max((xr-xl+1)/2, (yr-yl+1)/2);
        }
        if (r-l == 1) {
            cout<<min(cand,r);
            return 0;
        }
        if(cand >= med) {
            l = med;
        }
        else {
            r = med;
        }
    }
    
    
}