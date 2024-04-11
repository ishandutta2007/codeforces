#include <bits/stdc++.h>
using namespace std;

int d[2000];
int n;

long long dp[2000][2000];
bool vis[2000][2000];
long long D(int a, int b)
{
    if (a == b) return 0;
    if (!vis[a][b])
    {
        vis[a][b] = true;
        dp[a][b] = min(D(a+1, b), D(a, b-1)) + d[b] - d[a];
    }
    return dp[a][b];
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    sort(d, d + n);
    printf("%lld\n", D(0, n - 1));
}