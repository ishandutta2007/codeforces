#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const long long MOD = 998244353;
int n, m, a[200001], b[200001], last[200001];
map<int, int> mp;
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
        mp[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(a[i]))
        {
            last[mp[a[i]]] = i;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (!last[i])
        {
            printf("0");
            return 0;
        }
    }
    for (int i = 1; i <= last[1]; i++)
    {
        if (a[i] < b[1])
        {
            printf("0");
            return 0;
        }
    }
    for (int i = last[m] + 1; i <= n; i++)
    {
        if (a[i] < b[m])
        {
            printf("0");
            return 0;
        }
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = last[i - 1] + 1; j <= last[i]; j++)
        {
            if (a[j] < b[i - 1])
            {
                printf("0");
                return 0;
            }
        }
    }
    long long ans = 1;
    for (int i = m; i >= 2; i--)
    {
        int pos = last[i];
        for (int j = last[i]; j >= last[i - 1]; j--)
        {
            if (a[j] < b[i])
            {
                pos = j;
                break;
            }
        }
        ans = ans * (last[i] - pos) % MOD;
    }
    printf("%lld", ans);
    return 0;
}