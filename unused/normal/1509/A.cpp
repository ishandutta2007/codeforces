#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int x;
        scanf("%d",&x);
        int d[x];
        for (int i = 0; i < x; i++) scanf("%d",&d[i]);
        sort(d, d + x, [](int a, int b) { return a%2 < b%2; });
        for (int i = 0; i < x; i++) printf("%d ",d[i]);
        printf("\n");
    }
}