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
#include <array>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef double ld;
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
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    ld dist() const { return sqrt((ld)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<ll> pt;
typedef Point<ld> ptd;

bool cmp (pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

// returns clockwise??
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

template<class T>
T polygonArea2(vector<Point<T>>& v) {
    if(v.size() <= 2) return 0;
    T a = v.back().cross(v[0]);
    forn(i,0,v.size()-1) a += v[i].cross(v[i+1]);
    return a;
}

const ld PI = acos(ld(-1));
ld ccRadius(const ptd& A, const ptd& B, const ptd& C) {
    return (B-A).dist()*(C-B).dist()*(A-C).dist()/
    abs((B-A).cross(C-A))/2;
}

typedef Point<ll> P;
array<P, 2> hullDiameter(vector<P> S) {
    int n = S.size(), j = n < 2 ? 0 : 1;
    pair<ll, array<P, 2>> res({0, {S[0], S[0]}});
    forn(i,0,j)
    for (;; j = (j + 1) % n) {
        res = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});
        if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0)
            break;
    }
    return res.second;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    ll r;
    scanf("%d %lld", &n, &r);
    if(n==1) {
        cout<<0;
        exit(0);
    }
    vector<pt> a(n);
    forn(i,0,n) {
        double x,y;
        scanf("%lf %lf", &x, &y);
        a[i].x = floor(x*1000+0.5);
        a[i].y = floor(y*1000+0.5);
    }
    convex_hull(a);
    vector<ptd> b;
    reverse(all(a));
    for(auto x : a) b.emplace_back(ld(x.x)/1000, ld(x.y)/1000);
    auto diam = hullDiameter(a);
    int st = 0;
    while(a[st].x != diam[0].x || a[st].y != diam[0].y) st++;
//    for(auto x : a) {
//        cout<<x.x<<' '<<x.y<<'\n';
//    }
//    for(auto x : b) {
////        cout<<x.x<<' '<<x.y<<'\n';
//        printf("%.10lf %.10lf\n", (double)x.x, (double)x.y);
//    }
    
    auto seg = [&](ptd & p1, ptd & p2) {
        ld len = (p1-p2).dist();
        ld alpha = asin(min(len/(2*r), ld(1)));
        return r*(alpha*r - len/2*cos(alpha));
    };
    forn(it,0,100) {
        int bad = 0;
        vector<ptd> nb;
        int st = gen()%b.size();
//        for(auto p : b) {
        forn(i,0,b.size()) {
            auto p = b[st];
            st++;
            if(st == b.size()) st = 0;
            while(nb.size() >= 2) {
                auto p1 = nb[nb.size() - 1];
                auto p2 = nb[nb.size() - 2];
                if((p1-p).dot(p1-p2) < 0 && ccRadius(p1, p, p2) > r+1e-12) nb.pop_back();
                else break;
            }
            nb.pb(p);
        }
        swap(b,nb);
    }

    ld ans = abs(polygonArea2(b)/2);
            forn(i,0,b.size()) {
                ans += seg(b[i], b[(i+1)%b.size()]);
            }
        printf("%.12lf", (double)ans);
        exit(0);
    
}