#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int p[n+1],a[n+1];
    a[0]=n+1;
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]),a[p[i]]=i;
    int dp[n+1],m=1;
    for(int i=1;i<=n;i++)
        if(a[p[i]-1]<i)
            m=max(m,dp[i]=dp[a[p[i]-1]]+1);
        else
            dp[i]=1;
    printf("%d\n",n-m);
}