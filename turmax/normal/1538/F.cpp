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
        int l,r;
        cin>>l>>r;
        int ans=0;
        int o=1;
        for(int i=0;i<=9;++i)
        {
            ans+=(r/o-l/o);
            o*=10;
        }
        cout<<ans<<'\n';
    }
    return 0;
}