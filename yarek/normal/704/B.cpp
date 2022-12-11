#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline bool checkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T> inline bool checkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

const int N = 5005;
const ll inf = 1e17;
ll dp[N][N];
int x[N];
int a[N];
int b[N];
int c[N];
int d[N];

int main()
{
    int n, s, e;
    scanf("%d %d %d", &n, &s, &e);
    for(int i = 1; i <= n; i++)
        scanf("%d", x + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", b + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", c + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", d + i);
    if(s > e)
    {
        swap(s, e);
        for(int i = 1; i <= n; i++)
        {
            swap(a[i], c[i]);
            swap(b[i], d[i]);
        }
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n + 3; j++)
            dp[i][j] = inf;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
            ll dist = x[i] - x[i-1];
            if(i < s)
            {
                if(j == 0) continue;
                checkmin(dp[i][j], dp[i-1][j] + min(b[i] + c[i], a[i] + d[i]) + j * 2 * dist);
                checkmin(dp[i][j], dp[i-1][j-1] + b[i] + d[i] + (j - 1) * 2 * dist);
                if(j < n) checkmin(dp[i][j], dp[i-1][j+1] + a[i] + c[i] + (j + 1) * 2 * dist);
            }
            else if(i == s)
            {
                checkmin(dp[i][j], dp[i-1][j] + d[i] + j * 2 * dist);
                if(j < n) checkmin(dp[i][j], dp[i-1][j+1] + c[i] + (j + 1) * 2 * dist);
            }
            else if(i < e)
            {
                checkmin(dp[i][j], dp[i-1][j] + a[i] + d[i] + (j * 2 + 1) * dist);
                if(j > 0)
                {
                    checkmin(dp[i][j], dp[i-1][j] + b[i] + c[i] + (j * 2 + 1) * dist);
                    checkmin(dp[i][j], dp[i-1][j-1] + b[i] + d[i] + ((j - 1) * 2 + 1) * dist);
                }
                if(j < n) checkmin(dp[i][j], dp[i-1][j+1] + a[i] + c[i] + ((j + 1) * 2 + 1) * dist);
            }
            else if(i == e)
            {
                if(i != n && j == 0) continue;
                checkmin(dp[i][j], dp[i-1][j] + a[i] + (j * 2 + 1) * dist);
                if(j > 0) checkmin(dp[i][j], dp[i-1][j-1] + b[i] + ((j - 1) * 2 + 1) * dist);
            }
            else
            {
                if(i != n && j == 0) continue;
                checkmin(dp[i][j], dp[i-1][j] + min(b[i] + c[i], a[i] + d[i]) + j * 2 * dist);
                if(j > 0) checkmin(dp[i][j], dp[i-1][j-1] + b[i] + d[i] + (j - 1) * 2 * dist);
                if(j < n) checkmin(dp[i][j], dp[i-1][j+1] + a[i] + c[i] + (j + 1) * 2 * dist);
            }
        }
    printf("%lld\n", dp[n][0]);
}