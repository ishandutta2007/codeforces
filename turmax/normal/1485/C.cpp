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
        int x,y;
        cin>>x>>y;
        int ans=0;
        for(int r=1;r<100000;++r)
        {
            int u=(x/r)-1;//[r+1;u]
            ans+=max(0LL,min(y,u)-r);
        }
        cout<<ans<<'\n';
    }
    return 0;
}