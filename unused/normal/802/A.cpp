#include <bits/stdc++.h>
using namespace std;

vector<int> x[400005];
bool yes[400005];
int f[400005];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
        x[f[i]].push_back(i);
    }

    for (int i = 1; i <= 400000; i++) x[i].push_back(INT_MAX);

    set<pair<int, int>> pq;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (yes[f[i]])
        {
            pq.erase({i, f[i]});
            pq.emplace(*upper_bound(x[f[i]].begin(), x[f[i]].end(), i), f[i]);
            continue;
        }

        ++ans;

        if (pq.size() == k)
        {
            yes[pq.rbegin()->second] = false;
            pq.erase(prev(pq.end()));
        }

        pq.emplace(*upper_bound(x[f[i]].begin(), x[f[i]].end(), i), f[i]);
        yes[f[i]] = true;
    }

    printf("%d\n", ans);
}