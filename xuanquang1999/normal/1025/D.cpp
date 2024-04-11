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

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a%b);
}

const int MAXN = 700 + 5;

int n, a[MAXN];
// 0: left; 1: right
bool dp[2][MAXN][MAXN], c[MAXN][MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n)
        fto(j, 1, n) c[i][j] = (GCD(a[i], a[j]) > 1);

    fto(i, 1, n+1)
        fto(side, 0, 1) dp[side][i][i-1] = true;

    fto(len, 1, n) {
        fto(l, 1, n-len+1) {
            int r = l+len-1;

            fto(side, 0, 1) {
                fto(i, l, r) {
                    bool connect = (side == 0) ? c[i][l-1] : c[i][r+1];
                    if (connect && dp[0][i+1][r] && dp[1][l][i-1]) {
                        dp[side][l][r] = true;
                        break;
                    }
                }
            }
        }
    }

    fto(i, 1, n) {
        if (dp[0][i+1][n] && dp[1][1][i-1]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}