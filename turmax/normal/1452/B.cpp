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
        int sum=0;
        int ma=(-1e18);
        for(int i=0;i<n;++i) {cin>>a[i];sum+=a[i];ma=max(ma,a[i]);}
        int u;
        if(sum%(n-1)==0) u=0;
        else u=(n-1)-sum%(n-1);
        int ans=max(u,ma*(n-1)-sum);
        cout<<ans<<endl;
    }
    return 0;
}