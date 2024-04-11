#include <bits/stdc++.h>
using namespace std;

char dat[1005][1005];
bool visit[1005][1005][4][4];

constexpr int dr[4][2] = 
{
    1,0,
    0,1,
    -1,0,
    0,-1
};

int main()
{
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> dat[i] + 1;
    }

    int sx, sy;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        if (dat[i][j] == 'S')
        {
            sx = i; sy = j; goto out;
        }
    }

out:

    queue<tuple<int,int,int,int>> que;
    visit[sx][sy][0][0] = visit[sx][sy][1][0] = visit[sx][sy][2][0] = visit[sx][sy][3][0] = true;
    que.emplace(sx,sy,0,0);
    que.emplace(sx,sy,1,0);
    que.emplace(sx,sy,2,0);
    que.emplace(sx,sy,3,0);

    while (que.empty() == false)
    {
        int x, y, d, w;
        tie(x, y, d, w) = que.front(); que.pop();

        if (dat[x][y] == 'T')
        {
            printf("YES\n");
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            if (visit[x][y][i][w + 1]) continue;
            if (w == 2) continue;

            visit[x][y][i][w + 1] = true;
            que.emplace(x, y, i, w + 1);
        }

        int nx = x + dr[d][0];
        int ny = y + dr[d][1];
        if (dat[nx][ny] != '.' && dat[nx][ny] != 'T') continue;
        if (visit[nx][ny][d][w]) continue;
        visit[nx][ny][d][w] = true;
        que.emplace(nx, ny, d, w);
    }

    printf("NO\n");
}