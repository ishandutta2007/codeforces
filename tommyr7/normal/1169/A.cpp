#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,d;
int main()
{
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    while (a!=b&&c!=d)
    {
        ++a,--c;
        if (a==n+1) a=1;
        if (c==0) c=n;
        if (a==c)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}