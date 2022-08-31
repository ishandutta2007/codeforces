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
vi x,y;
ll s32(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

ll s3(int i, int j, int k) {
    return s32(x[i], y[i], x[j], y[j], x[k], y[k]);
}

bool cw(int i, int j, int k) {
    return s3(i,j,k) < 0;
}

bool ccw(int i, int j, int k) {
    return s3(i,j,k) > 0;
}

int sgccw(int i, int j, int k) {
    ll r = s3(i, j, k);
    if(r > 0) return 1;
    else if(r < 0) return -1;
    else return 0;
}

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

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0) // if parallel
        return {-(s1.cross(e1, s2) == 0), P(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,h;
    scanf("%d %d", &n, &h);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
    }
    vector<pair<pi, int>> ev;
    x.pb(x[n-1]);
    y.pb(y[n-1]+h);
    forn(i,0,n) ev.pb(mp(mp(x[i] - x[n], y[i] - y[n]), i));
    
    sort(all(ev), [&](const pair<pi, int> & a, const pair<pi, int> & b) {
        //        return a.first.first < b.first.first;
        bool ha = a.first.second > 0 || (a.first.second == 0 && a.first.first > 0);
        bool hb = b.first.second > 0 || (b.first.second == 0 && b.first.first > 0);
        if(ha) {
            if(hb == false) return true;
            if(a.first.second == 0) return b.first.second > 0;
            else if(b.first.second == 0) return false;
            return ll(a.first.first)*b.first.second > ll(b.first.first)*a.first.second;
        }
        else {
            if(hb == true) return false;
            if(a.first.second == 0) return b.first.second < 0;
            else if(b.first.second == 0) return false;
            return ll(a.first.first)*b.first.second > ll(b.first.first)*a.first.second;
        }
    });
//    forn(i,0,n) cout<<ev[i].second<<' ';
    int pt = 0;
    ld ans = 0;
    forn(i,0,n-1) {
        while(ev[pt].second <= i) pt++;
        int ind = ev[pt].second;
        int f = sgccw(n, ind, i);
        int e = sgccw(n, ind, i+1);
        if(f == 1 || (f == 0 && e == 1)) continue;
        else if(f == 0) {
            ans += (Point<ll>(x[i], y[i]) - Point<ll>(x[i+1], y[i+1])).dist();
        }
        else {
            auto res = lineInter(Point<ld>(x[i], y[i]), Point<ld>(x[i+1], y[i+1]), Point<ld>(x[n], y[n]), Point<ld>(x[ind], y[ind]));
            ans += (res.second - Point<ld>(x[i], y[i])).dist();
        }
    }
    printf("%.12lf", (double)ans);
    
    
}