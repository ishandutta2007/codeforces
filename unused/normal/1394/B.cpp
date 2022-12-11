#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[200005];
int ans, k;
bitset<200005> z[90];
vector<int> wronglist[90];
int wrong[90];

int idx(int a, int b)
{
        // a : size - 1, 0 <= b <= a
        return a * k + b;
}

void recur(int x)
{
        if (x == k)
        {
                ++ans;
                return;
        }

        for (int i = 0; i <= x; i++)
        {
                if (wrong[idx(x, i)]) continue;

                for (int j : wronglist[idx(x, i)]) wrong[j]++;
                recur(x + 1);
                for (int j : wronglist[idx(x, i)]) wrong[j]--;
        }
}

int main()
{
        int n, m;
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0; i < m; i++)
        {
                int u, v, w;
                scanf("%d%d%d",&u,&v,&w);
                graph[u].emplace_back(w, v);
        }

        for (int i = 1; i <= n; i++)
        {
                sort(graph[i].begin(), graph[i].end());
                for (int j = 0; j < graph[i].size(); j++)
                {
                        if (z[idx(graph[i].size() - 1, j)][graph[i][j].second]) wrong[idx(graph[i].size() - 1, j)] = 1;
                        else z[idx(graph[i].size() - 1, j)][graph[i][j].second] = true;
                }
        }

        for (int i = 0; i < k; i++)
        {
                for (int j = 0; j <= i; j++)
                {
                        int X = idx(i, j);
                        if (wrong[X]) continue;
                        for (int x = 0; x < k; x++)
                        {
                                for (int y = 0; y <= x; y++)
                                {
                                        int Y = idx(x, y);
                                        if (X == Y) continue;
                                        if (wrong[Y]) continue;
                                        if ((z[X] & z[Y]).any())
                                        {
                                                wronglist[X].push_back(Y);
                                        }
                                }
                        }
                }
        }

        recur(0);
        printf("%d\n", ans);
}