#include <bits/stdc++.h>
using namespace std;

char d[100005];
int ans[200005];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n, p, k;
        scanf("%d%d%d",&n,&p,&k);
        scanf("%s", d);
        int x, y;
        scanf("%d%d",&x,&y);
        for (int i = 0; i < n; i++) ans[i] = 2e9;
        for (int i = n; i < n + k; i++) ans[i] = 0;

        int r = 2e9;
        for (int i = n - 1; i >= p - 1; i--)
        {
            ans[i] = ans[i + k];
            if (d[i] == '0') ans[i] += x;
            r = min(r, (i - (p - 1)) * y + ans[i]);
        }

        printf("%d\n", r);
    }
}