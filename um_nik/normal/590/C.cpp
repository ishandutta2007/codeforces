#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = (int)1e8;
const int N = 1010;
int ans = INF;
char s[N][N];
int dist[3][N][N];
int q[N * N][2];
int topQ;
int n, m;
const int DX[4] = {0, 1, 0, -1};
const int DY[4] = {1, 0, -1, 0};

bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return s[x][y] != '#';
}

void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf(" %s ", s[i]);
    return;
}

void addQ(int x, int y)
{
    q[topQ][0] = x;
    q[topQ][1] = y;
    topQ++;
}
void solve(int id)
{
    topQ = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if ((int)(s[i][j] - '1') == id)
            {
                addQ(i, j);
                dist[id][i][j] = 0;
            }
            else
                dist[id][i][j] = INF;
        }
    for (int k = 0; k < topQ; k++)
    {
        int x = q[k][0], y = q[k][1];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + DX[i], ny = y + DY[i];
            if (!check(nx, ny)) continue;
            if (dist[id][nx][ny] <= dist[id][x][y] + 1) continue;
            dist[id][nx][ny] = dist[id][x][y] + 1;
            addQ(nx, ny);
        }
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i < 3; i++)
        solve(i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
    int AB = INF, AC = INF, BA = INF, BC = INF, CA = INF, CB = INF;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            if (s[x][y] == '1')
            {
                BA = min(BA, dist[1][x][y]);
                CA = min(CA, dist[2][x][y]);
            }
            if (s[x][y] == '2')
            {
                AB = min(AB, dist[0][x][y]);
                CB = min(CB, dist[2][x][y]);
            }
            if (s[x][y] == '3')
            {
                AC = min(AC, dist[0][x][y]);
                BC = min(BC, dist[1][x][y]);
            }
        }
    ans = min(ans, BA + CA - 2);
    ans = min(ans, AB + CB - 2);
    ans = min(ans, AC + BC - 2);
    printf("%d\n", (ans >= INF / 2 ? -1 : ans));

    return 0;
}