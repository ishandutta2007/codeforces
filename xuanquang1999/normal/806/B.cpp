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
#define oo 1000000009
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

int n, a[5], b[5], cnt[5];

bool isIn(int a, int b, int c) {
    return (a < b && b <= c);
}

int CalcScore(int a[], int i1, int i2, int i3, int i4, int i5) {
    int p[5] = {i1, i2, i3, i4, i5}, res = 0;
    fto(i, 0, 4) {
        if (a[i] >= 0) res += 2*p[i]*(250-a[i]);
    }
    return res;
}

int problemScore(int x, int n) {
    if (isIn(n, 2*x, 2*n)) return 1;
    if (isIn(n, 4*x, 2*n)) return 2;
    if (isIn(n, 8*x, 2*n)) return 3;
    if (isIn(n, 16*x, 2*n)) return 4;
    if (isIn(n, 32*x, 2*n)) return 5;
    if (isIn(-1, 64*x, 2*n)) return 6;
}

int Check(int x) {
    int maxPoint[5], minPoint[5];
    fto(i, 0, 4) {
        maxPoint[i] = problemScore(cnt[i], n+x);
        minPoint[i] = problemScore(cnt[i] + ((a[i] >= 0) ? x : 0), n+x);
    }
//    debug(x);
//    fto(i, 0, 4) printf("%d %d\n", minPoint[i], maxPoint[i]);

    fto(i0, minPoint[0], maxPoint[0]) {
        fto(i1, minPoint[1], maxPoint[1]) {
            fto(i2, minPoint[2], maxPoint[2]) {
                fto(i3, minPoint[3], maxPoint[3]) {
                    fto(i4, minPoint[4], maxPoint[4]) {
                        if (CalcScore(a, i0, i1, i2, i3, i4) > CalcScore(b, i0, i1, i2, i3, i4)) return true;
                    }
                }
            }
        }
    }

    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(j, 0, 4) scanf("%d", &a[j]);
    fto(j, 0, 4) scanf("%d", &b[j]);
    fto(j, 0, 4) {
        if (a[j] >= 0) ++cnt[j];
        if (b[j] >= 0) ++cnt[j];
    }
    fto(i, 1, n-2) {
        fto(j, 0, 4) {
            int x; scanf("%d", &x);
            if (x >= 0) ++cnt[j];
        }
    }

//    fto(j, 0, 4) printf("%d ", cnt[j]);
//    puts("");

    fto(i, 0, 5000) {
        if (Check(i)) {
            printf("%d", i);
            return 0;
        }
    }

    puts("-1");

    return 0;
}