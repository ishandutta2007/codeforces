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

struct p3 {
    double x, y, z;
    p3 operator + (p3 p) {return {x + p.x, y + p.y, z + p.z};}
    p3 operator - (p3 p) {return {x - p.x, y - p.y, z - p.z};}
    p3 operator * (double k) {return {x*k, y*k, z*k};}
    p3 operator / (double k) {return {x/k, y/k, z/k};}
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

double sq(p3 v) {return v|v;}
double mag(p3 v) {return sqrt(sq(v));}

struct line {
    p3 o, d;
    line(p3 o, p3 d): o(o), d(d) {}
    double sqDist(p3 p) {return sq(d*(p-o))/sq(d);}
    p3 proj(p3 p) {return o + d*(d|(p-o))/sq(d);}
};

bool circleInter(p3 o, double r, line l, pair<p3, p3> &out) {
    if (sq(l.d*(o-l.o)) > r*r*sq(l.d))
        return false;

    double h2 = r*r - l.sqDist(o);
    p3 p = l.proj(o), h = l.d*sqrt(h2)/mag(l.d);
    out = {p + h, p - h};
    return true;
}

const double INF = 1e9;

double ans = INF;

void update(p3 a, p3 v, p3 p) {
    if ((v|p) >= (v|a))
        ans = min(ans, mag(a-p)/mag(v));
}

void Solve(p3 o, double r, p3 a, p3 v) {
    line l(a, v);
    pair<p3, p3> out;
//    cout << o << " " << r << " " << a << " " << v << endl;
    if (!circleInter(o, r, l, out))
        return;
//    cout << out.ff << " " << out.ss << endl;

    update(a, v, out.ff);
    update(a, v, out.ss);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    p3 a, v;
    int n, R;
    cin >> a >> v >> R >> n;

    fto(i, 0, n-1) {
        p3 o;
        int r, k;
        cin >> o >> r >> k;

        Solve(o, r+R, a, v);

        fto(j, 0, k-1) {
            p3 p;
            cin >> p;
            p = o + p;

            Solve(p, R, a, v);
        }
    }

    if (ans == INF)
        ans = -1;

    cout << setprecision(50) << ans;

    return 0;
}