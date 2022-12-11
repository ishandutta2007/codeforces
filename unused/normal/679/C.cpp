#include <bits/stdc++.h>
using namespace std;

char dat[505][505];
int presum[505][505];
int idx[505][505];
int parent[250005], r[250005], s[250005];
int cnt[250005];

int getparent(int t)
{
    return t == parent[t] ? t : parent[t] = getparent(parent[t]);
}
void merge(int a, int b)
{
    a = getparent(a); b = getparent(b);
    if (a == b) return;
    if (r[a] < r[b]) swap(a, b);
    else if (r[a] == r[b]) r[a]++;
    parent[b] = a; s[a] += s[b];
}

constexpr int dr[4][2]=
{
    1,0,
    -1,0,
    0,1,
    0,-1
};

int ans, component;
int x1, y1, x2, y2, n, k;

void add(int i, int j)
{
    if (idx[i][j])
    {
        int p = getparent(idx[i][j]);
        if (cnt[p]++ == 0) component += s[p];
    }
}

void sub(int i, int j)
{
    if (idx[i][j])
    {
        int p = getparent(idx[i][j]);
        if (--cnt[p] == 0) component -= s[p];
    }
}

void updateans()
{
    ans = max(ans, component + k * k - (presum[x2][y2] - presum[x1-1][y2] - presum[x2][y1-1] + presum[x1-1][y1-1]));
}

void movedown()
{
    for (int i = x1; i <= x2; i++) sub(i, y1 - 1);
    for (int i = x1; i <= x2; i++) add(i, y2 + 2);
    sub(x1 - 1, y1);
    sub(x2 + 1, y1);
    add(x1 - 1, y2 + 1);
    add(x2 + 1, y2 + 1);
    y1++; y2++;
}

void moveup()
{
    for (int i = x1; i <= x2; i++) sub(i, y2 + 1);
    for (int i = x1; i <= x2; i++) add(i, y1 - 2);
    sub(x1 - 1, y2);
    sub(x2 + 1, y2);
    add(x1 - 1, y1 - 1);
    add(x2 + 1, y1 - 1);
    y1--; y2--;
}

void moveright()
{
    for (int i = y1; i <= y2; i++) sub(x1 - 1, i);
    for (int i = y1; i <= y2; i++) add(x2 + 2, i);
    sub(x1, y1 - 1);
    sub(x1, y2 + 1);
    add(x2 + 1, y1 - 1);
    add(x2 + 1, y2 + 1);
    x1++; x2++;
}

int main()
{
    scanf("%d%d",&n,&k);
    int last = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",dat[i] + 1);
        for (int j = 1; j <= n; j++)
        {
            presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1];

            if (dat[i][j] == '.')
            {
                idx[i][j] = last;
                parent[last] = last;
                s[last] = 1;
                ++last;
                ++presum[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dat[i][j] != '.') continue;
            for (int d = 0; d < 4; d++)
            {
                int nx = i + dr[d][0];
                int ny = j + dr[d][1];
                if (dat[nx][ny] != '.') continue;

                merge(idx[i][j], idx[nx][ny]);
            }
        }
    }

    x1 = 1; y1 = 1; x2 = k; y2 = k;

    for (int i = 1; i <= k + 1; i++)
    {
        for (int j = 1; j <= k + 1; j++)
        {
            if (i == k + 1 && j == k + 1) continue;
            add(i, j);
        }
    }

    updateans();

    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 0; j < n - k; j++)
        {
            if (i & 1) movedown();
            else moveup();

            updateans();
        }
        if (i < n - k + 1)
        {
            moveright();
            updateans();
        }
    }

    printf("%d\n", ans);
}