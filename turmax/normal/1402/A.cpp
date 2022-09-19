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
        int n,k;
        cin>>n>>k;
        int ans=0;
        if((n-k)%2!=0)
        {
            ans=1;
        }
        ans=max(ans,k-n);
        cout<<ans<<endl;
    }
    return 0;
}