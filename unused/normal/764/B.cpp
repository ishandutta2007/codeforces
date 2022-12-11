#include <bits/stdc++.h>
using namespace std;

int dat[300005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    for (int i = 0; i < n; i++)
    {
        int z = min(i, n - 1 - i);
        if (z % 2 == 0) printf("%d ", dat[n - 1 - i]);
        else printf("%d ", dat[i]);
    }
    printf("\n");
}