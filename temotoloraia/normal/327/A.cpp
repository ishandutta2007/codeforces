#include <bits/stdc++.h>
using namespace std;
int i,j,a[100001],n,m,l,r,dp[100001],ans,s;
main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    cin>>a[i];
    for (l=1;l<=n;l++)
    for (r=l;r<=n;r++)
    {
        s=0;
        for (i=1;i<=n;i++)
        if (i>=l && i<=r)
        s+=1-a[i];
        else
        s+=a[i];
        if (s>ans)
        ans=s;
    }
    cout<<ans;
}