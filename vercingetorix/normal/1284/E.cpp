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
typedef std::vector<long double> vd;
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

struct pt {
    pt(ll x, ll y, int ind) : x(x), y(y), ind(ind) {};
    ll x, y;
    int ind;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vll x, y;
//    vector<pt> p;
    forn(i,0,n) {
        int xx,yy;
        scanf("%d %d", &xx, &yy);
        x.pb(xx);
        y.pb(yy);
//        p.pb(pt(xx, yy, i));
    }
    ld pi = acos(ld(-1));
    ll dif = 0;
    ll sam = 0;
    forn(i,0,n) {
        vd u, d;
        forn(j,0,n) if(j != i) {
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            ld ang = acos(ld(dx) / sqrt(dx*dx + dy * dy));
            if(dy > 0 || (dy == 0 && dx > 0)) u.pb(ang);
            else d.pb(pi - ang);
        }
        srt(u);
        srt(d);
        int r = 0;
        forn(l,0,u.size()) {
            while(r < d.size() && d[r] < u[l]) r++;
            ll b = d.size() - r + l;
            ll a = u.size() - l - 1 + r;
            dif += a*b;
            sam += a*(a-1)/2 + b*(b-1)/2;
        }
    }
    ll numt = (2*dif - sam)/3;
    
//    vector<pt> q = p;
//    vi taken(n, 0);
//    ll numt = 0;
//    forn(i,0,n-2) {
//        p.clear();
//        forn(j,0,n) if(taken[j] == 0) p.pb(q[j]);
//        convex_hull(p);
////        forn(j,0,n) {
////            if(taken[j]) continue;
////            if(j == p[0].ind || j==p[1].ind || j == p[2].ind) continue;
////            if(cw(p[2], p[0], q[j])) numt++;
////        }
//        numt += n-i-p.size();
//        taken[p[0].ind] = 1;
//    }
    ll ans = numt*(n-4)/2;
//
//
////    for(auto x : p) ins[x.ind] = 0;
////    int k = p.size();
////    ll ans = 0;
//
////    forn(i,0,n) if(ins[i]) {
////        int l = 0;
////        int r = 0;
////        ll numt = 0;
////        forn(l,0,n) {
////            while(r==l || cw(p[l], p[r], q[i])) r = (r+1)%k;
////            ll cur = r-l;
////            if(cur < 0) cur+=k;
////            numt += cur;
////        }
////        ans += numt*(n-4)/2;
//    }
    cout<<ans;
    
    
}