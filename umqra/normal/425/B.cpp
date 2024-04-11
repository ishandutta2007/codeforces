#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int INF = (int)1e9;
const int N = 200;
int a[N][N];
int dp[N][(1 << 11)];
int tmp[N][N];

void hardSolve(int n, int m, int k)
{
    for (int i = 0; i < N; i++)
        for (int s = 0; s < (1 << 11); s++)
            dp[i][s] = INF;

    for (int i = 0; i < (1 << n); i++)
    {
        int val = 0;
        for (int s = 0; s < n; s++)
        {
            int t = ((i & (1 << s)) ? 1 : 0);
            val += (t ^ a[s][0]);
        }
        dp[1][i] = val;
    }
    int T = ((1 << n) - 1);
    for (int i = 1; i < m; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int val1 = 0, val2 = 0;
            for (int s = 0; s < n; s++)
            {
                int t = ((mask & (1 << s)) ? 1 : 0);
                val1 += (t ^ a[s][i]);
                t = (t == 1 ? 0 : 1);
                val2 += (t ^ a[s][i]);
            }
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask] + val1);
            dp[i + 1][mask ^ T] = min(dp[i + 1][mask ^ T], dp[i][mask] + val2);
        }
    }
    int ans = INF;
    for (int i = 0; i < (1 << n); i++)
        ans = min(ans, dp[m][i]);
    if (ans > k)
        puts("-1");
    else
        printf("%d", ans);
}

void simpleSolve(int n, int m, int k)
{
    int ans = k + 1;
    for (int i = 0; i < k + 1; i++)
        for (int s = 0; s < k + 1; s++)
        {
            int res = 0;
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    int old = a[i][y];
                    int ch = a[x][s];
                    int c = a[i][s];
                    if (c == ch)
                        res += (old ^ a[x][y]);
                    else
                    {
                        old ^= 1;
                        res += (old ^ a[x][y]);
                    }
                }
            }
            ans = min(ans, res);
        }
    if (ans > k)
    {
        puts("-1");
    }
    else
    {
        printf("%d", ans);
    }
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);    
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
            scanf("%d", &a[i][s]);
    if (n >= k + 1 && m >= k + 1)
    {
        simpleSolve(n, m, k);
        return 0;
    }
    else if (n < k + 1)
    {
        hardSolve(n, m, k);
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
            for (int s = 0; s < m; s++)
                tmp[s][i] = a[i][s];
        for (int i = 0; i < m; i++)
            for (int s = 0; s < n; s++)
                a[i][s] = tmp[i][s];
        hardSolve(m, n, k);
        return 0;
    }

    return 0;
}