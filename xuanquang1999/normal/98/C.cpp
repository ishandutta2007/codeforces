#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct pt {
    double x, y;
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

double mag(pt v) {return hypot(v.x, v.y);}

struct line {
    pt v; double c;
    line(pt p, pt q): v(q-p), c(v*p) {}
    double side(pt p) {return v*p - c;}
    double signedDist(pt p) {return side(p)/mag(v);}
};

const double EPS = 1e-9;
const double oo = 1e9;

double dist(double l, double alpha, pt corner) {
    pt a = {0, l*sin(alpha)}, b = {l*cos(alpha), 0};
    line ab(a, b);
    return ab.signedDist(corner);
}

double solve(double a, double b, double l) {
    double lo = 0, hi = PI/2, res = oo;
    pt corner = {a, b};
    fto(i, 1, 100) {
        double m1 = (2*lo + hi)/3, m2 = (lo + 2*hi)/3;
        double f1 = dist(l, m1, corner), f2 = dist(l, m2, corner);
        res = min(res, min(f1, f2));
        if (f1 >= f2)
            lo = m1;
        if (f1 <= f2)
            hi = m2;
    }

    if (a >= l)
        res = max(res, b);

    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    double a, b, l;
    cin >> a >> b >> l;

    double ans = max(solve(a, b, l), solve(b, a, l));
    ans = min(ans, l);

    if (ans < EPS)
        puts("My poor head =(");
    else
        cout << setprecision(50) << ans;

    return 0;
}