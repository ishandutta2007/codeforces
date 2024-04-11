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
        int ans=1e18;
        for(int i=0;i<30;++i)
        {
            int o=(y+i);
            if(o==1) continue;
            int res=i;
            int x1=x;
            while(true)
            {
                x1/=o;
                ++res;
                if(x1==0) break;
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}