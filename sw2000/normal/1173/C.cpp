#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;

int main()
{
    int n,a[maxn],b[maxn],ans=0,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);

    for(int i=1;i<=n;i++)
    {
        if(b[i]==1)flag=1;
        else if(flag)
        {
            if(b[i]==b[i-1]+1)flag++;
            else
            {
                flag=0;
                break;
            }
        }
    }

    if(flag)
    {
        for(int i=1;i<=n-flag;i++)
        {
            if(b[i]&&b[i]-i-1-flag<0)
            {
                cout<<n+n-flag+1;
                return 0;
            }
        }
        cout<<n-flag;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        if(b[i])ans=max(ans,i-b[i]+1);
    }
    cout<<ans+n;
    return 0;
}