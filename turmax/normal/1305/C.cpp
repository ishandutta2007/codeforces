#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(n>m)
    {
        cout<<0;
        return 0;
    }
    int ans=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            ans*=abs(a[i]-a[j]);
            ans%=m;
        }
    }
    cout<<ans;
    return 0;
}