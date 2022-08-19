#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = (int)1e6 + 100;
int n;
int deg[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;y--;
        deg[x]++;
        deg[y]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += deg[i] * (deg[i] - 1) / 2;
    printf("%d\n", ans);
    return;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}