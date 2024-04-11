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
#define maxN 105
#define oo 1000000007
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

int n, m, a[maxN][maxN], r[maxN], c[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) fto(j, 0, m-1) scanf("%d", &a[i][j]);

    int x = oo;
    fto(i, 0, n-1) fto(j, 0, m-1) x = min(x, a[i][j]);
    fto(i, 0, n-1) fto(j, 0, m-1) a[i][j] -= x;

    fto(p, 0, a[0][0]) {
        r[0] = p;
        fto(j, 0, m-1) c[j] = a[0][j]-r[0];
        fto(i, 1, n-1) r[i] = a[i][0]-c[0];
        bool ok = true;
        fto(i, 0, n-1) {
            fto(j, 0, m-1) {
                if (r[i] < 0 || c[j] < 0 || a[i][j] != r[i]+c[j]) ok = false;
            }
        }
        if (ok) {
            if (n < m) fto(i, 0, n-1) r[i] += x;
            else fto(j, 0, m-1) c[j] += x;
//            debug(p);
//            fto(i, 0, n-1) printf("%d ", r[i]);
//            puts("");
//            fto(j, 0, m-1) printf("%d ", c[j]);
//            puts("");
            int cnt = accumulate(c, c+m, 0)+accumulate(r, r+n, 0);
            printf("%d\n", cnt);
            fto(i, 0, n-1) fto(j, 1, r[i]) printf("row %d\n", i+1);
            fto(j, 0, m-1) fto(i, 1, c[j]) printf("col %d\n", j+1);
            return 0;
        }
    }

    puts("-1");

    return 0;
}