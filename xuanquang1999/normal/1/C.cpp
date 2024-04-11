#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef complex<T> pt;
#define X real()
#define Y imag()

typedef long long ll;
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
#define EPS 1e-3

const T PI = acos(-1.0);

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

pt perp(pt p) {return {-p.Y, p.X};}

T cross(pt v, pt w) {return (conj(v)*w).Y;}

pt rot(pt piv, pt p, T theta) {return (p-piv)*polar(1.0L, theta) + piv;}

struct line {
    pt v; T c;
    line(pt p, pt q): v(q-p), c(cross(v, p)) {};

    line perpThrough(pt p) {return {p, p + perp(v)};}
};

bool inter(line l1, line l2, pt &out) {
    T d = cross(l1.v, l2.v);
    if (abs(d) < EPS) return false;
    out = (l1.c*l2.v - l2.c*l1.v)/d;
    return true;
}

void read(pt &p) {
    T x, y;
    cin >> x >> y;
    p = {x, y};
}

bool equiDist(pt a, pt b, pt c, pt &out) {
    line ab(a, b), ac(a, c);
    line perpBisectAb = ab.perpThrough((a+b)*0.5L);
    line perpBisectAc = ac.perpThrough((a+c)*0.5L);
    return (inter(perpBisectAb, perpBisectAc, out));
}

T area(vector<pt> po) {
    T area = 0.0;
    int n = sz(po);
    fto(i, 0, n-1)
        area += cross(po[i], po[(i+1)%n]);
    return fabs(area)/2.0;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    pt p[3];
    fto(i, 0, 2) read(p[i]);

    pt o;
    equiDist(p[0], p[1], p[2], o);

//    debug(o);

    fto(n, 3, 100) {
        T theta = 2*PI/n;
        bitset<3> ok;
        pt a = p[0];
//        debug(n);
        vector<pt> po;
        fto(i, 1, n) {
            a = rot(o, a, theta);
//            debug(a);
            fto(j, 0, 2) {
                T x = fabs(a-p[j]);
//                cout << setprecision(15) << x << endl;
                if (x < EPS) ok.set(j);
            }
            po.pb(a);
        }
//        cout << ok << endl;


        bool found = true;
        fto(j, 0, 2) {
            if (!ok[j]) {found = false; break;}
        }

        if (found) {
            cout << setprecision(15) << area(po);
            break;
        }
    }



    return 0;
}