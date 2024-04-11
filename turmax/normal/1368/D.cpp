#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int b[n];
    for(int i=0;i<n;++i) b[i]=0;
    for(int i=0;i<20;++i)
    {
        int u[n];
        for(int j=0;j<n;++j)
        {
            if(a[j] & (1<<i))
            {
                u[j]=1;
            }
            else
            {
                u[j]=0;
            }
        }
        sort(u,u+n);
        for(int j=0;j<n;++j)
        {
            if(u[j])
            {
                b[j]+=(1<<i);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=b[i]*b[i];
    }
    cout<<ans<<endl;
    return 0;
}