#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#define LL long long
#define pii pair <int, int>
#define ULL unsigned long long
using namespace std;

const int N = 210, M = 33;
double dp[N][M][M];
int a[M];

int rev (int l, int r, int x) {
    return l + r - x;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) dp[0][i][j] = 1;
        }
    }
    int all = n * (n + 1) / 2;
    double a2 = 1.0 / all;
    for (int o = 0; o < k; o++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int ii = 1; ii <= n; ii++) {
                    for (int jj = ii; jj <= n; jj++) {
                        double t = dp[o][i][j] / all;
                        if (j < ii || jj < i || (i < ii && jj < j)) dp[o + 1][i][j] += t;
                        else if (ii <= i && i <= jj && jj < j) dp[o + 1][rev (ii, jj, i)][j] += t;
                        else if (i < ii && ii <= j && j <= jj) dp[o + 1][i][rev (ii, jj, j)] += t;
                        else dp[o + 1][rev (ii, jj, j)][rev (ii, jj, i)] += a2 - t;
                    }
                }
            }
        }
    }
    double res = 0;
//    for (int o = 0; o <= n; o++) {
//        for (int i = 1; i <= n; i++) {
//            for (int j = i + 1; j <= n; j++) {
//                cout << dp[o][i][j] << ' ';
//            } cout << endl;
//        } cout << endl;
//    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            res += dp[k][i][j];
        }
    }
    printf ("%.12f", res);
}