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
#define sz(a) (int)a.size()
#define maxN 5005
#define oo 1000000000000000007LL
#define MOD 1000000007
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

int n, a, b, k, f[maxN][maxN], d[maxN][maxN];

int Calc(int i, int l, int r) {
    return (d[i][r]-d[i][l-1]+MOD)%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n, &a, &b, &k);
    f[0][a] = 1;
    fto(y, a, n) d[0][y] = 1;

    fto(i, 1, k) {
        fto(y, 1, b-1)
            f[i][y] = (Calc(i-1, 1, (y+b-1)/2)-f[i-1][y]+MOD)%MOD;
        fto(y, b+1, n)
            f[i][y] = (Calc(i-1, (y+b)/2+1, n)-f[i-1][y]+MOD)%MOD;
        fto(y, 1, n) d[i][y] = (d[i][y-1]+f[i][y])%MOD;
    }

//    fto(i, 0, k) {
//        fto(y, 0, n) printf("%d ", f[i][y]);
//        puts("");
//    }
//    fto(i, 0, k) {
//        fto(y, 0, n) printf("%d ", d[i][y]);
//        puts("");
//    }

    printf("%d\n", d[k][n]);

    return 0;
}