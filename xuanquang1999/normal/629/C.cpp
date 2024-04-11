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
#define maxK 2005
#define maxN 100005
#define oo 1000000000000000007LL
#define MOD 1000000007
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

int add(int &a, int b) {
    a += b;
    if (a > MOD) a -= MOD;
}

int n, m, k, minD, curD, dp[maxK][maxK][2];
char s[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    k = n-m;
    scanf("%s", s);

    fto(i, 0, m-1) {
        curD += (s[i] == '(') ? 1 : -1;
        minD = min(minD, curD);
    }

//    debug(curD);
//    debug(minD);

    dp[0][0][0] = 1;
    fto(i, 0, k) {
        fto(j, -minD, maxK-1) {
            if (j+curD >= 0 && j+curD < maxK) add(dp[i][j+curD][1], dp[i][j][0]);
        }
        if (i < k) {
            fto(j, 0, maxK-1) {
                fto(p, 0, 1) {
                    if (j+1 < maxK) add(dp[i+1][j+1][p], dp[i][j][p]);
                    if (j > 0) add(dp[i+1][j-1][p], dp[i][j][p]);
                }
            }
        }
    }
//    fto(p, 0, 1) {
//        debug(p);
//        fto(i, 0, k) {
//            fto(j, 0, k) printf("%d ", dp[i][j][p]);
//            puts("");
//        }
//    }

    printf("%d", dp[k][0][1]);

    return 0;
}