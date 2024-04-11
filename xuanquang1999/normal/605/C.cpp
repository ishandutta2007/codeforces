//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 100005
#define oo 1000000007
#define EPS 1e-9
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

bool compX(const point &a, const point &b) {
    return a.X < b.X;
}

point readPoint() {
    int x, y; scanf("%d%d", &x, &y);
    return {x, y};
}

double cross(const point &a, const point &b) {return (conj(a)*b).Y;}

point intersect(const point &a, const point &b, const point &p, const point &q) {
    double c1 = cross(p-a, b-a), c2 = cross(q-a, b-a);
    return (c1*q-c2*p)/(c1-c2);
}

int CCW(const point &a, const point &b, const point &c) {
    double x = cross(b-a, c-b);
    if (x > EPS) return 1;
    if (x < -EPS) return -1;
    return 0;
}

bool isIn(const point &a, const point &b, const point &c) {
    return (abs(b-a)+abs(b-c)-abs(a-c) < EPS);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n; scanf("%d", &n);
    point F = readPoint();
    point O; O = {0, 0};

    vector<point> p(n+2);
    int maxY = -1, maxX = -1;
    fto(i, 1, n) {
        p[i] = readPoint();
        if (maxY == -1 || p[i].Y > p[maxY].Y) maxY = i;
        if (maxX == -1 || p[i].X > p[maxX].X) maxX = i;
    }
    p[0] = {0, p[maxY].Y}; p[n+1] = {p[maxX].X, 0};
    sort(p.begin()+1, p.begin()+n+1, compX);


    vector<point> H;
    fto(i, 0, n+1) {
        while (sz(H) > 1 && CCW(H[sz(H)-2], H[sz(H)-1], p[i]) != -1) H.pop_back();
        H.pb(p[i]);
    }

    //forit(it, H) cout << *it << endl;
    double ans = oo;
    fto(i, 0, sz(H)-2) {
        point M = intersect(O, F, H[i], H[i+1]);
        //debug(M);
        if (isIn(H[i], M, H[i+1])) ans = min(ans, abs(F)/abs(M));
    }

    printf("%.9g", ans);

    return 0;
}