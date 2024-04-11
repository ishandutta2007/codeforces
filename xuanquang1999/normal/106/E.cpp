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

const double EPS = 1e-9;

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
        os << p.x << " " << p.y << " " << p.z;
        return os;
    }
};

double sq(p3 v) {return v|v;}

double mag(p3 v) {return sqrt(sq(v));}

struct plane {
    p3 n; double d;
    plane(p3 n, p3 p): n(n), d(n|p) {}
    plane(p3 p, p3 q, p3 r): plane((q-p)*(r-p), p) {}
    double side(p3 p) {return (p|n) - d;}
};

struct line {
    p3 o, d;
    line(plane p1, plane p2) {
        d = p1.n*p2.n;
        o = (p2.n*p1.d - p1.n*p2.d)*d/sq(d);
    }
    p3 inter(plane p) {return o - d*p.side(o)/(p.n|d);}
};

struct sphere {
    p3 o; double r;
    sphere(p3 o, double r): o(o), r(r) {}
    bool contain(p3 p) {return mag(p-o) <= r + EPS;}
    friend ostream& operator << (ostream& os, sphere &s) {
        os << "(" << s.o << ") " << s.r;
        return os;
    }
};

plane perpThrough(line l, p3 p) {return plane(l.d, p);}

plane midPerp(p3 a, p3 b) {return plane(b-a, (a+b)/2);}

p3 inter(plane p1, plane p2, plane p3) {
    return line(p1, p2).inter(p3);
}

sphere circumSphere(p3 a, p3 b, p3 c) {
    p3 o = inter(midPerp(a, b), midPerp(a, c), plane(a, b, c));
    return sphere(o, mag(o - a));
}

sphere circumSphere(p3 a, p3 b, p3 c, p3 d) {
    p3 o = inter(midPerp(a, b), midPerp(a, c), midPerp(a, d));
    return sphere(o, mag(o - a));
}

const int MAXN = 105;

int n;
p3 p[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    fto(i, 0, n-1) cin >> p[i];

//    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//    shuffle(p, p+n, rng);

    sphere ans(p[0], 0);
    fto(i, 1, n-1) {
        if (ans.contain(p[i])) continue;
        ans = sphere(p[i], 0);
        fto(j, 0, i-1) {
            if (ans.contain(p[j])) continue;
            ans = sphere((p[i] + p[j])/2, mag(p[i] - p[j])/2);
            fto(k, 0, j-1) {
                if (ans.contain(p[k])) continue;
                ans = circumSphere(p[i], p[j], p[k]);
                fto(l, 0, k-1) {
                    if (ans.contain(p[l])) continue;
                    ans = circumSphere(p[i], p[j], p[k], p[l]);
                }
            }
        }
    }

    cout << setprecision(50) << ans.o;

    return 0;
}