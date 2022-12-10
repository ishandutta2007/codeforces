#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 105;

int n, m, q;
int res[N][N];
pair<int, int> who[N][N];

void shift_row_left(int r)
{
    auto x = who[r][0];
    for (int i = 0; i + 1 < m; i++)
        who[r][i] = who[r][i + 1];
    who[r][m - 1] = x;
}

void shift_col_up(int c)
{
    auto x = who[0][c];
    for (int i = 0; i + 1 < n; i++)
        who[i][c] = who[i + 1][c];
    who[n - 1][c] = x;
}

void apply(int r, int c, int x)
{
    auto p = who[r][c];
    res[p.first][p.second] = x;
}

void solve()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            who[i][j] = make_pair(i, j);

    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int r;
            scanf("%d", &r);
            r--;
            shift_row_left(r);
        }
        if (t == 2)
        {
            int c;
            scanf("%d", &c);
            c--;
            shift_col_up(c);
        }
        if (t == 3)
        {
            int r, c, x;
            scanf("%d%d%d", &r, &c, &x);
            r--; c--;
            apply(r, c, x);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}