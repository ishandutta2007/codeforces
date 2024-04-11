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
#define maxN 105
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

int power(int x, ll n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

int n, k, c[maxN][maxN], dp[maxN][maxN*maxN];
ll m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m >> k;

    fto(i, 0, n) {
        c[i][0] = 1;
        fto(j, 1, i) c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
    }

//    fto(i, 0, n) {
//        fto(j, 0, n) printf("%d ", c[i][j]);
//        puts("");
//    }

    dp[0][0] = 1;
    fto(i, 0, n-1) {
        fto(x, 0, n) {
            ll p = power(c[n][x], (m-i+n-1)/n);
            fto(j, 0, k-x)
                dp[i+1][j+x] = (dp[i+1][j+x]+1LL*dp[i][j]*p)%MOD;
        }
    }

    printf("%d", dp[n][k]);

    return 0;
}