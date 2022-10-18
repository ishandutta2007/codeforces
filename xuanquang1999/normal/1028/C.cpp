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
#define y1 jksdhgsjrgbiwrbgij

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

const int MAXN = 2e5 + 5;
const int oo = 1e9 + 7;

int n, x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
int lx1[MAXN], rx1[MAXN], ly1[MAXN], ry1[MAXN], lx2[MAXN], rx2[MAXN], ly2[MAXN], ry2[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n)
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);

    lx1[0] = ly1[0] = rx1[n+1] = ry1[n+1] = -oo;
    lx2[0] = ly2[0] = rx2[n+1] = ry2[n+1] = oo;
    fto(i, 1, n) {
        lx1[i] = max(lx1[i-1], x1[i]);
        ly1[i] = max(ly1[i-1], y1[i]);
        lx2[i] = min(lx2[i-1], x2[i]);
        ly2[i] = min(ly2[i-1], y2[i]);
    }

    fdto(i, n, 1) {
        rx1[i] = max(rx1[i+1], x1[i]);
        ry1[i] = max(ry1[i+1], y1[i]);
        rx2[i] = min(rx2[i+1], x2[i]);
        ry2[i] = min(ry2[i+1], y2[i]);
    }

    fto(i, 1, n) {
        int x1 = max(lx1[i-1], rx1[i+1]);
        int y1 = max(ly1[i-1], ry1[i+1]);
        int x2 = min(lx2[i-1], rx2[i+1]);
        int y2 = min(ly2[i-1], ry2[i+1]);
        if (x1 <= x2 && y1 <= y2) {
            printf("%d %d\n", x1, y1);
            break;
        }
    }


    return 0;
}