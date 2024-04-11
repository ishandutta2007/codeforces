#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n+1];a[n]=0;for(int i=0;i<n;++i) cin>>a[i];
        int ans=0;
        for(int i=1;i<n-1;++i)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])
            {
                ++ans;
                a[i+1]=max(a[i],a[i+2]);
            }
        }
        cout<<ans<<'\n';
        for(int i=0;i<n;++i) cout<<a[i]<<' ';
        cout<<'\n';
    }
    return 0;
}