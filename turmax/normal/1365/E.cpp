#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            ans=max(ans,a[i] | a[j]);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            for(int k=0;k<j;++k)
            {
                ans=max(ans,a[i] | a[j] | a[k]);
            }
        }
    }
    cout<<ans;
    return 0;
}