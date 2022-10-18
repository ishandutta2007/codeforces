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
#define oo 2000000007
#define EPS 1e-9

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

int n, p, a[maxN], b[maxN];

bool Check(double t) {
    double sumE = 0;
    fto(i, 1, n) sumE += max(0.0, a[i]*t-b[i]);
//    debug(t);
//    debug(sumE);
    return (sumE <= p*t);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &p);
    fto(i, 1, n) scanf("%d%d", &a[i], &b[i]);

    ll sumA = 0;
    fto(i, 1, n) sumA += a[i];
    if (p >= sumA) {
        puts("-1");
        return 0;
    }

    double lo = 0, hi = 1e12, res = 0;
    fto(i, 1, 100) {
        double mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            lo = mid+EPS;
        } else hi = mid-EPS;
    }

    printf("%.9g", res);

    return 0;
}