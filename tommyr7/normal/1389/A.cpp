#include <bits/stdc++.h>
using namespace std;
int T,lx,rx;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&lx,&rx);
        if (rx<2*lx) printf("%d %d\n",-1,-1); else printf("%d %d\n",lx,2*lx);
    }
    return 0;
}