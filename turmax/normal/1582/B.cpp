#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int c0=0,c1=0;
        for(int i=0;i<n;++i) {cin>>a[i];if(a[i]==0) ++c0;else if(a[i]==1) ++c1;}
        int ans=(1LL<<c0);
        ans*=c1;
        cout<<ans<<'\n';
    }
    return 0;
}