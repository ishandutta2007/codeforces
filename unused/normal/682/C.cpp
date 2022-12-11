#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100005];
int ccnt[100005];
int dat[100005];
int ans;

void dfs1(int t)
{
    ccnt[t] = 1;
    for (auto &e : graph[t])
    {
        dfs1(e.first);
        ccnt[t] += ccnt[e.first];
    }
}

void dfs2(int t, long long now)
{
    now = max(now, 0LL);
    if (now > dat[t])
    {
        ans += ccnt[t];
        return;
    }

    for (auto &e : graph[t])
    {
        dfs2(e.first, now + e.second);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a-1].emplace_back(i, b);
    }

    dfs1(0);
    dfs2(0, 0);

    printf("%d\n", ans);
}