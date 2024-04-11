#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define temp template<typename num>
#define ptn point<num>
temp struct point {
    num x, y;
    ptn() {}
    ptn(num a, num b) : x(a), y(b) {}
    template<typename num2> ptn(point<num2> p2) : x(p2.x), y(p2.y) {}
    ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
    ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
    num operator * (ptn o) const { return x * o.x + y * o.y; }
    num operator ^ (ptn o) const { return x * o.y - y * o.x; }
    ptn operator * (num v) const { return ptn(x * v, y * v); }
    ptn operator / (num v) const { return ptn(x / v, y / v); }
    point<double> rotate(double deg) {
        double cs = cos(deg), sn = sin(deg);
        return point<double>(x*cs - y*sn, x*sn + y*cs);
    }
};
typedef point<int> pti;
typedef point<double> ptd;
int t, vm;
pti a, b, v1, v2;
double eps = 1e-10;
const double pi_ = 3.14159265358979323;

ptd get(ptd dir, ptd ve) {
    dir = dir / sqrt(dir * dir);
    double le = 0, ri = 2000;
    while(ri - le > eps) {
        double mi = (le + ri) / 2.;
        ptd x = dir * mi - ve;
        if(x * x <= vm * vm) le = mi;
        else ri = mi;
    }
    ptd x = dir * ((le + ri) / 2) - ve;
    return dir * ((le + ri) / 2.);
}

double solve(ptd x) {
    ptd z = ptd(b) - x;
    ptd q = get(z, v2);
    return sqrt((z * z) / (q * q)) + t;
}

double try_direct() {
    pti g = b - a;
    ptd p = get(g, v1);
    double vel = p * p;
    if(g * g <= vel * t * t)
        return sqrt((g * g) / vel);
    return solve(p * t + ptd(a));
}

int main() {
    scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
    scanf("%d %d", &vm, &t);
    scanf("%d %d %d %d", &v1.x, &v1.y, &v2.x, &v2.y);
    double st = try_direct();
    double le = -pi_/2, ri = pi_/2;
    
    if(a.x == b.x && a.y == b.y) { puts("0"); return 0; }
    ptd x = b - a;
    x = x / sqrt(x * x);
    x = x * vm;
    while(ri - le > 1e-8) {
        double ql = le + (ri - le) / 4.,
               qr = le + 3. * (ri - le) / 4.;
        ptd xl = x.rotate(ql); 
        ptd xr = x.rotate(qr);
        double sl = solve(ptd(a) + (xl + ptd(v1)) * t);
        double sr = solve(ptd(a) + (xr + ptd(v1)) * t);
        if(sl < sr) ri = qr;
        else le = ql;
    }
    x = x.rotate((le + ri) / 2.);
    printf("%.15f\n", min(solve(ptd(a) + (x + ptd(v1)) * t), st));
}