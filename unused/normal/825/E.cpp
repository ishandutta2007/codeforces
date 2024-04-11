#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int degre[100005];
int ans[100005];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);

    priority_queue<int> pq;

    int odr = n;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[b].push_back(a);
        ++degre[a];
    }

    for (int i = 1; i <= n; i++) if (degre[i] == 0) pq.push(i);

    while (pq.empty() == false)
    {
        int x = pq.top(); pq.pop();
        ans[x] = odr--;
        for (int nxt : graph[x])
        {
            if (--degre[nxt] == 0) pq.push(nxt);
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}