#include <bits/stdc++.h>
using namespace std;

int n;
int price[200005];
long long psum[200005];
int dist[3][200005];
vector<int> graph[200005];

void bfs(int start, int *d)
{
        queue<int> que;
        fill(d, d + n, 0);
        d[start] = 1;
        que.push(start);

        while (!que.empty())
        {
                int x = que.front(); que.pop();
                for (int nxt : graph[x])
                {
                        if (d[nxt]) continue;
                        d[nxt] = d[x] + 1;
                        que.push(nxt);
                }
        }
}

void proc()
{
        int m, a, b, c;
        scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
        --a; --b; --c;
        for (int i = 0; i < m; i++) scanf("%d", &price[i]);
        sort(price, price + m);
        psum[0] = 0;
        for (int i = 1; i <= m; i++) psum[i] = psum[i - 1] + price[i - 1];
        for (int i = 0; i < m; i++)
        {
                int x, y;
                scanf("%d%d",&x,&y);
                --x; --y;
                graph[x].push_back(y);
                graph[y].push_back(x);
        }

        bfs(a, dist[0]);
        bfs(b, dist[1]);
        bfs(c, dist[2]);

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
                int x = dist[1][i] - 1;
                int y = dist[0][i] + dist[2][i] - 2;
                if (x + y > m) continue;
                ans = min(ans, psum[x + y] + psum[x]);
        }
        printf("%lld\n", ans);
}

int main()
{
        int T;
        scanf("%d", &T);
        while (T--)
        {
                proc();
                for (int i = 0; i < n; i++) graph[i].clear();
        }
}