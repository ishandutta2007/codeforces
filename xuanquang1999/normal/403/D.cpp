//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define maxN 1005
#define maxK 45
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

void add(int &a, ll b) {a = (a+b)%MOD;}
int mul(int a, int b) {return (1LL*a*b)%MOD;}

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return mul(x, power(x, n-1));
    int p = power(x, n/2);
    return mul(p, p);
}

int sum[maxK][maxN][maxN], fact[maxN], invFact[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

//    fto(i, 0, maxK-1) {
//        if (i == 0) dp[0][0][0] = 1;
//        else {
//            fto(j, 1, maxN-1) {
//                fto(k, 1, j) add(dp[i][j][k], sum[i-1][j-k][k-1]);
//            }
//        }
//
//        fto(j, 0, maxN-1) {
//            sum[i][j][0] = dp[i][j][0];
//            fto(k, 1, maxN-1) sum[i][j][k] = (sum[i][j][k-1]+dp[i][j][k])%MOD;
//        }
//    }

    fto(i, 0, maxK-1) {
        if (i == 0) {
            fto(k, 0, maxN-1) sum[0][0][k] = 1;
        } else {
            fto(j, 0, maxN-1) {
                fto(k, 1, maxN-1) {
                    add(sum[i][j][k], sum[i][j][k-1]);
                    if (k <= j) add(sum[i][j][k], sum[i-1][j-k][k-1]);
                }
            }
        }
    }

    invFact[0] = fact[0] = 1;
    fto(i, 1, maxN-1) {
        fact[i] = mul(fact[i-1], i);
        invFact[i] = power(fact[i], MOD-2);
    }

    int nTest; scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k >= maxK) puts("0");
        else {
            int ans = 0;
            fto(i, 0, n-k) add(ans, mul(sum[k][n-i][maxN-1], mul(fact[k+i], invFact[i])));
            printf("%d\n", ans);
        }
    }

    return 0;
}