#include <bits/stdc++.h>
using namespace std;
int n,v;
int main()
{
    scanf("%d%d",&n,&v);
    if (v>=n-1) printf("%d\n",n-1);
    else
    {
        int ans=v;
        for (int i=v+1;i<=n-1;i++)
            ans+=i-v+1;
        printf("%d\n",ans);
    }
    return 0;
}