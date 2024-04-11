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
#define maxN 105
#define oo 1000000007
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

char s[maxN][maxN];
int m, n, dp[2][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &n);
    fto(i, 0, m-1) scanf("%s", s[i]);

    int x = -1;
    fto(i, 0, m-1) {
        if (x != -1) break;
        fto(j, 0, n+1) {
            if (s[i][j] == '1') {x = i; break;}
        }
    }

    if (x == -1) {puts("0"); return 0;}
//    debug(x);

    dp[0][m] = 0; dp[1][m] = oo;
    fdto(i, m-1, x+1) {
        int minC = n+1, maxC = 0;
        fto(c, 0, n+1) {
            if (s[i][c] == '1') {minC = min(minC, c); maxC = max(maxC, c);}
        }
        dp[0][i] = min(dp[1][i+1]+n+2, dp[0][i+1]+2*maxC+1);
        dp[1][i] = min(dp[0][i+1]+n+2, dp[1][i+1]+2*(n+1-minC)+1);
    }

//    fto(i, 0, m) {
//        printf("%d %d\n", dp[0][i], dp[1][i]);
//    }

    int minC = n+1, maxC = 0;
    fto(c, 0, n+1) {
        if (s[x][c] == '1') {minC = min(minC, c); maxC = max(maxC, c);}
    }

    printf("%d\n", min(dp[0][x+1]+maxC, dp[1][x+1]+(n+1-minC)));



    return 0;
}