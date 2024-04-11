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
        int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int sum=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            sum+=a[i];
            if(2*sum==(i+1)*(i+2))
            {
                ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}