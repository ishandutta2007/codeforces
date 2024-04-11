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
        int ans=0;
        for(int i=0;i<n;++i) {cin>>a[i];if(i!=0) ans=max(ans,a[i]*a[i-1]);}
        cout<<ans<<'\n';
    }
    return 0;
}