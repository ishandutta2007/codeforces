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
        if(n%2050==0)
        {
            int u=(n/2050);
            int ans=0;
            while(u!=0)
            {
                ans+=(u%10);
                u/=10;
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<(-1)<<endl;
        }
    }
    return 0;
}