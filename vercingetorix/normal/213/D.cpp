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

ld PI = acos(ld(-1));

typedef Point<ld> pt;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    pt s(10, 0);
    vector<pt> a(6, pt(0,0));
    forn(i,1,6) {
        a[i] = a[i-1] + s;
        s=s.rotate(2*PI/5);
    }
    pt shift(0,0);
    vector<pt> ans;
    ans.pb(pt(0,0));
    forn(i,0,n) {
        forn(j,1,5) ans.pb(shift + a[j]);
        shift = shift+a[3];
    }
    printf("%d\n", ans.size());
    forn(i,0,ans.size()) {
        printf("%.12lf %.12lf\n", (double)ans[i].x, (double)ans[i].y);
    }
    forn(it,0,n) {
        if(it==0) forn(j,0,5) printf("%d ", j+1);
        else {
            printf("%d", it*4);
            forn(j,1,5) printf(" %d", 1+it*4+j);
        }
        printf("\n");
    }
    vi ord;
    ord.pb(0);
    forn(it,0,n) ord.pb(4*it+3);
    for(int it = n-1; it>=1; it--) {
        ord.pb(4*it+1);
        ord.pb(4*it+4);
        ord.pb(4*it+2);
        ord.pb(4*it-1);
    }
    ord.pb(1);
    ord.pb(4);
    ord.pb(2);
    ord.pb(0);
    for(auto x : ord) printf("%d ", x+1);
    
    
}