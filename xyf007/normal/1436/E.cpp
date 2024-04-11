#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct node
{
    int ls, rs, minn;
} t[8000001];
int n, a[100001], root[100001], tot;
vector<int> pos[100002];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
void pushup(int x)
{
    t[x].minn = min(t[t[x].ls].minn, t[t[x].rs].minn);
}
int modify(int l, int r, int p, int val, int x)
{
    int xx = ++tot;
    t[xx] = t[x];
    if (l == r)
    {
        t[xx].minn = val;
        return xx;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
    {
        t[xx].ls = modify(l, mid, p, val, t[x].ls);
    }
    else
    {
        t[xx].rs = modify(mid + 1, r, p, val, t[x].rs);
    }
    pushup(xx);
    return xx;
}
int query(int L, int R, int l, int r, int x)
{
    if (L <= l && r <= R)
    {
        return t[x].minn;
    }
    int mid = (l + r) >> 1, ret = 1e9;
    if (L <= mid)
    {
        checkmin(ret, query(L, R, l, mid, t[x].ls));
    }
    if (R > mid)
    {
        checkmin(ret, query(L, R, mid + 1, r, t[x].rs));
    }
    return ret;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
    }
    if ((int)pos[1].size() == n)
    {
        printf("1");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        root[i] = modify(1, n, a[i], i, root[i - 1]);
    }
    for (int i = 2; i <= n + 1; i++)
    {
        pos[i].push_back(n + 1);
    }
    for (int i = 2; i <= n + 1; i++)
    {
        if (query(1, i - 1, 1, n, root[pos[i].at(0) - 1]) >= 1)
        {
            continue;
        }
        bool f = 0;
        for (int j = 0; j < (int)pos[i].size() - 1 && !f; j++)
        {
            int l = pos[i].at(j) + 1, r = pos[i].at(j + 1) - 1;
            if (l > r)
            {
                continue;
            }
            f = query(1, i - 1, 1, n, root[r]) >= l;
        }
        if (!f)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", n + 2);
    return 0;
}