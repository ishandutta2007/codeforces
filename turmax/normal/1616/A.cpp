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
        int n;cin>>n;
        map <int,int> u;for(int i=0;i<n;++i) {int x;cin>>x;++u[abs(x)];}
        int ans=0;
        for(auto [key,val]:u)
        {
            int o=2;if(key==0) o=1;
            ans+=min(val,o);
        }
        cout<<ans<<'\n';
    }
    return 0;
}