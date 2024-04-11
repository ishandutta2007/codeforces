#include <bits/stdc++.h>
using namespace std;

char dp[5005][5005];
char palin[5005][5005];
int ans[5005];
char str[5005];

bool P(int a, int b)
{
    if (a > b) return true;
    if (palin[a][b] == -1)
    {
        palin[a][b] = str[a] == str[b] && P(a + 1, b - 1);
    }
    return palin[a][b];
}

int D(int a, int b)
{
    if (a > b) return 0;
    if (a == b) return 1;
    if (dp[a][b] == -1)
    {
        if (P(a, b) == false) dp[a][b] = 0;
        else dp[a][b] = 1 + min(
            D(a, (a + b - 1) / 2),
            D((a + b + 2) / 2, b)
        );
    }
    return dp[a][b];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    memset(palin, -1, sizeof(palin));
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            ans[D(i, j)]++;
        }
    }
    for (int i = len; i >= 1; i--) ans[i] += ans[i + 1];

    for (int i = 1; i <= len; i++) printf("%d ", ans[i]);
    printf("\n");
}