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
const int SZ = 6;
const int DX[SZ] = {-1, 1, 0, 0, 0, 0};
const int DY[SZ] = {0, 0, -1, 1, 0, 0};
const int DZ[SZ] = {0, 0, 0, 0, -1, 1};

int n, m, k;
char board[N][N][N];

bool in_board(int x, int y, int z)
{
    return 0 <= x && x < n &&
        0 <= y && y < m &&
        0 <= z && z < k;
}

bool is_critical(int a, int b, int c)
{
    for (int d1 = 0; d1 < SZ; d1++)
        for (int d2 = 0; d2 < SZ; d2++)
        {
            if (d1 == d2)
                continue;

            int x1 = a + DX[d1];
            int y1 = b + DY[d1];
            int z1 = c + DZ[d1];
            int x2 = a + DX[d2];
            int y2 = b + DY[d2];
            int z2 = c + DZ[d2];
            if (x1 > x2 || y1 > y2 || z1 > z2)
                continue;
            if (!in_board(x1, y1, z1) || !in_board(x2, y2, z2))
                continue;
            if (board[x1][y1][z1] != '1' || board[x2][y2][z2] != '1')
                continue;

            if (d1 / 2 == d2 / 2)
                return true;

            int x = a;
            if (x1 != x)
                x = x1;
            else if (x2 != x)
                x = x2;
            int y = b;
            if (y1 != y)
                y = y1;
            else if (y2 != y)
                y = y2;
            int z = c;
            if (z1 != z)
                z = z1;
            else if (z2 != z)
                z = z2;

            assert(in_board(x, y, z));
            if (board[x][y][z] != '1')
                return true;
        }

    return false;
}

void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%s", board[i][j]);

    int cnt = 0;
    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++)
            for (int c = 0; c < k; c++)
                if (board[a][b][c] == '1' && is_critical(a, b, c))
                    cnt++;

    printf("%d\n", cnt);
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