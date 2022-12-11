#include <bits/stdc++.h>
using namespace std;

typedef double T;
const double inf = 1e15;
const int N = 101, K = 10 * N;
T dp[N][K];
T s[N];
pair<int, int> tab[N];

int main()
{
    s[0] = 1;
    for(int i = 1; i < N; i++)
        s[i] = s[i-1] * 0.9;
    int test;
    scanf("%d", &test);
    while(test--)
    {
        for(int j = 0; j < N; j++)
            for(int k = 0; k < K; k++)
                dp[j][k] = inf;
        dp[0][0] = 0;        
        
        int n;
        scanf("%d", &n);
        T c, t;
        scanf("%lf %lf", &c, &t);
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &tab[i].first, &tab[i].second);
        sort(tab + 1, tab + n + 1, greater<pair<int, int>>());
        for(int i = 1; i <= n; i++)
        {
            int a = tab[i].first, p = tab[i].second;
            for(int j = i; j > 0; j--)
                for(int k = p; k <= j * 10; k++)
                {
                    dp[j][k] = min(dp[j][k], dp[j-1][k-p] + a / s[j]);
                    //printf("dp[%d][%d][%d] = %lf\n", i, j, k, dp[j][k]);
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= i * 10; j++)
            {
                T x = dp[i][j];
                
                T r = t - i * 10;
                if(x <= r) ans = max(ans, j);
                T k = sqrt(c * x), tr = (k - 1) / c;
                if(tr > 0 && tr + x / (1 + c * tr) <= r)
                    ans = max(ans, j);
            }
        printf("%d\n", ans);
    }
}