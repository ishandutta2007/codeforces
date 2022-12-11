#include <bits/stdc++.h>
using namespace std;

char dat[1005][1005];
int dist[1005][1005];

constexpr int dr[4][2]=
{
    {1,0},
    {0,-1},
    {0,1},
    {-1,0}
};
constexpr char lt[4] =
{
    'D','L','R','U'
};

void bfs(int x, int y)
{
    queue<pair<int,int>> que;
    dist[x][y] = 1;
    que.emplace(x, y);
    while (que.empty() == false)
    {
        tie(x, y) = que.front();
        que.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dr[j][0];
            int ny = y + dr[j][1];
            if (dat[nx][ny] == '.' || dat[nx][ny] == 'X')
            {
                if (dist[nx][ny]) continue;
                dist[nx][ny] = dist[x][y] + 1;
                que.emplace(nx, ny);
            }
        }
    }
}

int main()
{
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    if (k % 2)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) scanf("%s", dat[i] + 1);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dat[i][j] == 'X')
            {
                x = i; y = j;
            }
        }
    }

    bfs(x, y);

    string ans;
    for (int i = 0; i < k; i++)
    {
        int j;
        for (j = 0; j < 4; j++)
        {
            int nx = x + dr[j][0];
            int ny = y + dr[j][1];
            if ((dat[nx][ny] == '.' || dat[nx][ny] == 'X') &&
                dist[nx][ny] - 1 <= k - i - 1)
            {
                x = nx; y = ny;
                ans.push_back(lt[j]);
                break;
            }
        }
        if (j == 4)
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    printf("%s\n", ans.c_str());
}