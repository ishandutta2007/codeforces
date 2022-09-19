#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int ans=0;
    int n;
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        for(int j=2;(i*j)<=n;++j)
        {
            ans+=(4*j);
        }
    }
    cout<<ans;
    return 0;
}