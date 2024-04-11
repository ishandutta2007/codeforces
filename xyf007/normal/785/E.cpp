#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n, q, B, a[200001], t[501][200001];
void add(int id, int x, int val)
{
    while (x <= n)
    {
        t[id][x] += val;
        x += x & -x;
    }
}
int sum(int id, int x)
{
    int s = 0;
    while (x)
    {
        s += t[id][x];
        x -= x & -x;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    B = sqrt(n);
    for (int i = 0; i < n; i++)
    {
        add(i / B, a[i], 1);
    }
    long long ans = 0;
    while (q--)
    {
        int l, r, B1, B2, cnt1 = 0, cnt2 = 0;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        if (l == r)
        {
            printf("%lld\n", ans);
            continue;
        }
        if (l > r)
        {
            swap(l, r);
        }
        B1 = l / B;
        B2 = r / B;
        if (B1 == B2)
        {
            for (int i = l + 1; i < r; i++)
            {
                if (a[i] < a[r])
                {
                    cnt1++;
                }
                if (a[i] < a[l])
                {
                    cnt2++;
                }
            }
        }
        else
        {
            for (int i = l + 1; i < (B1 + 1) * B; i++)
            {
                if (a[i] < a[r])
                {
                    cnt1++;
                }
                if (a[i] < a[l])
                {
                    cnt2++;
                }
            }
            for (int i = B2 * B; i < r; i++)
            {
                if (a[i] < a[r])
                {
                    cnt1++;
                }
                if (a[i] < a[l])
                {
                    cnt2++;
                }
            }
            for (int i = B1 + 1; i < B2; i++)
            {
                cnt1 += sum(i, a[r] - 1);
                cnt2 += sum(i, a[l] - 1);
            }
        }
        ans += 2 * cnt1 - 2 * cnt2;
        if (a[l] < a[r])
        {
            ans++;
        }
        else
        {
            ans--;
        }
        add(B1, a[l], -1);
        add(B2, a[r], -1);
        add(B2, a[l], 1);
        add(B1, a[r], 1);
        swap(a[l], a[r]);
        printf("%lld\n", ans);
    }
    return 0;
}