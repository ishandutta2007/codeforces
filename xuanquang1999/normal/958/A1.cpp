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
#define maxN 15
#define oo 1000000000000000007LL
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

int n;
char a[maxN][maxN], b[maxN][maxN], c[maxN][maxN], d[maxN][maxN];

bool isEqual(char a[][maxN], char b[][maxN]) {
    fto(i, 0, n-1) fto(j, 0, n-1)
        if (a[i][j] != b[i][j]) return false;
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%s", a[i]);
    fto(i, 0, n-1) scanf("%s", b[i]);

    fto(i, 0, 3) {
        fto(x, 0, n-1) fto(y, 0, n-1) c[n-y-1][x] = a[x][y];
        fto(x, 0, n-1) fto(y, 0, n-1) d[x][n-y-1] = c[x][y];
        if (isEqual(b, c) || isEqual(b, d)) {
            puts("Yes");
            return 0;
        }
        fto(x, 0, n-1) fto(y, 0, n-1) a[x][y] = c[x][y];
    }

    puts("No");

    return 0;
}