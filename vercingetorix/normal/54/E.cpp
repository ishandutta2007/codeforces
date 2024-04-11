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

typedef Point<ll> pt;
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

const double PI = acos(-1);
vector<pt> a;

double ac(int r, int l1, int l) {
    double val = (a[r] - a[l1]).dot(a[l]-a[l1]) / (a[l]-a[l1]).dist() / (a[r]-a[l1]).dist();
    val = min(val, 1.);
    val = max(val, -1.);
    return acos(val);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) scanf("%d %d", &x[i], &y[i]);
    if(cw(0,1,2)) {
        reverse(all(x));
        reverse(all(y));
    }
    forn(i,0,n) a.emplace_back(x[i], y[i]);
    double ans = 1e18;
    
    forn(go,0,2) {
        int r = 0;
        ll curs2 = 0;
        forn(l,0,n) {
            if(r == l) r++;
            if(r == n) r = 0;
            int l1 = (l+1)%n;
            while(1) {
                int r1 = (r+1)%n;
                if((a[l1]-a[l]).dot(a[r1]-a[r]) <= 0) break;
                else {
                    int wr = r;
                    r++;
                    if(r==n) r = 0;
                    curs2 += abs(s3(wr,r,l1));
                }
            }
            if(l1 == r) {
                cout<<0;
                exit(0);
            }
            double d = (a[l1]- a[r]).dist();
            double ang = PI-ac(l, l1, r);
            ans = min(ans, d*d*sin(ang)*cos(ang)-curs2);
            if(l1 != r) {
                int l2 = (l1+1)%n;
                curs2 -= abs(s3(l1,l2,r));
            }
            
        }
        reverse(all(x));
        reverse(all(y));
        reverse(all(a));
        forn(i,0,n) {
            y[i] = -y[i];
            a[i].y = -a[i].y;
        }
    }
    printf("%.10lf", ans/2);
    
}