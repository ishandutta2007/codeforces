#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 10;
int add(int x, int y)
{
    return min(INF, x + y);
}

const int N = 5004;
int n;
int sz[N];
int par[N];
int dp[N][2][N];
int B;
int a[N][2];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &B);
    scanf("%d%d", &a[0][0], &a[0][1]);
    a[0][1] = a[0][0] - a[0][1];
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &par[i]);
        par[i]--;
        a[i][1] = a[i][0] - a[i][1];
    }
    for (int i = 0; i < n; i++) {
        sz[i] = 1;
        dp[i][0][0] = 0;
        dp[i][0][1] = a[i][0];
        dp[i][1][0] = INF;
        dp[i][1][1] = a[i][1];
        for (int j = 2; j <= n + 1; j++)
            dp[i][0][j] = dp[i][1][j] = INF;
    }
    for (int v = n - 1; v > 0; v--) {
        int u = par[v];
        for (int i = 0; i <= sz[v]; i++)
            dp[v][1][i] = min(dp[v][1][i], dp[v][0][i]);
        for (int i = sz[u]; i >= 0; i--)
            for (int j = sz[v]; j >= 0; j--) {
                for (int k = 0; k < 2; k++) {
                    dp[u][k][i + j] = min(dp[u][k][i + j], add(dp[u][k][i], dp[v][k][j]));
                }
            }
        sz[u] += sz[v];
    }
    for (int i = 0; i <= sz[0]; i++)
        dp[0][1][i] = min(dp[0][1][i], dp[0][0][i]);

/*
    for (int v = 0; v < n; v++) {
        printf("v = %d, sz = %d\n", v, sz[v]);
        for (int i = 0; i <= sz[v]; i++)
            printf("%d ", dp[v][1][i]);
        printf("\n");
    }
*/

    int ans = 0;
    while(ans < sz[0] && dp[0][1][ans + 1] <= B) ans++;
    printf("%d\n", ans);

    return 0;
}