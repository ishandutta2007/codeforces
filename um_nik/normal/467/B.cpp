#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m, k;
int a[10100];
int x;
int ans;

int solve(int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (x & (1 << i))
            ans++;
    return ans;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    for (int i = 0; i < m; i++)
    {
        int y = x ^ a[i];
        if (solve(y) <= k)
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}