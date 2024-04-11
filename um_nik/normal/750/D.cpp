#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 330;
const int Z = 160;
int n;
int a[N];
bool ans[N][N];
bool b[2][N][N][8];
const int DX[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int DY[] = {1, 1, 0, -1, -1, -1, 0, 1};

void solve(int t)
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            for (int k = 0; k < 8; k++)
                b[1][x][y][k] = 0;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            for (int k = 0; k < 8; k++)
            {
                if (!b[0][x][y][k]) continue;
                int xx = x, yy = y;
                for (int i = 0; i < t; i++)
                {
                    xx += DX[k];
                    yy += DY[k];
                    ans[xx][yy] = 1;
                }
                b[1][xx][yy][(k + 8 - 1) % 8] = 1;
                b[1][xx][yy][(k + 1) % 8] = 1;
            }
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            for (int k = 0; k < 8; k++)
                b[0][x][y][k] = b[1][x][y][k];
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ans[Z][Z] = 1;
    b[0][Z][Z][0] = 1;
    a[0]--;
    for (int i = 0; i < n; i++)
        solve(a[i]);
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res += (int)ans[i][j];
    printf("%d\n", res);

    return 0;
}