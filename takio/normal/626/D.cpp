#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 5010, M = 15005;

//double dp[N][N];
LL c[N], c2[N];
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            c[abs (a[i] - a[j])]++;
        }
    }
//    for (int i = 1; i < N; i++) c[i] /= n * (n - 1) / 2;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) if (i + j < N) {
            c2[i + j] += c[i] * c[j];
        }
    }
    long double res = 0.00;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) if (i - j < 0) {
            res += (long double)c2[i] * c[j];
        }
    }
    int tmp = n * (n - 1) / 2;
    res /= tmp;
    res /= tmp;
    res /= tmp;
    printf ("%.10f\n", (double) res);
}