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

struct pt {
    long double x, y;
    pt(ld x = 0, ld y = 0) : x(x), y(y) {};
    ld len() {
        return sqrt(x*x+y*y);
    }
    pt operator-(const pt & b) const {
        return pt(x-b.x,y-b.y);
    }
};

struct line {
    long double a, b, c;
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

line sp(pt a, pt b) {
    ld x0 = a.x + b.x;
    ld y0 = a.y + b.y;
    x0/=2;
    y0/=2;
    line ret;
    ret.a = a.x-x0;
    ret.b = a.y-y0;
    ret.c = -ret.a*x0-ret.b*y0;
    return ret;
}

bool isint(ld x) {
    return abs(x - floor(x+0.1)) < 1e-4;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vector<pt> x(3);
    forn(i,0,3) cin>>x[i].x>>x[i].y;
    pt o;
    intersect(sp(x[0],x[1]), sp(x[0],x[2]), o);
//    cout<<o.x<<' '<<o.y;
    vd a;
    forn(i,0,3) a.pb(atan2(x[i].y-o.y, x[i].x-o.x));
    srt(a);
//    cout<<a.size();
    ld ans = 1e18;
    ld r = (o-x[0]).len();
    ld PI = acos(ld(-1));
    ld t1 = (a[1] - a[0])/(2*PI);
    ld t2 = (a[2] - a[1])/(2*PI);
    forn(n,3,101) {
        ld cand = n*r*r/2*sin(2*PI/n);
        if(isint(t1*n) && isint(t2*n)) ans = min(ans,cand);
    }
    printf("%.10lf", (double) ans);
    
    
}