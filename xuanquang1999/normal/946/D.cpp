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
#define maxN 505
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

int n, m, k, c[maxN][maxN], dp[maxN][maxN];
char s[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 0, n-1) scanf("%s", &s[i]);

    fto(i, 1, n) {
        vector<int> p;
        fto(j, 0, m-1)
            if (s[i-1][j] == '1') p.pb(j);
        fto(j, 0, sz(p)-1) {
            int len = sz(p)-j;
            c[i][j] = oo;
            fto(k, 0, sz(p)-len) c[i][j] = min(c[i][j], p[k+len-1]-p[k]+1);
        }
    }
//    fto(i, 1, n) {
//        fto(j, 0, k) printf("%d ", c[i][j]);
//        puts("");
//    }

    fto(i, 1, n) {
        fto(j, 0, k) {
            dp[i][j] = oo;
            fto(p, 0, j) dp[i][j] = min(dp[i][j], dp[i-1][j-p]+c[i][p]);
        }
    }

    printf("%d", dp[n][k]);

    return 0;
}