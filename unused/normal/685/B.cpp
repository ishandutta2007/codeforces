#include <bits/stdc++.h>
using namespace std;

int parent[300005];
int ccnt[300005];
int cent[300005];
int visit[300005];
int fin[300005];
int maxchild[300005];
vector<int> graph[300005];

int vtime;

void dfs(int t)
{
    ccnt[t] = 1;
    visit[t] = ++vtime;
    maxchild[t] = -1;
    for (int nxt : graph[t])
    {
        dfs(nxt);
        ccnt[t] += ccnt[nxt];
        if (maxchild[t] == -1 ||
            ccnt[maxchild[t]] < ccnt[nxt]) maxchild[t] = nxt;
    }
    fin[t] = vtime;
}

void recur(int t, int now)
{
    for (bool flag = true; flag;)
    {
        flag = false;

        int nxt = maxchild[now];
        if (nxt != -1 && ccnt[nxt] > ccnt[t] / 2)
        {
            now = nxt;
            flag = true;
        }
    }

    cent[t] = now;

    for (int nxt : graph[t])
    {
        recur(nxt, visit[nxt] <= visit[now] && visit[now] <= fin[nxt] ? now : nxt);
    }
}

int main()
{
    int n, q;
    scanf("%d%d",&n,&q);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d",&parent[i]);
        graph[parent[i]].push_back(i);
    }

    dfs(1);
    recur(1, 1);

    while (q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n", cent[x]);
    }
}