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
#define maxN 1005
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

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

int inv(int x) {return power(x, MOD-2);}

int add(int a, int b) {a += b; if (a >= MOD) a -= MOD; return a;}

int mul(int a, int b) {return (1LL*a*b)%MOD;}

int k, a, b, ib, dp[maxN][maxN];

int Solve(int i, int j) {
    if (j >= k) return j;
    if (i+j >= k) return add(j+i-1, ib);
    if (dp[i][j] != -1) return dp[i][j];

    int xa = mul(Solve(i+1, j), a), xb = mul(Solve(i, j+i), b);
    return dp[i][j] = add(xa, xb);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &k, &a, &b);

    int c = a+b;
    a = mul(a, inv(c));
    b = mul(b, inv(c));
    ib = inv(b);

    fto(i, 0, maxN-1) fill(dp[i], dp[i]+maxN, -1);
    cout << Solve(1, 0);


    return 0;
}