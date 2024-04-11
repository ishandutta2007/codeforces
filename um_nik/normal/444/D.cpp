#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int SZ = 3000;
const int INF = (int)1e6;
int n, q;
char s[50100];
char s1[5], s2[5];
const int sz = 27 * 27 * 27 * 27;
vector<int> g[sz];
bool ex[sz];
int a[80];
int b[80][sz];
int sz2;
int tmp[50100];
int len, t1, t2;
int sz3;

int func(int x)
{
    int t = 27;
    for (int i = 0; i < 5; i++)
    {
        if (t > x)
            return i;
        t *= 27;
    }
}

int my_find(int x)
{
    int l = -1;
    int r = sz3;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (tmp[m] <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

void solve(int h1, int h2)
{
    int ans = INF;
    if (!ex[h1] || !ex[h2])
    {
        printf("-1\n");
        return;
    }
    int pos1, pos2;
    int idx = 0;
    sz3 = (int)g[h2].size();
    for (int i = 0; i < (int)g[h1].size(); i++)
    {
        pos1 = g[h1][i];
        while (idx < sz3 && g[h2][idx] < g[h1][i]) idx++;
        if (idx < sz3)
        {
            pos2 = g[h2][idx];
            int y = min(pos1, pos2);
            int z = max(pos1 + func(h1), pos2 + func(h2));
            ans = min(ans, z - y);
        }
        if (idx > 0)
        {
            pos2 = g[h2][idx - 1];
            int y = min(pos1, pos2);
            int z = max(pos1 + func(h1), pos2 + func(h2));
            ans = min(ans, z - y);
        }
    }
    printf("%d\n", ans + 1);
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf(" %s ", &s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < 4; j++)
        {
            if (i + j >= n)
                break;
            x = x * 27 + (int)(1 + s[i + j] - 'a');
            g[x].push_back(i);
        }
    }
    for (int i = 0; i < sz; i++)
        if ((int)g[i].size() > 0)
            ex[i] = 1;
    for (int i = 0; i < sz; i++)
    {
        if ((int)g[i].size() < SZ)
            continue;
        a[sz2] = i;
        sz3 = (int)g[i].size();
        for (int j = 0; j < sz3; j++)
            tmp[j] = g[i][j];
        for (int j = 0; j < sz; j++)
        {
            b[sz2][j] = INF;
            for (int k = 0; k < (int)g[j].size(); k++)
            {
                int x = my_find(g[j][k]);
                if (x > -1)
                {
                    int y = min(g[j][k], tmp[x]);
                    int z = max(g[j][k] + func(j), tmp[x] + func(i));
                    b[sz2][j] = min(b[sz2][j], z - y);
                }
                x++;
                if (x < sz3)
                {
                    int y = min(g[j][k], tmp[x]);
                    int z = max(g[j][k] + func(j), tmp[x] + func(i));
                    b[sz2][j] = min(b[sz2][j], z - y);
                }
            }
        }
        sz2++;
    }

    scanf("%d", &q);
    while (q--)
    {
        scanf(" %s %s ", &s1, &s2);
        len = strlen(s1);
        t1 = 0;
        for (int i = 0; i < len; i++)
            t1 = t1 * 27 + (int)(1 + s1[i] - 'a');
        len = strlen(s2);
        t2 = 0;
        for (int i = 0; i < len; i++)
            t2 = t2 * 27 + (int)(1 + s2[i] - 'a');
        bool good = 0;
        for (int k = 0; k < sz2; k++)
        {
            if (t1 == a[k])
            {
                if (b[k][t2] == INF)
                    printf("-1\n");
                else
                    printf("%d\n", b[k][t2] + 1);
                good = 1;
                break;
            }
        }
        if (good)
            continue;
        for (int k = 0; k < sz2; k++)
        {
            if (t2 == a[k])
            {
                if (b[k][t1] == INF)
                    printf("-1\n");
                else
                    printf("%d\n", b[k][t1] + 1);
                good = 1;
                break;
            }
        }
        if (good)
            continue;
        solve(t1, t2);
    }

    return 0;
}