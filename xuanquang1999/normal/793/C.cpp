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
#define sz(a) (int)a.size()
#define y1 PleaseLetMeUseThisName
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

int n, x1, y1, x2, y2, rx[maxN], ry[maxN], vx[maxN], vy[maxN];

void no() {
    puts("-1");
    exit(0);
}

pair<double, double> Solve(int x1, int x2, int p[], int v[]) {
    double minT = -oo, maxT = oo;
    fto(i, 1, n) {
        double t1, t2;
        if (p[i] <= x1) {
            if (v[i] <= 0) no();
            t1 = 1.0*(x1-p[i])/abs(v[i]);
            t2 = 1.0*(x2-p[i])/abs(v[i]);
        } else if (p[i] >= x2) {
            if (v[i] >= 0) no();
            t1 = 1.0*(p[i]-x2)/abs(v[i]);
            t2 = 1.0*(p[i]-x1)/abs(v[i]);
        } else {
            t1 = 0;
            if (v[i] == 0) t2 = oo;
            if (v[i] < 0) t2 = 1.0*(p[i]-x1)/abs(v[i]);
            if (v[i] > 0) t2 = 1.0*(x2-p[i])/abs(v[i]);
        }
        minT = max(minT, t1);
        maxT = min(maxT, t2);
//        printf("%d %.9g %.9g\n", i, t1, t2);
    }
    return mp(minT, maxT);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    fto(i, 1, n) scanf("%d%d%d%d", &rx[i], &ry[i], &vx[i], &vy[i]);

    pair<double, double> pX = Solve(x1, x2, rx, vx), pY = Solve(y1, y2, ry, vy);
    double minT = max(pX.ff, pY.ff), maxT = min(pX.ss, pY.ss);

    if (minT+EPS < maxT) printf("%.9g", minT);
    else puts("-1");

    return 0;
}