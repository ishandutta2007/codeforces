#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
array<long long, 5> dp1[200005];
array<long long, 5> dp2[200005];
int n, k;
long long ans;

void dfs(int t, int p)
{
    array<long long, 5> cnts{};
    array<long long, 5> sums{};

    for (int nxt: graph[t])
    {
        if (nxt == p) continue;
        dfs(nxt, t);

        auto &cnt = dp1[nxt];
        auto &sum = dp2[nxt];

        for (int i = 0; i < k; i++)
        {
            ans += (sum[i] + cnt[i] * ((k - i) % k)) / k;
            for (int j = 0; j < k; j++)
            {
                int rem = (k - (i + j) % k) % k;
                long long totalpair = cnt[i] * cnts[j];
                ans += (sums[j] * cnt[i] + sum[i] * cnts[j] + totalpair * rem) / k;
            }
        }

        for (int i = 0; i < k; i++)
        {
            cnts[i] += cnt[i];
            sums[i] += sum[i];
        }
    }

    for (int i = 0; i < k; i++)
    {
        dp1[t][(i+1)%k] = cnts[i];
        dp2[t][(i+1)%k] = sums[i] + cnts[i];
    }

    dp1[t][1%k]++;
    dp2[t][1%k]++;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i < n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);
    printf("%lld\n", ans);
}