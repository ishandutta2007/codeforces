#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, d[100001], fa[100001], cnt[100001];
long long s, sum;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i - 1;
        d[i] = 1;
    }
    sum = 1LL * n * (n + 1) / 2;
}
bool check(int x)
{
    init();
    if (sum < s)
    {
        return 0;
    }
    int l = 2, r = n;
    long long tmp = sum - s;
    while (tmp)
    {
        while (d[l] == d[l - 1] * x)
        {
            l++;
        }
        while (!d[r])
        {
            r--;
        }
        if (l >= r)
        {
            return 0;
        }
        if (tmp < r - l)
        {
            l = r - tmp;
        }
        d[l]++;
        d[r]--;
        if (!(tmp -= r - l))
        {
            return 1;
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    scanf("%d%lld", &n, &s);
    int l = 1, r = n, best = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (best == -1)
    {
        printf("No");
        return 0;
    }
    else
    {
        check(best);
        printf("Yes\n");
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = cnt[i - 1] + d[i];
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < d[i]; j++)
            {
                printf("%d ", cnt[i - 2] + j / best + 1);
            }
        }
    }
    return 0;
}//