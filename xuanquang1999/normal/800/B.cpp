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
#define maxN 1005
#define oo 1000000000000000007LL
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

int n;
point p[maxN];

double dot(const point &a, const point &b) {return (conj(a)*b).X;}

double dist(const point &a, const point &b, const point &p) {
    point h = a + (b - a) * dot(p - a, b - a) / norm(b - a);
    return abs(p-h);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }

    double ans = oo;
    fto(i, 0, n-1) {
        fto(j, i+2, i+n-1) {
            ans = min(ans, dist(p[i], p[j%n], p[(i+1)%n]));
            ans = min(ans, dist(p[i], p[j%n], p[(j-1)%n]));
        }
    }

    printf("%.9g", ans/2);

    return 0;
}