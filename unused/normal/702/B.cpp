#include <stdio.h>
#include <algorithm>

using namespace std;

unsigned dat[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%u",&dat[i]);
    }
    sort(dat,dat+n);
    long long ans = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        unsigned j = 1;
        while (j <= dat[i]) j <<= 1;
        auto res = equal_range(dat, dat + i, j - dat[i]);
        ans += res.second - res.first;
    }
    printf("%lld", ans);
}