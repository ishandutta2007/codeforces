#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

struct ver
{
    double r, s, p;
};
    ver dp[101][101][101];
    int r, s, p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> r >> s >> p;
    for(int i(0); i < 101; ++i)
    for(int j(0); j < 101; ++j)
        dp[i][0][j].p = dp[i][j][0].r = dp[0][i][j].s = 1, 
        dp[i][0][j].s = dp[i][0][j].r = dp[i][j][0].s = dp[i][j][0].p = dp[0][i][j].p = dp[0][i][j].r = 0;
    for(int i(1); i < 101; ++i)
    for(int j(1); j < 101; ++j)
    for(int k(1); k < 101; ++k)
        dp[i][j][k].p = (dp[i - 1][j][k].p * i * k + dp[i][j - 1][k].p * i * j + dp[i][j][k - 1].p * j * k) * 2 / ((i + j + k) * (i + j + k - 1) - (i - 1) * i - (j - 1) * j - (k - 1) * k),
        dp[i][j][k].s = (dp[i - 1][j][k].s * i * k + dp[i][j - 1][k].s * i * j + dp[i][j][k - 1].s * j * k) * 2 / ((i + j + k) * (i + j + k - 1) - (i - 1) * i - (j - 1) * j - (k - 1) * k),
        dp[i][j][k].r = (dp[i - 1][j][k].r * i * k + dp[i][j - 1][k].r * i * j + dp[i][j][k - 1].r * j * k) * 2 / ((i + j + k) * (i + j + k - 1) - (i - 1) * i - (j - 1) * j - (k - 1) * k);
    cout << setprecision(12) << fixed << dp[r][s][p].r << ' ' << dp[r][s][p].s << ' ' << dp[r][s][p].p;
    return 0;
}