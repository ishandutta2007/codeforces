#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; scanf("%d",&t); while (t--)
    {
        int n; scanf("%d",&n);
        int l = 0, r = 0;
        for (int i = 1; i <= n / 2 - 1; i++) l += 1 << i;
        for (int i = n / 2; i < n; i++) r += 1 << i;
        l += 1 << n;
        printf("%d\n", l - r);
    }
}