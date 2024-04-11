#include <bits/stdc++.h>
using namespace std;

int a[200005];
int presum[200005];

void proc()
{
        int n, k;
        scanf("%d%d",&n,&k);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        presum[1] = 0;
        for (int i = 2; i < n; i++)
        {
                presum[i] = presum[i - 1];
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) presum[i]++;
        }

        int t = 0, l = 1;
        for (int i = 1; i <= n - k + 1; i++)
        {
                if (presum[i + k - 2] - presum[i] > t)
                {
                        t = presum[i + k - 2] - presum[i];
                        l = i;
                }
        }
        printf("%d %d\n", t + 1, l);
}

int main()
{
        int t;
        scanf("%d",&t);
        while (t--) proc();
}