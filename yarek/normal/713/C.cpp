#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3001;
ll dp[N][N];
int a[N];
int x[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        a[i] -= i;
        x[i-1] = a[i];
    }
    sort(x, x + n);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = dp[i-1][j] + abs(a[i] - x[j]);
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    printf("%lld\n", dp[n][n-1]);
}