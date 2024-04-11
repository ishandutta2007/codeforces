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
#define sz(a) (int)a.size()
#define maxN 18
#define oo 1000000000000000007LL
#define MOD 1000000007
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

int n;
double a[maxN][maxN], dp[maxN][1<<maxN];

int C2(int x) {return x*(x-1)/2;}

bool in(int mask, int i) {return (mask>>i)&1;}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1)
        fto(j, 0, n-1) scanf("%lf", &a[i][j]);


    fto(mask, 1, (1<<n)-1) {
        fto(i, 0, n-1) {
            if (in(mask, i)) {
                int numFish = __builtin_popcount(mask);
                if (numFish == 1) dp[i][mask] = 1;
                else {
                    int numPair = C2(numFish);
                    fto(j, 0, n-1) {
                        if (i != j && in(mask, j)) {
                            dp[i][mask] += dp[i][mask^(1<<j)]*a[i][j]/numPair;
                            fto(k, 0, n-1) {
                                if (i != k && j != k && in(mask, k)) {
                                    dp[i][mask] += dp[i][mask^(1<<j)]*a[k][j]/numPair;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    fto(i, 0, n-1) printf("%.9g ", dp[i][(1<<n)-1]);

    return 0;
}