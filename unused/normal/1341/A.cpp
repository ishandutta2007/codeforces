#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d",&T); while (T--)
    {
        int n, a, b, c, d;
        scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
        if ((a-b)*n > c+d || (a+b)*n < c-d) printf("No\n");
        else printf("Yes\n");
    }
}