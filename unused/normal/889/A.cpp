#include <bits/stdc++.h>
using namespace std;

int dat[200005];
int now[200005];

int main()
{
    int n;
    scanf("%d",&n);
    now[0] = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&dat[i]);
        if (now[dat[i]] == 0)
        {
            now[i] = ++ans;
        }
        else
        {
            now[i] = now[dat[i]];
            now[dat[i]] = 0;
        }
    }

    printf("%d\n", ans);
}