#include <cstdio>
#include <queue>
using namespace std;

int degree[100005];
int weight[100005];
long long sub[100005];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) degree[i] = 0;
        for (int i = 1; i <= n; i++) sub[i] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &weight[i]);

        long long ans = 0;
        for (int i = 1; i <= n; i++) ans += weight[i];

        for (int i = 1; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            degree[a]++;
            degree[b]++;
        }

        priority_queue<int> pq;
        pq.push(0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < degree[i]; j++)
            {
                pq.push(weight[i]);
            }
        }

        for (int i = 1; i < n; i++)
        {
            printf("%lld ", ans);
            ans += pq.top();
            pq.pop();
        }

        printf("\n");
    }
}