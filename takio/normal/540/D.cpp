#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 110;

double dp[N][N][N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    double res1 = 0, res2 = 0, res3 = 0;
    dp[a][b][c] = 1.0;
    for (int i = a; i >= 0; i--) {
        for (int j = b; j >= 0; j--) {
            for (int k = c; k >= 0; k--) {
                int all = i * j + j * k + i * k;
//                cout << i << ' ' << j << ' ' << k << ' ' << all << endl;
                if (i && j) dp[i][j - 1][k] += dp[i][j][k] * i * j / all;
                if (j && k) dp[i][j][k - 1] += dp[i][j][k] * j * k / all;
                if (k && i) dp[i - 1][j][k] += dp[i][j][k] * k * i / all;
                if (!j && !k) res1 += dp[i][j][k];
                if (!i && !k) res2 += dp[i][j][k];
                if (!i && !j) res3 += dp[i][j][k];
            }
        }
    }
    printf ("%.12f %.12f %.12f", res1, res2, res3);
//    while (cin >> a >> b >> c) cout <<dp[a][b][c] <<endl;
}