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
int mult(int x, int y)
{
    return ((ll)x * y) % MOD;
}

const int N = (int)1e6 + 3;
const int K = 20;
int d[N];
int dp[N][K];

int main()
{
    
    for (int x = 2; x < N; x++)
        d[x] = -1;
    for (int x = 2; x < N; x++)
    {
        if (d[x] != -1) continue;
        for (int y = x; y < N; y += x)
            if (d[y] == -1)
                d[y] = x;
    }
    dp[0][0] = 1;
    for (int i = 1; i < K; i++)
        dp[0][i] = 2;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < K; j++)
            dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
    }

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int ans = 1;
        while(y > 1)
        {
            int p = d[y];
            int t = 0;
            while(y % p == 0)
            {
                t++;
                y /= p;
            }
            ans = mult(ans, dp[x][t]);
        }
        printf("%d\n", ans);
    }

    return 0;
}