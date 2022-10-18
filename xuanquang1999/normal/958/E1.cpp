//84104971101048411497 - Can you guess what does this mean?
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
#define X real()
#define Y imag()
#define maxN 15
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
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

double cross(point a, point b) {
    return (conj(a) * b).Y;
}

bool intersection(point a, point b, point p, point q, point &i) {
    double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
    if (abs(c1-c2) < EPS) return false;
    i = (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
    return true;
}

bool isIn(double l, double x, double r) {
    if (l > r) swap(l, r);
    return (l <= x && x <= r);
}

bool isIn(point l, point o, point r) {
    return (isIn(l.X, o.X, r.X) && isIn(l.Y, o.Y, r.Y));
}

int R, B, p[maxN];
point r[maxN], b[maxN];
bool can[maxN][maxN][maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &R, &B);
    if (R != B) {
        puts("No");
        return 0;
    }
    fto(i, 1, R) {
        int x, y; scanf("%d%d", &x, &y);
        r[i] = {x, y};
    }
    fto(i, 1, B) {
        int x, y; scanf("%d%d", &x, &y);
        b[i] = {x, y};
    }

    fto(r1, 1, R) fto(r2, 1, R) if (r1 != r2) {
        fto(b1, 1, B) fto(b2, 1, B) if (b1 != b2) {
            point o;
            if (!intersection(r[r1], b[b1], r[r2], b[b2], o)) can[r1][r2][b1][b2] = true;
            else can[r1][r2][b1][b2] = (!isIn(r[r1], o, b[b1]) || !isIn(r[r2], o, b[b2]));
        }
    }

    fto(i, 1, R) p[i] = i;
    do {
        bool ok = true;
        fto(i, 1, R) {
            if (!ok) break;
            fto(j, i+1, R) {
                if (!can[i][j][p[i]][p[j]]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            puts("Yes");
            return 0;
        }
    } while (next_permutation(p+1, p+R+1));

    puts("No");

    return 0;
}