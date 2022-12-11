#include <bits/stdc++.h>
using namespace std;

const int N = 401;
bool edge[N][N];
int dist[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a][b] = edge[b][a] = true;
    }
    dist[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u = 1; u <= n; u++)
            if(edge[v][u] != edge[1][n] && dist[u] == 0)
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
    printf("%d\n", dist[n] - 1);
}