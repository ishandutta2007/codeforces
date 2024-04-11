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
//#define double long double
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
    ld angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};
typedef Point<ld> pt;
const ld PI = acos(ld(-1));

template<class P>
vector<P> circleLine(P c, ld r, P a, P b) {
    P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
    ld s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
    if (h2 < 0) return {};
    if (h2 == 0) return {p};
    P h = ab.unit() * sqrt(h2);
    return {p - h, p + h};
}

template<class P>
vector<pair<P, P>> tangents(P c1, ld r1, P c2, ld r2) {
    P d = c2 - c1;
    ld dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
    if (d2 == 0 || h2 < 0)  return {};
    vector<pair<P, P>> out;
    for (ld sign : {-1, 1}) {
        P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
        out.push_back({c1 + v * r1, c2 + v * r2});
    }
    if (h2 == 0) out.pop_back();
    return out;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    cout<<cos(16*PI);
//    exit(0);
//    auto xaf = circleLine(pt(0,0), 3, pt(10,0), pt(20,0));
//    exit(0);
    ll xp,yp,vp;
    ll x,y,v,r;
    cin>>xp>>yp>>vp;
    cin>>x>>y>>v>>r;
    if(x == xp && y == yp) {
        cout<<0;
        exit(0);
    }
    Point<ld> p(xp, yp);
    Point<ld> s(x, y);
    ld R = sqrt(ld(xp*xp+yp*yp));
    ld sl = 0;
    ld sr = 1e9+R/v+2*PI*R/vp;
    const ld eps = 1e-12;
    forn(it,0,1000) {
        ld sm = (sl + sr)/2;
        ld ang = sm*vp/R;
        pt fin = p.rotate(ang);
        if((s-fin).dist() < eps) {
            sr = sm;
            continue;
        }
        auto inter = circleLine(pt(0,0), r, s, fin);
        ld tm = sm + 1;
        if(inter.size() < 2) {
            tm  = (s-fin).dist()/v;
        }
        else {
            auto p1 = inter[0];
            ld dist=(s-fin).dist();
            if((s-p1).dist() > dist+eps || (p1-fin).dist()>dist+eps) {
                tm  = (s-fin).dist()/v;
            }
            else {
                auto a = tangents(pt(0,0), r, s, 0);
                auto b = tangents(pt(0,0), r, fin, 0);
                ld md = 1e18;
                tm = (a[0].first-a[0].second).dist() + (b[0].first-b[0].second).dist();
                for(auto g : a) for(auto h : b) {
                    ld len = (g.first - h.first).dist();
                    ang = 2*asin(min(len/(2*r), ld(1)));
                    md = min(md, ang*r);
                }
                tm += md;
                tm/=v;
            }
        }
        if(tm < sm) sr = sm;
        else sl = sm;
    }
    printf("%.12lf", (double)sr);
    
    
}