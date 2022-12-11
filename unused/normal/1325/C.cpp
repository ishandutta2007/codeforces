#include <bits/stdc++.h>
using namespace std;

pair<int, int> edge[100005];
int degree[100005];
int ans[100005];

int main()
{
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n - 1; i++)
        {
                scanf("%d%d", &edge[i].first, &edge[i].second);
                degree[edge[i].first]++;
                degree[edge[i].second]++;
        }

        int x = 1;
        for (int i = 1; i <= n; i++)
        {
                if (degree[i] >= 3)
                {
                        for (int j = 0; j < n - 1; j++)
                        {
                                if (edge[j].first == i || edge[j].second == i)
                                {
                                        ans[j] = x++;
                                }
                        }
                        break;
                }
        }
        for (int i = 0; i < n - 1; i++)
        {
                if (ans[i] == 0) printf("%d\n", x++ - 1);
                else printf("%d\n", ans[i] - 1);
        }
}