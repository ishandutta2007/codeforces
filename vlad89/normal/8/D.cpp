#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

typedef double cfloat;
const cfloat eps = 1e-10;
const cfloat pi = 2 * acos(0.0);
#define sqr(x) ((x)*(x))
#define Sqrt(x) (((x)<eps) ? 0 : sqrt(x)) 

inline int cmp(cfloat q, cfloat w) {
    return (q < w + eps) ? (q > w - eps) ? 0 : -1 : 1;
}
struct point {
    cfloat x, y;
    point (cfloat x, cfloat y): x(x), y(y) {}
    point () { x=y=0.0; }
    point operator + (point q) { return point(x + q.x, y + q.y); }
    point operator - (point q) { return point(x - q.x, y - q.y); }
    point operator * (cfloat t) { return point(x * t, y * t); }
    point operator / (cfloat t) { return point(x / t, y / t); }
    cfloat operator * (point q) { return q.x * x + q.y * y; }
    cfloat operator % (point q) { return x * q.y - y * q.x; }    
    int cmp(point q) const { if (int t = ::cmp(x, q.x)) return t; return ::cmp(y, q.y); }            
    #define Comp(x) bool operator x (point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp (>=) Comp (<=) Comp (!=)     
    #undef Comp
};

inline cfloat abs(point p) { return sqrt(p.x*p.x + p.y*p.y); }  
inline cfloat dist(point a, point b) { return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y)); }

vector<point> intersect_circles(point q, cfloat r1, point w, cfloat r2) {
    vector <point> res;
    cfloat d = dist(q, w);
    if (cmp (d, r1+r2) > 0 || cmp (d, fabs(r1-r2)) < 0 || cmp (d, 0) == 0) return res;
    cfloat a = (r1*r1 + d*d - r2*r2) / (2*d);
    cfloat c = Sqrt(r1*r1 - a*a);
    point b = (w-q) * (a/d);
    point n (w.y-q.y, q.x-w.x);
    n = n * (c / abs (n));
    res.pb (q + b + n);
    res.pb (q + b - n);
    return res;
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    double t1, t2;
    cin >> t1 >> t2;
    point C, H, S;
    cin >> C.x >> C.y;
    cin >> H.x >> H.y;
    cin >> S.x >> S.y;
    double max_t2 = dist (C, H) + t2;
    double max_t1 = dist (C, S) + dist (S, H) + t1;
    double b1 = 0;
    double b2 = min (max_t2, dist (C, S) + t1);
    REP (it, 100) {
        double rC = (b1 + b2) / 2;
        double rH = max_t2 - rC;
        double rS = dist (C, S) + t1 - rC;
        vector <point> a;
        a.pb (C);
        a.pb (H);
        a.pb (S);
        vector <point> b = intersect_circles (C, rC, H, rH);
        REP (i, SZ (b)) a.pb (b[i]);
        b = intersect_circles (C, rC, S, rS);       
        REP (i, SZ (b)) a.pb (b[i]);
        b = intersect_circles (S, rS, H, rH);       
        REP (i, SZ (b)) a.pb (b[i]);
        bool ok = false;
        REP (i, SZ (a))
            if (cmp (dist (a[i], C), rC) <= 0 && 
                cmp (dist (a[i], S), rS) <= 0 && 
                cmp (dist (a[i], H), rH) <= 0)
                    ok = true;
        if (ok) 
            b1 = rC;
        else
            b2 = rC;
    }
    double ans = (b1+b2)/2;
    if (cmp (dist (C, S) + dist (S, H), max_t2) <= 0)
        ans = min (max_t1, max_t2);
    printf ("%.10lf\n", ans);
	return 0;
}