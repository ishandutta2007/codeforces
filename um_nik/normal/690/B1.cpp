#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 51;
int n;
char a[N][N];

void solve()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", a[i]);
        for(int j = 0; j < n; ++j)
            a[i][j] -= '0';
    }
    int cnt4 = 0;
    int min_x = n, min_y = n;
    int max_x = 0, max_y = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if (a[i][j] == 4)
            {
                ++cnt4;
                min_x = min(min_x, i);
                min_y = min(min_y, j);
                max_x = max(max_x, i + 1);
                max_y = max(max_y, j + 1);
            }
    if (cnt4 == 0)
    {
        puts("No");
        return;
    }
    bool ok = true;
    for(int i = min_x; i < max_x; ++i)
        for(int j = min_y; j < max_y; ++j)
            ok &= a[i][j] == 4;
    if (min_x > 0)
    {
        for(int j = min_y; j < max_y; ++j)
            ok &= a[min_x - 1][j] == 2;
        if (min_y > 0)
            ok &= a[min_x - 1][min_y - 1] == 1;
        if (max_y < n)
            ok &= a[min_x - 1][max_y] == 1;
    }
    if (max_x < n)
    {
        for(int j = min_y; j < max_y; ++j)
            ok &= a[max_x][j] == 2;
        if (min_y > 0)
            ok &= a[max_x][min_y - 1] == 1;
        if (max_y < n)
            ok &= a[max_x][max_y] == 1;
    }
    if (min_y > 0)
    {
        for(int i = min_x; i < max_x; ++i)
            ok &= a[i][min_y - 1] == 2;
    }
    if (max_y < n)
    {
        for(int i = min_x; i < max_x; ++i)
            ok &= a[i][max_y] == 2;
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if (i < min_x - 1 || i > max_x || j < min_y - 1 || j > max_y)
                ok &= a[i][j] == 0;
    puts(ok ? "Yes" : "No");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}