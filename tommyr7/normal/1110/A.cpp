#include <bits/stdc++.h>
using namespace std;
int b,k;
int x;
int main()
{
    int ans=0;
    scanf("%d%d",&b,&k);
    for (int i=1;i<=k;i++)
    {
        scanf("%d",&x);
        if (i==k) ans=(ans+x)%2;
        else if (b%2==1) ans=(ans+x)%2;
    }
    if (ans%2==1) printf("odd\n"); else printf("even\n");
    return 0;
}