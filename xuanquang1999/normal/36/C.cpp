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
const int MAXN = 3e3 + 5;

int n, h[MAXN], r[MAXN], R[MAXN];
double y[MAXN];

double getHeight(const int &h, const int &r, const int &R, const int &w) {
    return 1.0*h*(R-w)/(R-r);
}

double inter(const int &h1, const int &r1, const int &R1, const int &h2, const int &r2, const int &R2) {
    if (r2 >= R1) return 0;
    int x1 = h1*(R2-r2), x2 = h2*(R1-r1);
    double t;
    if (x1 <= x2) {
        t = getHeight(h1, r1, R1, r2);
    } else if (R2 <= R1) {
        t = h2 + getHeight(h1, r1, R1, R2);
    } else {
        t = h2 - getHeight(h2, r2, R2, R1);
    }
//    printf("%d %d %d %d %d %d %d %d\n", h1, r1, R1, h2, r2, R2, x1, x2);
//    debug(t);
    return min((double)h1, max(t, 0.0));
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    double ans = 0;
    fto(i, 1, n) {
        scanf("%d%d%d", &h[i], &r[i], &R[i]);
        y[i] = 0;
        fto(j, 1, i-1) {
            double newY = y[j] + h[j] - inter(h[j], r[j], R[j], h[i], r[i], R[i]);
            y[i] = max(y[i], newY);
        }
        ans = max(ans, y[i] + h[i]);
    }

    printf("%.15g", ans);

    return 0;
}