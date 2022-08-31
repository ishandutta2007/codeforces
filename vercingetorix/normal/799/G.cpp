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
typedef std::pair<ld, ld> pld;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int A = 10000;
const ld PI = acos((ld)-1);
const ld PI2 = 2*PI;

int gacnt = 0;

struct pt {
    pt() {};
    pt(ld x, ld y) : x(x), y(y) {};
    ld x, y;
};

inline bool cclockw(const pt & a, const pt & b) {
    return a.x*b.y > a.y*b.x;
}
pt u,v;
ld getalpha(ll x, ll y) {
    ld res = atan2(y, x);
    if(res < 0) res+= PI2;
    return res;
}

vi x,y;
int n,q;

ld getdarea (ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
    return abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));;
}
int gincnt = 0;
int ccheck = 0;
int totcheck = 0;
int ck0check = 0;
int getind(ll px, ll py, pt val) {
    gincnt ++;
    int l = 0;
    int r = n;
    pt vl, vr;
    vl.x = x[0] - px;
    vl.y = y[0] - py;
    vr.x = x[0] - px;
    vr.y = y[0] - py;
    int ck = 1;
    if (cclockw(val, vr)) ck = 2;
    int did = 0;
    while (r-l>1) {
        int m = (r+l)/2;
        pt vm;
        vm.x = x[m] - px;
        vm.y = y[m] - py;
        if(ck == 1) {
            if(cclockw(vl, vm) && cclockw(vm, val)) {
                l = m;
                vl = vm;
            }
            else {
                r = m;
                vr = vm;
            }
        }
        else if(ck == 2) {
            if(cclockw(val, vm) && cclockw(vm, vr)) {
                r = m;
                vr = vm;
            }
            else {
                l = m;
                vl = vm;
            }
        }
    }
    return l;
}

int getind(ll px, ll py, ld alpha) {
    pt val;
    val.x = cos(alpha);
    val.y = sin(alpha);
    return getind(px, py, val);
}


struct line {
    ld a, b, c;
};

const ld EPS = 1e-12;

ld det (ld a, ld b, ld c, ld d) {
    return a * d - b * c;
}

bool intersect (line m, line n, pt & res) {
    ld zn = det (m.a, m.b, n.a, n.b);
    if (abs (zn) < EPS)
        return false;
    res.x = - det (m.c, m.b, n.c, n.b) / zn;
    res.y = - det (m.a, m.c, n.a, n.c) / zn;
    return true;
}

pt pint(ll px, ll py, pt vec, int i) {
    ld x0 = x[i];
    ld y0 = y[i];
    ld dx = x[(i+1)%n] - x0;
    ld dy = y[(i+1)%n] - y0;
    pt res;
    line li;
    li.a = dy;
    li.b = -dx;
    li.c = -dy*x0 + dx*y0;
    line luch;
    luch.a = vec.y;
    luch.b = -vec.x;
    luch.c = -luch.a*px - luch.b*py;
    intersect(li, luch, res);
    return res;
}

pt pint(ll px, ll py, ld alpha, int i) {
    pt vec;
    vec.x = cos(alpha);
    vec.y = sin(alpha);
    return pint(px, py, vec, i);
}
ld total = 0;

ll area[A][A/5];

ld segsum(int from, int to) {
    ld res = 0;
    int cover = to - from;
    if(cover < 0) cover += n;
    int cur = from;
    while(cover > 0) {
        int st = min(cover, A/5-1);
        res += area[cur%n][st];
        res += getdarea(x[from], y[from], x[cur%n], y[cur%n], x[(cur+st)%n], y[(cur+st)%n]);
        cur += st;
        cover -= st;
    }
    return res;
}

ld getard(ll px, ll py, pt v, int i1, int i2) {
    pt vop(-v.x, -v.y);
    pt li1 = pint(px, py, v, i1);
    pt li2 = pint(px, py, vop, i2);
    ld up = segsum((i1+1)%n, i2) + getdarea(li1.x, li1.y, x[i2], y[i2], li2.x, li2.y) +
    getdarea(li1.x, li1.y, x[i2], y[i2], x[(i1+1)%n], y[(i1+1)%n]);
    return 2*up - total;
}

ld getard(ll px, ll py, ld alpha, int i1, int i2) {
    pt vec(cos(alpha), sin(alpha));
    return getard(px, py, vec, i1, i2);
}

pair<ld, int> getardv(ll px, ll py, int v) {
    pt val;
    val.x = px - x[v];
    val.y = py - y[v];
    int i2 = getind(px, py, val);
    pt li1(x[v], y[v]);
    pt li2 = pint(px, py, val, i2);
    ld up = segsum(v, i2) + getdarea(li1.x, li1.y, x[i2], y[i2], li2.x, li2.y);
    return mp(2*up - total,i2);
}


ll getarea (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

double solve(int qx, int qy) {
    int vl, vr;
    auto t0 = getardv(qx, qy, 0);
    int i2 = t0.second;
    pt vecl, vecr;
    vecl = pt(x[0] - qx, y[0] - qy);
    vecr = pt(qx - x[0], qy - y[0]);
    if (t0.first < 0) {
        vl = 0;
        vr = i2+1;
    }
    else {
        vl = i2;
        vr = n;
        swap(vecl, vecr);
    }
    while(vr - vl > 1) {
        int vm = (vr+vl)/2;
        if(getardv(qx, qy, vm).first > 0) {
            vr = vm;
            vecr = pt(x[vm] - qx, y[vm] - qy);
        }
        else {
            vl = vm;
            vecl = pt(x[vm] - qx, y[vm] - qy);
        }
    }
    int ind1 = vl;
    pt avecl(-vecl.x, -vecl.y);
    pt avecr(-vecr.x, -vecr.y);
    int nl = getind(qx, qy, avecl);
    int nr = getind(qx, qy, avecr) + 1;
    if(nr <= nl) nr += n;
    while(nr - nl > 1) {
        int nm = (nr + nl) / 2;
        if(getardv(qx, qy, nm%n).first < 0) {
            nr = nm;
            avecr = pt(x[nm%n] - qx, y[nm%n] - qy);
        }
        else {
            nl = nm;
            avecl = pt(x[nm%n] - qx, y[nm%n] - qy);
        }
    }
    int ind2 = nl%n;
    ld al = getalpha(-avecl.x, -avecl.y);
    ld ar = getalpha(-avecr.x, -avecr.y);
    if(ar < al) ar += PI2;
    forn(it,0,50) {
        ld am = (al+ar)/2;
        if(getard(qx, qy, am, ind1, ind2) > 0) ar = am;
        else al = am;
        
    }
    while(al > PI) al-=PI;
    return double(al);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &q);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
    }
    reverse(all(x));
    reverse(all(y));
    forn(st,2,A/5) {
        forn(i,0,n) {
            int i2 = (i+st-1)%n;
            int i3 = (i+st)%n;
            area[i][st] = area[i][st-1] + abs(getarea(x[i], y[i], x[i2], y[i2], x[i3], y[i3]));
        }
    }
    forn(st,2,n) {
        total += abs(getarea(x[0], y[0], x[st-1], y[st-1], x[st], y[st]));
    }
    forn(i,0,q) {
        ll qx, qy;
        scanf("%lld %lld", &qx, &qy);
        printf("%.15lf\n", solve(qx, qy));
    }
}