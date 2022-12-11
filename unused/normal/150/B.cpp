#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int parent[2002];
int gs[2002];

int getparent(int t)
{
    return parent[t] == t ? t : parent[t] = getparent(parent[t]);
}

void merge(int a, int b)
{
    parent[getparent(a)] = getparent(b);
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;

    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < k; j++)
        {
            merge(i + j, i + k - 1 - j);
        }
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (getparent(i) != i) continue;
        ans = ans * 1ll * m % MOD;
    }

    printf("%d\n", ans);
}