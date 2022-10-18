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
#define double long double

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

const double EPS = 1e-6;

struct pt {
    double x, y;
    bool operator == (pt p) {
        return abs(x-p.x) < EPS && abs(y-p.y) < EPS;
    }
    bool operator < (pt p) {
        if (*this == p) return false;
        return (abs(x-p.x) < EPS) ? (y < p.y) : (x < p.x);
    }
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream &is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

double mag(pt v) {return hypot(v.x, v.y);}

double orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
    double oa = orient(c, d, a), ob = orient(c, d, b);
    double oc = orient(a, b, c), od = orient(a, b, d);
    if (oa*ob < -EPS && oc*od < -EPS) {
        out = (a*ob - b*oa)/(ob - oa);
        return true;
    }
    return false;
}

bool onSegment(pt a, pt b, pt p) {
    return (abs(orient(a, b, p)) < EPS && (a-p)%(b-p) < EPS);
}

vector<pt> inter(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out)) return {out};
    vector<pt> ans;
    if (onSegment(c, d, a)) ans.pb(a);
    if (onSegment(c, d, b)) ans.pb(b);
    if (onSegment(a, b, c)) ans.pb(c);
    if (onSegment(a, b, d)) ans.pb(d);
    return ans;
}

double area(pt a, pt b, pt c) {
    return abs(orient(a, b, c));
}

//Check if a point is in a triangle
bool in(pt po[], pt p) {
    int n = 3;
    double sum = area(po[0], po[1], po[2]);
    fto(i, 0, n-1) {
        if (onSegment(po[i], po[(i+1)%n], p))
            return false;
        sum -= area(p, po[i], po[(i+1)%n]);
    }
//    puts("in:");
//    cout << po[0] << " " << po[1] << " " << po[2] << " " << p << endl;
//    debug(sum);
    return abs(sum) < EPS;
}

const int MAXN = 105;
int n;
pt p[MAXN][3];

double getVisibleLength(pt a, pt b) {
    vector<pt> P = {a, b};
    fto(i, 0, n-1) {
        fto(j, 0, 2) {
            vector<pt> out = inter(a, b, p[i][j], p[i][(j+1)%3]);
            P.insert(end(P), begin(out), end(out));
        }
    }

    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());

//    cout << a << " " << b << endl;
//    for(pt p: P) cout << p << " ";
//    cout << endl;

    int k = sz(P);
    double ans = 0;
    fto(i, 0, k-2) {
        pt c = P[i], d = P[i+1];
        pt m = (c+d)/2;

        bool visible = true;
        fto(j, 0, n-1) {
            if (in(p[j], m)) {
                visible = false;
                break;
            }
        }

        if (visible)
            ans += mag(d-c);
    }

//    debug(ans);

    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    fto(i, 0, n-1)
        fto(j, 0, 2) cin >> p[i][j];

    double ans = 0;
    fto(i, 0, n-1)
        fto(j, 0, 2)
            ans += getVisibleLength(p[i][j], p[i][(j+1)%3]);

    cout << setprecision(69) << ans;

    return 0;
}