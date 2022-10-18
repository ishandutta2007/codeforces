#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int a[N],dp[N];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int l=max(i-k,1),r=min(i+k,n);
        if(a[i]==0)
            dp[i]=r-l+1;
        else
        {
            int p=a[i];
            int pr=min(p+k,n);
            if(pr<l)
                dp[i]=dp[p]+r-l+1;
            else
                dp[i]=dp[p]+r-pr;
        }
        printf("%d ",dp[i]);
    }
}