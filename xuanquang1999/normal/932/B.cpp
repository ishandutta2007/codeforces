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
#define maxN 1000005
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

int g[maxN], dp[10][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 1, 9) g[i] = i;
    fto(i, 10, maxN-1) {
        int prod = 1, x = i;
        while (x > 0) {
            if (x%10 != 0) prod *= x%10;
            x /= 10;
        }
        g[i] = g[prod];
    }
    //fto(i, 1, 20) printf("%d %d\n", i, g[i]);

    fto(i, 1, maxN-1) {
        fto(k, 1, 9) dp[k][i] = dp[k][i-1];
        ++dp[g[i]][i];
    }

    int q; scanf("%d", &q);
    fto(i, 1, q) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", dp[k][r]-dp[k][l-1]);
    }

    return 0;
}