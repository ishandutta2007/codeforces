#include <bits/stdc++.h>
using namespace std;

char dat[256][256];
unsigned short visit[256][256];
int val[256][256];
unsigned short vtime;
int n, m, q, p;

constexpr int dr[4][2]=
{
    1,0,
    0,1,
    -1,0,
    0,-1
};

void bfs(int x, int y)
{
    ++vtime;

    queue<tuple<int, int, int>> que;
    val[x][y] += (dat[x][y] - 'A' + 1) * q;
    visit[x][y] = vtime;
    que.emplace(x, y, (dat[x][y] - 'A' + 1) * q);

    while (que.empty() == false)
    {
        int w;
        tie(x, y, w) = que.front();
        que.pop();
        if (w <= 1) continue;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dr[d][0];
            int ny = y + dr[d][1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dat[nx][ny] == '*') continue;

            if (visit[nx][ny] == vtime) continue;

            visit[nx][ny] = vtime;
            val[nx][ny] += w / 2;
            que.emplace(nx, ny, w / 2);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> q >> p;

    for (int i = 0; i < n; i++) cin >> dat[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dat[i][j] >= 'A' && dat[i][j] <= 'Z')
            {
                bfs(i, j);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] > p) ++ans;
        }
    }

    printf("%d\n", ans);
}