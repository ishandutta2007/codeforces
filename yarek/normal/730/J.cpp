#include <bits/stdc++.h>
using namespace std;

const int N = 101;
pair<int, int> p[N];
int sum[N];
int dp[N][N*N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i].second);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i].first);
    sort(p + 1, p + n + 1);
    int k = 0;
    int sumA = 0;
    for(int i = 1; i <= n; i++)
        sumA += p[i].second;
    int sumB = 0;
    for(int i = n; i > 0; i--)
    {
        sumB += p[i].first;
        if(sumB >= sumA)
        {
            k = n - i + 1;
            break;
        }
    }
    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= sumA; j++)
            dp[i][j] = -1000000000;
    for(int i = 1; i <= n; i++)
        for(int k = i; k >= 1; k--)
            for(int j = 0; j <= sumA; j++)
            {
                int l = min(sumA, j + p[i].first);
                dp[k][l] = max(dp[k][l], dp[k-1][j] + p[i].second);
            }
    printf("%d %d\n", k, sumA - dp[k][sumA]);
}