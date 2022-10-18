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
#define maxN 100005
#define maxK 20
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

int n, k, val[maxN], p[maxK][maxN], pMin[maxK][maxN], pMax[maxK][maxN];
set<int> success;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n) pMin[0][i] = -1, pMax[0][i] = oo;
    fto(i, 1, n) {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        val[i] = x;
        if (l > 0) {
            p[0][l] = i;
            pMax[0][l] = x;
        }
        if (r > 0) {
            p[0][r] = i;
            pMin[0][r] = x;
        }
    }

    k = log2(n)+1;
    fto(i, 1, k) {
        fto(u, 0, n) {
            p[i][u] = p[i-1][p[i-1][u]];
            pMin[i][u] = max(pMin[i-1][u], pMin[i-1][p[i-1][u]]);
            pMax[i][u] = min(pMax[i-1][u], pMax[i-1][p[i-1][u]]);
        }
    }


    fto(u, 1, n) {
        int lo = pMin[k][u], hi = pMax[k][u];
        if (lo <= val[u] && val[u] <= hi) success.insert(val[u]);
    }
    int ans = 0;
    fto(u, 1, n) {
        if (!success.count(val[u])) ++ans;
    }
    printf("%d", ans);

    return 0;
}