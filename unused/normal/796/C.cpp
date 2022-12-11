#include <bits/stdc++.h>
using namespace std;

int dat[300005];
vector<int> graph[300005];
bool ismax[300005];

int dfs(int t, int p, int inc)
{
    int ret = dat[t] + inc;
    for (int nxt : graph[t])
    {
        if (nxt == p) continue;
        ret = max(ret, dfs(nxt, t, min(2, inc + 1)));
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d",&n);

    int maxval = INT_MIN;
    vector<int> maxs;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &dat[i]);
        if (dat[i] > maxval) maxs.clear(), maxval = dat[i];
        if (dat[i] == maxval) maxs.push_back(i);
    }

    for (int t : maxs) ismax[t] = true;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (maxs.size() == 1)
    {
        printf("%d\n", dfs(maxs[0], -1, 0));
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int t : graph[i])
            {
                if (ismax[t]) ++cnt;
            }

            if (ismax[i]) ++cnt;

            if (cnt == maxs.size())
            {
                printf("%d\n", maxval + 1);
                return 0;
            }
        }

        printf("%d\n", maxval + 2);
        return 0;
    }
}