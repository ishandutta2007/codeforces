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

const double PI = acos(-1.0);
const double EPS = 1e-9;

struct p2 {
    double x, y;
    p2 operator + (p2 p) {return {x + p.x, y + p.y};}
    p2 operator - (p2 p) {return {x - p.x, y - p.y};}
    p2 operator * (double k) {return {x * k, y * k};}
    p2 operator / (double k) {return {x / k, y / k};}
    double operator * (p2 p) {return x*p.y - y*p.x;}
    double operator | (p2 p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, p2 &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, p2 &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

p2 perp(p2 v) {return {-v.y, v.x};}

struct p3 {
    double x, y, z;
    p3 operator + (p3 p) {return {x + p.x, y + p.y, z + p.z};}
    p3 operator - (p3 p) {return {x - p.x, y - p.y, z - p.z};}
    p3 operator * (double k) {return {x * k, y * k, z * k};}
    p3 operator / (double k) {return {x / k, y / k, z / k};}
    p3 operator * (p3 p) {return {y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x};}
    double operator | (p3 p) {return x*p.x + y*p.y + z*p.z;}
    friend istream& operator >> (istream& is, p3 &p) {
        is >> p.x >> p.y >> p.z;
        return is;
    }
    friend ostream& operator << (ostream& os, p3 &p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }
};

template<class T>
double sq(T p) {return p|p;}

template<class T>
double mag(T p) {return sqrt(sq(p));}

template<class T>
T unit(T v) {return v/mag(v);}

struct coords {
    p3 o, dx, dy, dz;
    coords(p3 p, p3 q, p3 r): o(p) {
        dx = unit(q-p);
        dz = unit(dx*(r-p));
        dy = dz*dx;
    }
    p2 pos2d(p3 p) {return {(p-o)|dx, (p-o)|dy};}
};

struct circle {
    p2 o; double r;
    circle(p2 o, double r): o(o), r(r) {}
    bool contain(p2 p) {return mag(o-p) <= r + EPS;}
};

//Assumed that a, b, c is not collinear
circle circumCircle(p2 a, p2 b, p2 c) {
    b = b-a; c = c-a;
    p2 o = a + perp(b*sq(c) - c*sq(b))/(b*c)/2;
    return circle(o, mag(a-o));
}

const int MAXN = 905;

int n, m;
p3 cen[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m;
    fto(i, 0, n-1)
        cin >> cen[i];

    fto(j, 0, m-1) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<p3> inPlane;
        inPlane.pb({0, 0, 0});
        if (a != 0) {
            inPlane.pb({-1.0*b/a, 1, 0});
            inPlane.pb({-1.0*c/a, 0, 1});
        } else if (b != 0) {
            inPlane.pb({1, -1.0*a/b, 0});
            inPlane.pb({0, -1.0*c/b, 1});
        } else if (c != 0) {
            inPlane.pb({1, 0, -1.0*a/c});
            inPlane.pb({0, 1, -1.0*b/c});
        }

        coords C(inPlane[0], inPlane[1], inPlane[2]);
        vector<p2> p(n);
        fto(i, 0, n-1)
            p[i] = C.pos2d(cen[i]);

        random_shuffle(p.begin(), p.end());

        circle ans(p[0], 0);
        fto(i, 1, n-1) {
            if (ans.contain(p[i])) continue;
            ans = circle(p[i], 0);
            fto(j, 0, i-1) {
                if (ans.contain(p[j])) continue;
                ans = circle((p[i]+p[j])/2, mag(p[i]-p[j])/2);
                fto(k, 0, j-1) {
                    if (ans.contain(p[k])) continue;
                    ans = circumCircle(p[i], p[j], p[k]);
                }
            }
        }

        cout << setprecision(50) << ans.r << endl;
    }

    return 0;
}