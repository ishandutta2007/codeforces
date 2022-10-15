#include <bits/stdc++.h>
 
#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define check(x, y) ((x > 0) && (x <= n) && (y > 0) && (y <= n))
 
const int MaxN = 1e3 + 10;
const char op[] = {'U', 'L', 'D', 'R', 'X'};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
 
int n, vis[MaxN][MaxN];
char ans[MaxN][MaxN];
std::vector<std::pair<int, int>> v;
std::pair<int, int> a[MaxN][MaxN];
 
int nxt(int x, int y, int ex, int ey)
{
    for (int i = 0; i <= 3; i++)
        if (x + dx[i] == ex && y + dy[i] == ey)
            return i;
    return -1;
}
 
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}
 
void dfs(int x, int y, int Dx) // 
{
    if (ans[x][y]) return;
    ans[x][y] = op[Dx];
    for (int i = 0; i <= 3; i++)
    {
        int ex = x + dx[i], ey = y + dy[i];
        if (check(ex, ey) && a[ex][ey] == a[x][y])
            dfs(ex, ey, i);
    }
}
 
void get(int x, int y) // 
{
    vis[x][y] = 1, v.push_back(std::make_pair(x, y));
    for (int i = 0; i <= 3; i++)
    {
        int ex = x + dx[i], ey = y + dy[i];
        if (check(ex, ey) && a[ex][ey].first == -1 && a[ex][ey].second == -1 && !vis[ex][ey])
            get(ex, ey);
    }
}
 
void Dfs(int x, int y, int banx, int bany, int Dx) // 
{
    if (ans[x][y]) return;
    ans[x][y] = op[Dx];
    for (int i = 0; i <= 3; i++)
    {
        int ex = x + dx[i], ey = y + dy[i];
        if (check(ex, ey) && (a[ex][ey].first == -1 && a[ex][ey].second == -1) && (ex != banx || ey != bany))
            Dfs(ex, ey, banx, bany, i);
    }
}
 
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            a[i][j].first = read(), a[i][j].second = read();
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j].first == i && a[i][j].second == j)
                dfs(i, j, 4);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j].first == -1 && a[i][j].second == -1 && !vis[i][j])
            {
                v.clear(), get(i, j);
                if (v.size() == 1) return 0 * printf("INVALID");
                for (int k = 1; k < v.size(); k++)
                {
                    int x = nxt(v[k - 1].first, v[k - 1].second, v[k].first, v[k].second);
                    if (~x)
                    {
                        Dfs(v[k].first, v[k].second, v[k - 1].first, v[k - 1].second, x);
                        x = nxt(v[k].first, v[k].second, v[k - 1].first, v[k - 1].second);
                        Dfs(v[k - 1].first, v[k - 1].second, v[k].first, v[k].second, x);
                        break;
                    }
                    puts("fuck");
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!ans[i][j])
                return 0 * printf("INVALID");
    puts("VALID");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            putchar(ans[i][j]);
        puts("");
    }
    return 0; 
}