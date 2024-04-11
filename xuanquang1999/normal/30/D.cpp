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

const int MAXN = 1e5 + 5;
const double oo = 1e18;

int n, k, x[MAXN], y[MAXN];

double dist(int i, int j) {
    return hypot(x[i]-x[j], y[i]-y[j]);
}

double cover(int l, int r) {
    return min(dist(l, n), dist(r, n)) + dist(l, r);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k); --k;
    fto(i, 0, n) scanf("%d", &x[i]);
    scanf("%d", &y[n]);

    int xk = x[k];
    sort(x, x+n);

    double ans = oo;
    if (k == n)
        ans = cover(0, n-1);
    else {
        fto(i, 0, n-1)
            if (x[i] == xk) k = i;

        fto(i, 0, k) {
            double d = min(dist(k, i) + dist(n-1, n), dist(k, n-1) + dist(i, n)) + dist(i, n-1);
            if (i > 0)
                d += cover(0, i-1);
            ans = min(ans, d);
        }

        fto(i, k, n-1) {
            double d = min(dist(k, i) + dist(0, n), dist(k, 0) + dist(i, n)) + dist(0, i);
            if (i < n-1)
                d += cover(i+1, n-1);
            ans = min(ans, d);
        }
    }

    printf("%.15g", ans);

    return 0;
}