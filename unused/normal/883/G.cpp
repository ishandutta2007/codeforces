#include <bits/stdc++.h>
using namespace std;

int t[300005], u[300005], v[300005];
vector<int> graph[300005];
vector<int> graph2[300005];
bool visit[300005];
char ans1[300005], ans2[300005];

int cnt;

void dfs(int t)
{
    visit[t] = true;
    ++cnt;
    for (int nxt : graph[t])
    {
        if (visit[nxt] == false) dfs(nxt);
    }

    for (int nxt : graph2[t])
    {
        if (t == u[nxt])
        {
            if (visit[v[nxt]]) continue;
            ans1[nxt] = '+';
            dfs(v[nxt]);
        }
        else
        {
            if (visit[u[nxt]]) continue;
            ans1[nxt] = '-';
            dfs(u[nxt]);
        }
    }
}

set<int> vts;

void dfs2(int t)
{
    for (int nxt : graph[t])
    {
        if (vts.insert(nxt).second) dfs2(nxt);
    }
}


int main()
{
    int n, m, s;
    scanf("%d%d%d",&n,&m,&s);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&t[i],&u[i],&v[i]);

        if (t[i] == 1)
        {
            graph[u[i]].push_back(v[i]);
            --i; --m;
        }
        else
        {
            graph2[u[i]].push_back(i);
            graph2[v[i]].push_back(i);
            ans1[i] = '+';
            ans2[i] = '+';
        }
    }

    dfs(s);
    printf("%d\n%s\n", cnt, ans1);

    vts.insert(s);
    dfs2(s);
    for (int i = 0; i < m; i++)
    {
        if (vts.count(u[i]) && vts.count(v[i]) == 0) ans2[i] = '-';
        else ans2[i] = '+';
    }
    printf("%zd\n%s\n", vts.size(), ans2);
}