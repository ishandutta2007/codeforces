#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
int parent[200005];
int dp1[200005], dp2[200005];
int ans;

void dfs(int t)
{
  for (int i = 0; i < graph[t].size(); i++)
  {
    if (graph[t][i] == parent[t])
    {
      swap(graph[t][i], graph[t].back());
      graph[t].pop_back();
      i--;
      continue;
    }
    parent[graph[t][i]] = t;
    dfs(graph[t][i]);
  }
}

int DP1(int), DP2(int);

int DP1(int t)
{
  if (dp1[t] == 0)
  {
    if (graph[t].empty()) dp1[t]=1;
    else if (graph[t].size()==1) dp1[t] = min(DP2(graph[t][0])+1, DP1(graph[t][0]));
    else
    {
      int sum = 0;
      for (int next : graph[t]) sum += DP2(next);

      dp1[t] = sum + 1;

      for (int next : graph[t])
      {
        dp1[t] = min(dp1[t], sum - DP2(next) + DP1(next));
      }
    }
  }
  return dp1[t];
}

int DP2(int t)
{
  if (dp2[t]==0)
  {
    dp2[t] = DP1(t);
    if (graph[t].size()>=2)
    {
      int sum = -1;
      priority_queue<int> pq;
      for (int next : graph[t])
      {
        pq.push(DP1(next) - DP2(next));
        sum += DP2(next);
        while (pq.size() > 2) pq.pop();
      }

      while (pq.empty()==false) sum += pq.top(), pq.pop();
      dp2[t] = min(dp2[t], sum);
    }
  }

  return dp2[t];
}

int main()
{
  int n,x,y;
  scanf("%d%d%d",&n,&x,&y);
  for (int i = 0; i < n - 1; i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  if (x>=y)
  {
    for (int i = 1; i <= n; i++)
    {
      if (graph[i].size() == n - 1)
      {
        printf("%lld", (long long)(n-2)*y+x);
        return 0;
      }
    }
    printf("%lld", (long long)(n-1)*y);
    return 0;
  }

  dfs(1);

  printf("%lld", (long long)(n-1)*y - (long long)(y-x) * (n-DP2(1)));
}