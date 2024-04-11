#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 100100;
int n;
pii a[N];
int dp[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].X, &a[i].Y);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int x = a[i].X - a[i].Y;
        int p = lower_bound(a, a + n, mp(x, -1)) - a;
        dp[i + 1] = dp[p] + 1;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", n - ans);

    return 0;
}