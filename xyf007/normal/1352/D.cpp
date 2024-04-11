#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[100001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        int cnt = 0, cnt1 = 0, cnt2 = 0, last = 0, l = 1, r = n, sum1 = 0, sum2 = 0;
        while (l <= r)
        {
            while (cnt1 <= last && l <= r)
            {
                cnt1 += a[l++];
            }
            cnt++;
            sum1 += cnt1;
            if (l > r)
            {
                printf("%d %d %d\n", cnt, sum1, sum2);
                break;
            }
            last = cnt1;
            cnt1 = 0;
            while (cnt2 <= last && l <= r)
            {
                cnt2 += a[r--];
            }
            cnt++;
            sum2 += cnt2;
            if (l > r)
            {
                printf("%d %d %d\n", cnt, sum1, sum2);
                break;
            }
            last = cnt2;
            cnt2 = 0;
        }
    }
    return 0;
}