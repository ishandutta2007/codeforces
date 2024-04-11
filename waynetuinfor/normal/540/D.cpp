#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
double dp[maxn][maxn][maxn];
int r, s, p;

double f(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> r >> s >> p;
    dp[r][s][p] = 1.0;
    double a = 0.0, b = 0.0, c = 0.0;
    for (int i = 1; i <= r; ++i) a += f(i, 0, 0);
    for (int i = 1; i <= s; ++i) b += f(0, i, 0);
    for (int i = 1; i <= p; ++i) c += f(0, 0, i);
    cout << fixed << setprecision(10) << a << ' ' << b << ' ' << c << endl;
    return 0;
}

double f(int i, int j, int k) {
    if (i > r || j > s || k > p) return 0.0;
    if (dp[i][j][k]) return dp[i][j][k];
    if (k || j) dp[i][j][k] += (double)((i + 1) * k) / (double)((i + 1) * k + k * j + (i + 1) * j) * f(i + 1, j, k);
    if (i || k) dp[i][j][k] += (double)((j + 1) * i) / (double)((j + 1) * i + i * k + (j + 1) * k) * f(i, j + 1, k);
    if (i || j) dp[i][j][k] += (double)((k + 1) * j) / (double)((k + 1) * j + i * j + (k + 1) * i) * f(i, j, k + 1);
    return dp[i][j][k];
}