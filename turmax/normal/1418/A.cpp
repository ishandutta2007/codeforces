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
        int x,y,k;
        cin>>x>>y>>k;
        int low=(-1);
        int up=(4e18/(x-1));
        int ans=4e18;
        while(true)
        {
            //cout<<low<<" low "<<up<<" up "<<endl;
            if((up-low)==1) break;
            int m=(low+up)/2;
            int z=m*(x-1)+1;
            z-=k*y;
            bool h=false;
            if(z>=k) h=true;
            if(!h)
            {
                low=m;
            }
            else
            {
                up=m;
                ans=min(ans,m+k);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}