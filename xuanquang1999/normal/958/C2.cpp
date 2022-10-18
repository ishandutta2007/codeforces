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
#define maxN 20005
#define maxK 55
#define maxP 105
#define oo 1000000007
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

int n, k, p, a[maxN], dp[maxK][maxN], maxDP[maxP];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &k, &p);
    fto(i, 1, n) scanf("%d", &a[i]);

    dp[0][0] = 0;
    fto(i, 1, n) dp[0][i] = -oo;
    fto(j, 1, k) {
        fto(x, 0, p-1) maxDP[x] = -oo;

        maxDP[0] = dp[j-1][0];
        dp[j][0] = -oo;

        int sum = 0;
//        debug(j);
        fto(i, 1, n) {
//            debug(i);
//            fto(x, 0, p-1) printf("%d ", maxDP[x]);
//            puts("");
            sum = (sum+a[i])%p;
            dp[j][i] = -oo;
            fto(x, 0, p-1)
                dp[j][i] = max(dp[j][i], maxDP[x]+(sum-x+p)%p);
            maxDP[sum] = max(maxDP[sum], dp[j-1][i]);
        }
    }

//    fto(j, 0, k) {
//        fto(i, 0, n) printf("%d ", dp[j][i]);
//        puts("");
//    }

    printf("%d", dp[k][n]);


    return 0;
}