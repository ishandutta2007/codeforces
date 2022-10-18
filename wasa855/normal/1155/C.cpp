#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[300005];
int b[300005];
int gcd(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    return gcd(y,x%y);
}
signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++)
    {
        scanf("%I64d",&b[i]);
    }
    int ans=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        ans=gcd(ans,a[i]-a[i-1]);
    }
    for(int i=1;i<=m;i++)
    {
        if(ans%b[i]==0)
        {
            printf("YES\n%I64d %I64d\n",a[1],i);
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}