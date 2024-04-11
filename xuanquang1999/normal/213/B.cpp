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
#define maxN 105
#define oo 10000000000007LL
#define EPS 1e-9
#define MOD 1000000007

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

int n, a[10], f[maxN][10], C[maxN][maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, 9) scanf("%d", &a[i]);
    fto(i, 0, n) {
        C[i][0] = 1;
        fto(j, 1, i) C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
    }

    fto(len, 0, n) {
        f[len][9] = (len >= a[9]);
        fdto(d, 8, 1) {
            fto(k, a[d], len) f[len][d] = (f[len][d]+(ll)f[len-k][d+1]*C[len][k])%MOD;
        }
        if (len > 0)
            fto(k, a[0], len) f[len][0] = (f[len][0]+(ll)f[len-k][1]*C[len-1][k])%MOD;
    }

//    fto(i, 0, n) {
//        fto(d, 0, 9) printf("%d ", f[i][d]);
//        puts("");
//    }
    int ans = 0;
    fto(i, 0, n) ans = (ans+f[i][0])%MOD;
    printf("%d", ans);

    return 0;
}