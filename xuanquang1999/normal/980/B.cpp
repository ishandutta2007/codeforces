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
#define MOD 1000
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

int n, k, dp1[4][maxN], dp2[4][maxN];
char ans[4][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 0, 3) {
        fto(j, 0, n-1) ans[i][j] = '.';
        ans[i][n] = '\0';
    }

    if (k == 1) ans[1][n/2] = '#';
    else if (k == 3) {
        int offset = (n-k-2)/2;
        fto(j, 1, 3) ans[1][j+offset] = '#';
    } else {
        int x = (k+1)/2;
        fto(j, 1, x) ans[1][j] = ans[2][j] = '#';
        if (k%2 == 1) ans[1][2] = '.';
    }

    puts("YES");
    fto(i, 0, 3) puts(ans[i]);

    dp1[0][0] = 1; dp2[0][n-1] = 1;
    fto(i, 0, 3) {
        fto(j, 0, n-1) {
            if (ans[i][j] != '#') {
                if (i > 0) dp1[i][j] += dp1[i-1][j];
                if (j > 0) dp1[i][j] += dp1[i][j-1];
            }
        }
        fdto(j, n-1, 0) {
            if (ans[i][j] != '#') {
                if (i > 0) dp2[i][j] += dp2[i-1][j];
                if (j < n-1) dp2[i][j] += dp2[i][j+1];
            }
        }
    }
//    printf("%d %d\n", dp1[3][n-1], dp2[3][0]);


    return 0;
}