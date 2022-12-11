#include <bits/stdc++.h>
using namespace std;

int s[200005], g[200005];
int weight[200005];

int main()
{
    int n;
    scanf("%d",&n);

    priority_queue<pair<int, int>> pq;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&s[i],&g[i]);
        weight[i] = s[i] + g[i];
        pq.emplace(-weight[i], i);
    }

    while (pq.empty() == false)
    {
        int a = -pq.top().first;
        int b = pq.top().second;

        pq.pop();
        if (weight[b] < a) continue;

        if (b && weight[b - 1] > a + 1)
        {
            weight[b - 1] = a + 1;
            pq.emplace(-weight[b - 1], b - 1);
        }

        if (b < n - 1 && weight[b + 1] > a + 1)
        {
            weight[b + 1] = a + 1;
            pq.emplace(-weight[b + 1], b + 1);
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (weight[i] < s[i])
        {
            printf("-1\n");
            return 0;
        }

        ans += weight[i] - s[i];
    }

    printf("%lld\n", ans);

    for (int i = 0; i < n; i++) printf("%d ", weight[i]);
    printf("\n");
}