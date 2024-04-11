#include <bits/stdc++.h>
using namespace std;

const int N = 16, K = 121;
int dp[1<<N][K];
int bsum[1<<N];
int rsum[1<<N];

char t[N];
int r[N];
int b[N];

int main()
{
    int n;
    const int none = -1000;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %c %d %d", t + i, r + i, b + i);
    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
                if(t[j] == 'R') rsum[i]++;
                else bsum[i]++;
        for(int j = 1; j < K; j++)
            dp[i][j] = none;
    }
    for(int i = 1; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
            {
                int k = i ^ (1 << j);
                int sb = min(b[j], bsum[k]);
                int sr = min(r[j], rsum[k]);
                for(int l = 0; l + sb < K; l++)
                    dp[i][l+sb] = max(dp[i][l+sb], dp[k][l] + sr);
            }
    }
    int all = (1 << n) - 1;
    int tb = 0, tr = 0;
    for(int i = 0; i < n; i++)
    {
        tb += b[i];
        tr += r[i];
    }
    int ans = max(tb, tr);
    for(int j = 0; j < K; j++)
        if(dp[all][j] >= 0) ans = min(ans, max(tb - j, tr - dp[all][j]));
    printf("%d\n", ans + n);
}