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

const int MAXN = 100005;
const double oo = 1e18;

int n, x[MAXN], y[MAXN];

bool Check(double r) {
    double minClose = oo, maxOpen = -oo;
//    debug(r);
    fto(i, 1, n) {
        double dy = y[i] - r;
        double dx = r*r - dy*dy;
        if (dx < 0) return false;
        dx = sqrt(dx);

        double lo = x[i] - dx, hi = x[i] + dx;
        minClose = min(minClose, hi);
        maxOpen = max(maxOpen, lo);
    }

    return (minClose >= maxOpen);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d", &x[i], &y[i]);

    if (y[1] < 0) {
        fto(i, 1, n)
            y[i] = -y[i];
    }

    fto(i, 1, n) {
        if (y[i] < 0) {
            puts("-1");
            return 0;
        }
    }


    double lo = 0, hi = 1e15, res = -1;
    fto(i, 1, 200) {
        double mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            hi = mid;
        } else lo = mid;
    }

    printf("%.15g", res);

    return 0;
}