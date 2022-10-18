#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[300005];
int f[3][300005];
signed main()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[0][i]=max(f[0][i-1]+a[i],0LL);
        f[1][i]=max(f[1][i-1]+a[i]*x,f[0][i]);
        f[2][i]=max(f[1][i],f[2][i-1]+a[i]);
        ans=max(ans,f[2][i]);
    }
    cout<<ans<<endl;
    return 0;
}