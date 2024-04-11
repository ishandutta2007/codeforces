#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int INF = (int)1e8;
int n;
const int N = (int)1e6 + 100;
char s[N];
char t[N];
int q;
int d, k;

int p[1000100][22];

inline int up(int pos, int tms)
{
    int ans = 0;
    bool flag = 0;
    for (int idx = 21; idx >= 0; idx--)
    {
        if ((1 << idx) > tms) continue;
        if (p[pos][idx] != -1)
        {
            pos = p[pos][idx];
            tms -= (1 << idx);
            ans += (1 << idx);
        }
        else
        {
            flag = 1;
            tms = (1 << idx) - 1;
        }
    }
    if (flag)
    {
        ans++;
        pos = -1;
    }
    return ans + pos;
}

inline int findPos(int idx)
{
    int pos;
    if (idx < k)
        pos = up(idx, n - k + 1);
    else
        pos = (idx - k + 1) + up(k - 1, n - idx);
    return pos;
}

inline void solve()
{
    int idx = -1;
    for (int i = 0; i < d; i++)
        for (int j = i; j < k; j += d)
            p[j][0] = idx++;
    for (int it = 0; it < 21; it++)
        for (int i = 0; i < k; i++)
        {
            if (p[i][it] == -1)
                p[i][it + 1] = -1;
            else
                p[i][it + 1] = p[ p[i][it] ][it];
        }
    for (int i = 0; i < n; i++)
        t[findPos(i)] = s[i];
    for (int i = 0; i < n; i++)
        s[i] = t[i];
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf(" %s ", &s);
    n = strlen(s);
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &k, &d);
        solve();
        printf("%s\n", s);
    }

    return 0;
}