#include <bits/stdc++.h>
using namespace std;

char mp[55][55];
pair<int, int> dr[4] =
{
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

int main()
{
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mp[i];

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (mp[i][j] == 'S') sx = i, sy = j;
        else if (mp[i][j] == 'E') ex = i, ey = j;

    string cmd;
    cin >> cmd;

    sort(dr, dr + 4);

    int ans = 0;

    do
    {
        int x = sx, y = sy;

        for (int t : cmd)
        {
            x += dr[t - '0'].first;
            y += dr[t - '0'].second;

            if (x < 0 || y < 0 || x >= n || y >= m || mp[x][y] == '#') break;
            if (x == ex && y == ey) break;
        }

        if (x == ex && y == ey) ++ans;
    } while (next_permutation(dr, dr + 4));

    cout << ans;
}