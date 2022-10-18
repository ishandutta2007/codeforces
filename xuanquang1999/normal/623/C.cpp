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
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define maxN 100005
#define oo 1000000007

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

ll sqr(ll x) {return x*x;}

int n, minL[maxN], maxL[maxN], minR[maxN], maxR[maxN];
ii p[maxN];

bool Check(ll dis) {
//    debug(dis);
    fto(i, 1, n) {
        int minX, maxX;
        if (p[i].X > 0) {
            minX = max(-p[i].X, p[i].X-(int)sqrtl(dis));
            maxX = p[i].X;
        } else {
            minX = p[i].X;
            maxX = min(-p[i].X, p[i].X+(int)sqrtl(dis));
        }

        int l = lower_bound(p+1, p+n+1, mp(minX, -oo))-p;
        int r = upper_bound(p+1, p+n+1, mp(maxX, oo))-p-1;
//        printf("%d %d %d %d %d\n", i, minX, maxX, l, r);
        if (l == 1 && r == n) return true;

        int minY = min(minL[l-1], minR[r+1]);
        int maxY = max(maxL[l-1], maxR[r+1]);
        if (sqr(maxY-minY) <= dis && max(sqr(minX), sqr(maxX))+max(sqr(minY), sqr(maxY)) <= dis) return true;
    }

    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d", &p[i].X, &p[i].Y);

    int minX = oo, maxX = -oo, minY = oo, maxY = -oo;
    fto(i, 1, n) {
        minX = min(minX, p[i].X);
        maxX = max(maxX, p[i].X);
        minY = min(minY, p[i].Y);
        maxY = max(maxY, p[i].Y);
    }

    sort(p+1, p+n+1);

    minL[0] = oo; maxL[0] = -oo;
    fto(i, 1, n) {
        minL[i] = min(minL[i-1], p[i].Y);
        maxL[i] = max(maxL[i-1], p[i].Y);
    }
    minR[n+1] = oo; maxR[n+1] = -oo;
    fdto(i, n, 1) {
        minR[i] = min(minR[i+1], p[i].Y);
        maxR[i] = max(maxR[i+1], p[i].Y);
    }

    ll lo = 0, hi = (ll)oo*oo, res = min(sqr(maxX-minX), sqr(maxY-minY));
    while (lo <= hi) {
        ll mid = (lo+hi)/2;
        if (Check(mid)) {
            res = min(res, mid);
            hi = mid-1;
        } else lo = mid+1;
    }

    printf("%lld", res);

    return 0;
}