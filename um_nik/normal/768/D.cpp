#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

typedef long double ld;

const int N = 1010;
int n;
ld dp[2][N];
int ans[N];

void solve()
{
    dp[0][0] = 1;
    int pos = 0;
    for (int t = 1; pos < 1000; t++)
    {
        for (int i = 0; i <= n; i++)
            dp[1][i] = 0;
        dp[1][n] = dp[0][n];
        for (int i = 0; i < n; i++)
        {
            dp[1][i] += dp[0][i] * i / n;
            dp[1][i + 1] += dp[0][i] * (n - i) / n;
        }
        for (int i = 0; i <= n; i++)
            dp[0][i] = dp[1][i];
        while(pos < 1000 && pos + 1 <= 2000 * dp[0][n])
        {
            pos++;
            ans[pos] = t;
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int m;
    scanf("%d%d", &n, &m);
    solve();
    while(m--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }

    return 0;
}