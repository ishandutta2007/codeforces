#include <bits/stdc++.h>
using namespace std;
int n,x,sum,ans=0;
int main()
{
    sum=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        ans=max(ans,x);
        sum+=x;
    }
    sum=sum*2+1;
    ans=max(ans,(sum+n-1)/n);
    printf("%d\n",ans);
    return 0;
}