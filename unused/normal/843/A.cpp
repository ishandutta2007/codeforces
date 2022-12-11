#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100005];
int parent[100005];
vector<int> vt[100005];

int f(int t)
{
    return parent[t] == t ? t : parent[t] = f(parent[t]);
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i].first);
        a[i].second = i;
        parent[i] = i;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        parent[f(i)] = f(a[i].second);
    }

    for (int i = 1; i <= n; i++) vt[f(i)].push_back(i);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += !vt[i].empty();

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
    {
        if (vt[i].empty()) continue;
        printf("%zd ", vt[i].size());
        for (int t : vt[i]) printf("%d ", t);
        printf("\n");
    }
}