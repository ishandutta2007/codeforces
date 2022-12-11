#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

char dat[1005][1005];

struct uf
{
    vector<int> parent;
    uf()
    {
        for (int i = 0; i <= 1005; i++) parent.push_back(i);
    }
    int getparent(int t)
    {
        return parent[t] == t ? t : parent[t] = getparent(parent[t]);
    }
    void merge(int a, int b, bool L)
    {
        a = getparent(a); b = getparent(b);
        if (L) parent[max(a, b)] = min(a, b);
        else parent[min(a, b)] = max(a, b);
    }
};

uf rowL[1005], rowR[1005];
uf colL[1005], colR[1005];

void makevisit(int a, int b)
{
    rowL[a].merge(b, b - 1, true);
    rowR[a].merge(b, b + 1, false);
    colL[b].merge(a, a - 1, true);
    colR[b].merge(a, a + 1, false);
}

int main()
{
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", dat[i] + 1);
    }

    int x1, y1, x2, y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    queue<tuple<int, int, int>> que;
    makevisit(x1, y1);
    que.emplace(x1, y1, 0);

    while (que.empty() == false)
    {
        int x, y, w;
        tie(x, y, w) = que.front();
        que.pop();

        if (x == x2 && y == y2)
        {
            printf("%d\n", w);
            return 0;
        }

        for (int ny = rowL[x].getparent(y); y - ny <= k && dat[x][ny] == '.'; ny = rowL[x].getparent(ny))
        {
            makevisit(x, ny);
            que.emplace(x, ny, w + 1);
        }
        for (int ny = rowR[x].getparent(y); ny - y <= k && dat[x][ny] == '.'; ny = rowR[x].getparent(ny))
        {
            makevisit(x, ny);
            que.emplace(x, ny, w + 1);
        } 
        for (int nx = colL[y].getparent(x); x - nx <= k && dat[nx][y] == '.'; nx = colL[y].getparent(nx))
        {
            makevisit(nx, y);
            que.emplace(nx, y, w + 1);
        }
        for (int nx = colR[y].getparent(x); nx - x <= k && dat[nx][y] == '.'; nx = colR[y].getparent(nx))
        {
            makevisit(nx, y);
            que.emplace(nx, y, w + 1);
        }
    }

    printf("-1\n");
}