#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
pair<long long, int> a[200001];
void checkmax(long long &x, long long y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i].first);
        a[i].first -= i;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    long long ans = 0, sum = a[1].first + a[1].second;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].first == a[i - 1].first)
        {
            sum += a[i].first + a[i].second;
        }
        else
        {
            checkmax(ans, sum);
            sum = a[i].first + a[i].second;
        }
    }
    checkmax(ans, sum);
    printf("%lld", ans);
    return 0;
}