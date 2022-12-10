#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 105;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, -1, 0, 1};

int n, m;
char board[N][N];
bool used[N][N];

bool in_board(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y)
{
    used[x][y] = true;
    for (int d = 0; d < 4; d++)
    {
        int nx = x + DX[d];
        int ny = y + DY[d];
        if (!in_board(nx, ny))
            continue;
        if (board[nx][ny] == '.')
            continue;
        if (used[nx][ny])
            continue;
        dfs(nx, ny);
    }
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", board[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!used[i][j] && board[i][j] == 'B')
            {
                dfs(i, j);
                cnt++;
            }

    printf("%d\n", cnt);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}