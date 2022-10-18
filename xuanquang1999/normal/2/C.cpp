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

void read(pt &p) {
    int x, y;
    scanf("%d%d", &x, &y);
    p = {x, y};
}

void print(pt p) {
    printf("%.5f %.5f\n", p.X, p.Y);
}

int sgn(double x) {return (x > 0) - (x < 0);}

T sq(pt p) {return p.X*p.X + p.Y*p.Y;}

T dot(pt v, pt w) {return (conj(v)*w).X;}

T cross(pt v, pt w) {return (conj(v)*w).Y;}

pt perp(pt p) {return {-p.Y, p.X};}

double angle(pt v, pt w) {
    double cosTheta = dot(v, w)/abs(v)/abs(w);
    return acos(min(1.0, max(-1.0, cosTheta)));
}

struct circle {
    pt o; T r;
    circle(pt o, T r): o(o), r(r) {}
};

struct line {
    pt v; T c;
    line(pt a, pt b): v(b-a), c(cross(v, a)) {}
};

pt inter(line l1, line l2) {
    T d = cross(l1.v, l2.v);
    return (l1.c*l2.v - l2.c*l1.v)/d;
}

pt circumCenter(pt a, pt b, pt c) {
    b = b-a; c = c-a;
    return perp(b*sq(c) - c*sq(b))/cross(b, c)/2.0;
}

vector<line> tangents(pt o1, T r1, pt o2, T r2, bool inner) {
    if (inner) r2 = -r2;
    pt d = o2-o1;
    double dr = r2-r1, d2 = sq(d), h2 = d2 - dr*dr;
    vector<line> res;
    for (double sign: {-1.0, 1.0}) {
        pt v = (d*dr + perp(d)*sqrt(h2)*sign)/d2;
        res.pb(line(o1+r1*v, o2+r2*v));
    }
    return res;
}

pt tangentInter(pt o1, T r1, pt o2, T r2, bool inner) {
    vector<line> tg = tangents(o1, r1, o2, r2, inner);
    return inter(tg[0], tg[1]);
}

int circleCircle(pt o1, T r1, pt o2, T r2, pair<pt, pt> &res) {
    pt d = o2-o1; double d2 = sq(d);
    if (d2 == 0) {assert(r1 != r2); return 0;}
    double pd = (d2 + r1*r1 - r2*r2)/2.0;
    double h2 = r1*r1 - pd*pd/d2;
    if (h2 >= 0) {
        pt p = o1 + d*pd/d2, h = perp(d)*sqrt(h2/d2);
        res = {p-h, p+h};
    }
    return 1 + sgn(h2);
}

double getAngle(pt p, pt o, T r) {
    vector<line> tg = tangents(o, r, p, 0, false);
    return angle(tg[0].v, tg[1].v);
}

pt p[3];
int r[3];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 0, 2) {
        read(p[i]);
        scanf("%d", &r[i]);
    }

    if (r[0] == r[1] && r[1] == r[2]) {
        print(circumCenter(p[0], p[1], p[2]));
    } else {
        vector<circle> cir;
        fto(i, 0, 1) {
            fto(j, i+1, 2) {
                if (r[i] != r[j]) {
                    pt pInner = tangentInter(p[i], r[i], p[j], r[j], true);
                    pt pOuter = tangentInter(p[i], r[i], p[j], r[j], false);
                    pt o = (pInner+pOuter)/2.0;
                    cir.pb({o, abs(o-pInner)});
                }
            }
        }
//        for(circle c: cir) {
//            printf("%.9g %.9g %.9g\n", c.o.X, c.o.Y, c.r);
//        }

        pair<pt, pt> cand;
        if (circleCircle(cir[0].o, cir[0].r, cir[1].o, cir[1].r, cand) == 0) return 0;

        pt ans = cand.ff;
        if (getAngle(cand.ss, p[0], r[0]) > getAngle(cand.ff, p[0], r[0]))
            ans = cand.ss;
        print(ans);
    }

    return 0;
}