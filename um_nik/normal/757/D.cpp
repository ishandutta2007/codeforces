#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}

const int N = 77;
const int M = (1 << 20);
int n;
char s[N];
int a[N];
int dp[N][M + 3];

int main()
{
    
    scanf("%d", &n);
    scanf(" %s ", s);
    for (int i = 0; i < n; i++)
        a[i] = (int)(s[i] - '0');

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int l = 0; l < n; l++)
    {
        int x = 0;
        for (int r = l + 1; r <= n; r++)
        {
            x = 2 * x + a[r - 1];
            if (x == 0) continue;
            if (x > 20) break;
            for (int i = 0; i < M; i++)
                dp[r][i | (1 << (x - 1))] = add(dp[r][i | (1 << (x - 1))], dp[l][i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 20; j++)
            ans = add(ans, dp[i][(1 << j) - 1]);
    printf("%d\n", ans);

    return 0;
}