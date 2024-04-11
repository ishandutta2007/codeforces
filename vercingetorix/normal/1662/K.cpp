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
#define sz(c) c.size()
const double PI = acos(-1);
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
    double dist() const { return sqrt((double)dist2()); }
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

typedef Point<double> pt;

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0) // if parallel
        return {-(s1.cross(e1, s2) == 0), P(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}

template<class P>
int sideOf(const P& s, const P& e, const P& p, ll eps) {
    auto a = (e-s).cross(p-s);
    double l = (e-s).dist()*eps;
    return (a > l) - (a < -l);
}


double get(const pt & a1, pt & b, pt & c) {
    vector<pt> a = {a1,b,c};
    forn(i,0,3) {
        int j = (i+1)%3;
        int k = (i+2)%3;
        if((a[i]-a[j]).dot(a[i]-a[k])/(a[i]-a[j]).dist()/(a[i]-a[k]).dist() <= cos(PI*2/3)) {
            return (a[i]-a[j]).dist() + (a[i]-a[k]).dist();
        }
    }
    pt b1 = (a[0] + a[2])/2 + (a[0]-a[2]).rotate(PI/2)*sin(PI/3);
    pt b2 = (a[0] + a[1])/2 + (a[0]-a[1]).rotate(PI/2)*sin(PI/3);
    if(sideOf(a[0], a[2], b1, 0) == sideOf(a[0], a[2], a[1], 0)) b1 = a[0]+a[2]-b1;
    if(sideOf(a[0], a[1], b2, 0) == sideOf(a[0], a[1], a[2], 0)) b2 = a[0]+a[1]-b2;
    auto ret = lineInter(a[1], b1, a[2], b2);
    return (ret.second-a[0]).dist() + (ret.second-a[1]).dist() + (ret.second-a[2]).dist();
}

double get(const pt & mid, vector<pt> & a) {
    return max({get(mid, a[0], a[1]), get(mid, a[2], a[1]), get(mid, a[0], a[2])});
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vector<pt> a;
    forn(i,0,3) {
        int x,y;
        cin>>x>>y;
        a.emplace_back(x,y);
    }
    forn(i,0,3) {
        int j = (i+1)%3;
        int k = (i+2)%3;
        if((a[i]-a[j]).dot(a[i]-a[k]) <= 0) {
            printf("%.10lf\n", (a[j]-a[k]).dist());
            exit(0);
        }
    }
    double step = 0.000001;
    int k = 24;
    pt cur = (a[0]+a[1]+a[2])/3;
    double best = get(cur, a);
    while(1) {
        pair<double, int> ans(0, -1);
        forn(rot,0,k) {
            double cand = get(cur + pt(step,0).rotate(PI*2/k*rot), a);
            ans = max(ans, mp(best-cand, rot));
        }
        if(ans.first > 0) {
            double l = 0;
            double r = 1e11;
            pt base = pt(step,0).rotate(PI*2/k*ans.second);
            forn(it,0,100) {
                double m = (l+r)/2;
                if(get(cur + base*(m+1), a) < get(cur+base*m, a)) l = m;
                else r = m;
            }
            cur = cur + base*(l+0.5);
            best = get(cur,a);
        }
        else break;
    }
    printf("%.10lf\n", best);
    
    
}