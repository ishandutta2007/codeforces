#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double T;
typedef complex<T> pt;
#define X real()
#define Y imag()

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
#define maxN 100005
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
#define EPS 1e-12

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

struct circle {
    pt o; double r;
    circle(): o({0, 0}), r(0) {}
    circle(pt o, double r): o(o), r(r) {}
};

int t1, t2;
double T1, T2;
pt house, shop, cinema;

void read(pt &p) {
    int x, y;
    scanf("%d%d", &x, &y);
    p = {x, y};
}

T sq(pt p) {return p.X*p.X + p.Y*p.Y;}

pt perp(pt p) {return {-p.Y, p.X};}

int sgn(double x) {return (x > 0) - (x < 0);}

vector<pt> circleCircle(pt o1, double r1, pt o2, double r2) {
    vector<pt> out;
    pt d = o2-o1; double d2 = sq(d);
    if (d2 == 0) return out;
    double pd = (d2 + r1*r1 - r2*r2)/2;
    double h2 = r1*r1 - pd*pd/d2;
//    debug(h2);
    if (h2 >= 0) {
        pt p = o1 + pd*d/d2, h = perp(d)*sqrt(h2/d2);
        out.pb(p-h);
        if (h2 > 0) out.pb(p+h);
    }
    return out;
}

void print(pt p) {
    printf("%.9g %.9g\n", p.X, p.Y);
}

void print(circle c) {
    printf("%.9g %.9g %.9g\n", c.o.X, c.o.Y, c.r);
}

bool Check(circle c1, circle c2, circle c3) {
//    print(c1);
//    print(c2);
//    print(c3);
    vector<pt> inter = circleCircle(c1.o, c1.r, c2.o, c2.r);
    if (abs(c1.o-c2.o) <= c2.r-c1.r) inter.pb(c1.o);
    for(pt p: inter) {
//        print(p);
        if (abs(p-c3.o) <= c3.r) return true;
    }
    return false;
}

bool Check(double x) {
    circle c[3];
    c[0] = {house, T2-x};
    c[1] = {shop, T1-abs(shop-house)-x};
    c[2] = {cinema, x};

//    debug(x);
    fto(i, 0, 2)
        fto(j, 0, 2)
            if (i != j) {
//                printf("%d %d %d\n", i, j, 3-i-j);
                if (Check(c[i], c[j], c[3-i-j])) return true;
            }
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &t1, &t2);
    read(cinema);
    read(house);
    read(shop);
    T1 = t1+abs(cinema-shop)+abs(shop-house)+EPS;
    T2 = t2+abs(cinema-house)+EPS;

    double res;
    if (T2+EPS >= T1-t1) {
        res = min(T1, T2);
    } else {
        double lo = 0, hi = min(T1-abs(shop-house), T2);
        fto(i, 1, 100) {
            double mid = (lo+hi)/2;
            if (Check(mid)) {
                res = mid;
                lo = mid;
            } else hi = mid;
        }
    }

    printf("%.9g", res);


    return 0;
}