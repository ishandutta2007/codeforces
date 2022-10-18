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
#define maxN 85
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

void minimize(int &a, int b) {a = min(a, b);}

int n, K, m, c[maxN][maxN], dp[maxN][maxN][maxN][2];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &K);
    fto(u, 0, n+1) fto(v, 0, n+1) c[u][v] = oo;
    fto(u, 1, n) c[0][u] = c[n+1][u] = 0;
    scanf("%d", &m);
    fto(i, 1, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        c[u][v] = min(c[u][v], w);
    }
//    fto(u, 0, n+1) {
//        fto(v, 0, n+1) printf("%d ", c[u][v]);
//        puts("");
//    }
    fto(u, 0, n+1) fto(v, 0, n+1) fto(k, 0, K) fto(side, 0, 1) dp[u][v][k][side] = oo;
    fto(u, 1, n) dp[0][u][1][1] = dp[u][n+1][1][0] = 0;

    fto(i, 0, n+1) {
        fdto(j, n+1, i+1) {
            fto(k, 1, K-1) {
                fto(v, i+1, j-1) {
                    minimize(dp[i][v][k+1][1], dp[i][j][k][0]+c[i][v]);
                    minimize(dp[v][j][k+1][0], dp[i][j][k][0]+c[i][v]);
                    minimize(dp[i][v][k+1][1], dp[i][j][k][1]+c[j][v]);
                    minimize(dp[v][j][k+1][0], dp[i][j][k][1]+c[j][v]);
                }
            }
        }
    }

    int ans = oo;
    fto(i, 0, n+1) fto(j, i+1, n+1) fto(side, 0, 1) ans = min(ans, dp[i][j][K][side]);
    if (ans == oo) ans = -1;
    printf("%d", ans);

    return 0;
}