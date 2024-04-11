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

const double EPS = 1e-7;

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
    friend ostream& operator << (ostream& os, const pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

struct line {
    pt v; double c;
    line(pt p, pt q): v(q-p), c(v*p) {}
};

bool orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

const int MAXN = 1e3 + 5;
int n;
pt po[MAXN];

pt inter(line l1, line l2) {
    return (l2.v*l1.c - l1.v*l2.c)/(l1.v*l2.v);
}

int Solve() {
    line AB(po[0], po[1]);

    double maxL = po[0].x, minR = po[1].x;

    fto(i, 2, n-1) {
        line l(po[i], po[(i+1)%n]);
        double d = AB.v % l.v;
        double c = AB.v * l.v;
//        printf("%d %.9g %.9g\n", i, d, c);
        if (abs(c) < EPS) {
            if (d > 0) return 0;
        } else {
            double x = orient(po[i], po[0], po[i+1]);
//            debug(x);
            pt p = inter(AB, l);
            if (c > 0) {
                if (x < -EPS) return 0;
                maxL = max(maxL, p.x);
            } else {
                minR = min(minR, p.x);
            }
        }

    }

//    debug(maxL);
//    debug(minR);

    int lo = ceil(maxL-EPS), hi = floor(minR+EPS);
//    printf("%d %d\n", lo, hi);
    return max(0, hi - lo + 1);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    fto(i, 0, n-1) cin >> po[i];

    if (po[2].y > po[1].y-EPS) {
        fto(i, 2, n-1)
            po[i].y = 2*po[1].y - po[i].y;
        reverse(po+2, po+n);
        swap(po[0], po[1]);
    }

//    fto(i, 0, n-1) cout << po[i] << endl;

    cout << Solve();

    return 0;
}