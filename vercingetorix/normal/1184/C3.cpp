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

typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
    return (B-A).dist()*(C-B).dist()*(A-C).dist()/
    abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}


typedef Point<double> pt;

double frand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

typedef pair<pt, double> Disk;

Disk getdisk(pt &a , pt&b, pt&c) {
    return mp(ccCenter(a, b, c), ccRadius(a, b, c));
}

const double RDISK = 1000000;
const double RMIN = 250000;
const double RMAX = 750000;
const double INF = 1e18;
const double MINHAUS = 600000;
const double MAXERROR = 100000;
const double PI = acos((double)-1);

double diskdist(Disk a, Disk b) {
    double d = (a.first - b.first).dist();
    double ret = 0;
    for(auto s1 : {-1,1}) for(auto s2 : {-1,1}) ret = max(ret, min(abs(d+s1*a.second+s2*b.second), abs(d+s1*a.second-s2*b.second)));
    return ret;
}

bool checkwin(const vector<Disk> & a, const vector<Disk> & b) {
    if(a.size() != b.size()) return false;
    vi to;
    forn(i,0,a.size()) to.pb(i);
    do {
        int good = 1;
        forn(i,0,a.size()) if(diskdist(a[i], b[to[i]]) > MAXERROR) {
            good = 0;
            break;
        }
        if(good) return true;
    } while(next_permutation(all(to)));
    return false;
}

vector<Disk> genrings(int k) {
    vector<Disk> ret;
    forn(it,0,k) {
        while(1) {
            auto x = frand(0,RDISK);
            auto y = frand(0,RDISK);
            if(x*x+y*y>RDISK*RDISK) continue;
            auto r = frand(RMIN, RMAX);
            pair<pt, double> disk = mp(pt(x,y), r);
            int good = 1;
            for(auto & disk2 : ret) if(diskdist(disk2, disk) < MINHAUS) good = 0;
            if(good) {
                ret.pb(disk);
                break;
            }
        }
    }
    return ret;
}

pt getRandom(const Disk & disk) {
    double phi = frand(0, 2*PI);
    double r = frand(disk.second*0.9, disk.second*1.1);
    return disk.first + pt(r,0).rotate(phi);
}

vector<pt> genPoints(const vector<Disk> & disks, int n) {
    vector<pt> ret;
    for(auto & disk : disks) forn(i,0,n) ret.pb(getRandom(disk));
    return ret;
}

void print(Disk & a) {
    printf("%.0lf %.0lf %.0lf\n", a.first.x, a.first.y, a.second);
}

vector<pair<pt, double>> solve(int n, int k, vector<pt> a) {
    vector<Disk> cand;
    double dneed = 250000;
    double dmax = 1500000;
    int num = 15000;
    forn(it,0,num) {
        while(1) {
            int i = gen()%a.size();
            int j = gen()%a.size();
            if(j==i || (a[i]-a[j]).dist() < dneed || (a[i]-a[j]).dist() > dmax) continue;
            int h = gen()%a.size();
            if(i == h || j == h || (a[i]-a[h]).dist() < dneed || (a[j]-a[h]).dist()<dneed || (a[i]-a[h]).dist() > dmax || (a[h]-a[j]).dist() > dmax ) continue;
            cand.pb(getdisk(a[i], a[j], a[h]));
            break;
        }
    }
    vpi best;
    double dc = MAXERROR/4;
    forn(i,0,num) {
        int cnt = 0;
        forn(j,0,num) if(diskdist(cand[j], cand[i]) < dc) cnt++;
        best.pb(mp(cnt, i));
    }
    srtrev(best);
    vector<Disk> ans;
    for(auto x : best) {
        Disk cur = cand[x.second];
        int bad = 0;
        for(auto y : ans) if(diskdist(cur, y) < 2*MINHAUS/4) {
            bad = 1;
            break;
        }
        if(bad == 0) ans.pb(cur);
        if(ans.size() == k) break;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    forn(it,0,2) {
//        int k = 3;
//        int n = 104;
//
//        vector<Disk> ans = {mp(pt(-382229.2871075071, 396672.8404605993), 251370.7186075198),
//            mp(pt(657206.6118908568, -200595.6975323943), 369429.6485299009),
//            mp(pt(382519.13553853927, -544835.8029023121), 543421.4450888853)};
//        auto p = genPoints(ans, n);
//        auto test = solve(n, k, p);
//        cout<<it<<' '<<checkwin(ans, test)<<'\n';
//    }
//    exit(0);
//    forn(it,0,3) {
//        int k = 1+gen()%4;
//        int n = 100+gen()%901;
////        int k = 1;
////        int n = 1000;
//        auto ans = genrings(k);
//        auto p = genPoints(ans, n);
//        auto test = solve(n, k, p);
////        print(ans[0]);
////        print(test[0]);
//        cout<<n<<' '<<k<<' '<<checkwin(ans, test)<<'\n';
//    }
    int n,k;
    cin>>k>>n;
    vector<pt> p;
    forn(i,0,n*k) {
        int x,y;
        cin>>x>>y;
        p.pb(pt(x,y));
    }
    auto ans = solve(n,k,p);
    for(auto x : ans) print(x);
    
}