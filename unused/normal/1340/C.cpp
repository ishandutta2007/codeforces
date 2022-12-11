#include <bits/stdc++.h>
using namespace std;

int pos[10000];
int visit[10000][1001];

int main()
{
        int n, m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < m; i++) scanf("%d", &pos[i]);
        sort(pos, pos + m);
        m = unique(pos, pos + m) - pos;
        int g, r;
        scanf("%d%d",&g,&r);

        memset(visit, 0x7F, sizeof(visit));

        deque<tuple<int, int, int>> dq;
        visit[0][0] = 1;
        dq.emplace_back(0, 0, 1);

        while (!dq.empty())
        {
                auto [v, t, w] = dq.front(); dq.pop_front();
                if (visit[v][t] != w) continue;

                if (t == g)
                {
                        if (visit[v][0] <= visit[v][g] + 1) continue;
                        visit[v][0] = visit[v][g] + 1;
                        dq.emplace_back(v, 0, visit[v][g] + 1);
                        continue;
                }

                if (v > 0)
                {
                        int nt = t + pos[v] - pos[v - 1];
                        if (nt <= g && visit[v - 1][nt] > visit[v][t])
                        {
                                visit[v - 1][nt] = visit[v][t];
                                dq.emplace_front(v - 1, nt, visit[v][t]);
                        }
                }
                if (v < m - 1)
                {
                        int nt = t + pos[v + 1] - pos[v];
                        if (nt <= g && visit[v + 1][nt] > visit[v][t])
                        {
                                visit[v + 1][nt] = visit[v][t];
                                dq.emplace_front(v + 1, nt, visit[v][t]);
                        }
                }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= g; i++)
        {
                if (visit[m - 1][i] < 0x7F7F7F7F)
                {
                        ans = min(ans, (visit[m - 1][i] - 1) * (g + r) + i);
                }
        }

        if (ans == INT_MAX) ans = -1;
        printf("%d\n", ans);
}