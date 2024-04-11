#include <bits/stdc++.h>
using namespace std;

const int N = 401;
typedef long double ld;

int dist[N][N];
vector<int> g[N];
vector<int> lay[N];
ld tmppos[N];
ld pos[N];
int n;

void bfs(int start)
{
    for(int i = 1; i <= n; i++)
        dist[start][i] = N;
    dist[start][start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u: g[v])
            if(dist[start][u] == N)
            {
                dist[start][u] = dist[start][v] + 1;
                q.push(u);
            }
    }
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        bfs(i);
    ld ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ld pr = 0;
        for(int j = 0; j <= n; j++)
            lay[j].clear();
        for(int j = 1; j <= n; j++)
            lay[dist[i][j]].push_back(j);
        for(int j = 0; j <= n; j++)
        {
            int k = lay[j].size();
            if(k == 0) continue;
            if(k == 1)
            {
                pr += 1.0;
                continue;
            }
            vector<int> vec;
            for(int v: lay[j])
                for(int u: g[v])
                {
                    if(pos[u] == 0)
                        vec.push_back(u);
                    pos[u] += 1.0 / g[v].size();
                }
            ld best = 1.0;
            for(int v = 1; v <= n; v++)
            {
                for(int u: vec)
                {
                    int d = dist[v][u];
                    tmppos[d] = max(tmppos[d], pos[u]);
                }
                ld sum = 0;
                for(int u: vec)
                {
                    int d = dist[v][u];
                    sum += tmppos[d];
                    tmppos[d] = 0;
                }
                best = max(best, sum);
            }
            for(int v: vec)
                pos[v] = 0;
            pr += best;
        }
        ans = max(ans, pr);
    }
    printf("%.10lf\n", (double)(ans / n));
}