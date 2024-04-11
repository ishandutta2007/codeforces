#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
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

const double EPS = 1e-10;

struct pt {
    double x, y;
    void read() {cin >> x >> y;}
    pt operator + (pt p) {return {x+p.x, y+p.y};}
    pt operator - (pt p) {return {x-p.x, y-p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator % (pt p) {return x*p.x + y*p.y;}
    friend ostream& operator << (ostream& os, const pt& p) {
        os << "(" << p.x << ", " << p.y << ")";
    }
};

double mag(pt v) {return hypot(v.x, v.y);}

double sq(pt v) {return v.x*v.x + v.y*v.y;}

pt perp(pt v) {return {-v.y, v.x};}

struct line {
    pt v; double c;
    line(pt p, pt q): v(q-p), c(v*p) {}
    double side(pt p) {return v*p - c;}
    pt reflect(pt p) {return p - perp(v)*2*side(p)/sq(v);}
};

double orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

pt reflect(pt a, pt b, pt p) {
    line l(a, b);
    return l.reflect(p);
}

bool onSegment(pt a, pt b, pt p) {
    return (abs(orient(a, b, p)) < EPS && (a-p)%(b-p) < EPS);
}

bool properInter(pt a, pt b, pt c, pt d, pt &i) {
    double oa = orient(c, d, a), ob = orient(c, d, b);
    double oc = orient(a, b, c), od = orient(a, b, d);
    if (oa*ob < -EPS && oc*od < -EPS) {
        i = (a*ob - b*oa)/(ob-oa);
        return true;
    }
    return false;
}

vector<pt> inter(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out)) return {out};
    vector<pt> res;
    if (onSegment(c, d, a)) res.pb(a);
    if (onSegment(c, d, b)) res.pb(b);
    if (onSegment(a, b, c)) res.pb(c);
    if (onSegment(a, b, d)) res.pb(d);
    return res;
}

pt w[2], m[2];

bool blockByMirror(pt a, pt b) {
    return (inter(a, b, m[0], m[1]).size() == 1);
}

bool blockByWall(pt a, pt b) {
    return (!inter(a, b, w[0], w[1]).empty());
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    pt A; A.read();
    pt B; B.read();
    fto(i, 0, 1) w[i].read();
    fto(i, 0, 1) m[i].read();

//    vector<pt> tmp = inter(A, B, w[0], w[1]);
//    puts("wall:");
//    for(pt p: tmp) cout << p << endl;
//    tmp = inter(A, B, m[0], m[1]);
//    puts("mirror:");
//    for(pt p: tmp) cout << p << endl;

    if (!blockByMirror(A, B) && !blockByWall(A, B)) {
        puts("YES");
        return 0;
    }

    pt C = reflect(m[0], m[1], A);
//    debug(C);
    vector<pt> M = inter(C, B, m[0], m[1]);
    if (M.size() == 0) {
        puts("NO");
        return 0;
    }
//    debug(M[0]);

//    vector<pt> tmp = inter(A, M[0], w[0], w[1]);
//    puts("A, M[0]:");
//    for(pt p: tmp) cout << p << endl;
//    tmp = inter(M[0], B, w[0], w[1]);
//    puts("B, M[0]:");
//    for(pt p: tmp) cout << p << endl;

    if (!blockByWall(A, M[0]) && !blockByWall(M[0], B)) {
        puts("YES");
        return 0;
    }

    puts("NO");

    return 0;
}