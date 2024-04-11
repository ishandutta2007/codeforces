#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,z;cin>>n>>z;int a[n];int x=z;int s=z;for(int i=0;i<n;++i) {cin>>a[i];s+=a[i];x&=a[i];}
        int ans=0;for(int i=0;i<n;++i) ans=max(ans,a[i] | z);
        cout<<ans<<'\n';
    }
    return 0;
}