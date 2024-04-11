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
        int n,l,r;
        cin>>n>>l>>r;
        pair <int,int> u[n+1];
        for(int i=0;i<=n;++i) u[i]={0,0};
        for(int i=0;i<l;++i) {int x;cin>>x;x--;u[x].first++;}
        for(int i=0;i<r;++i) {int x;cin>>x;x--;u[x].second++;}
        int ans=0;
        int l1=l,r1=r;
        for(int i=0;i<=n;++i)
        {
            int z=min(u[i].first,u[i].second);
            u[i].first-=z;u[i].second-=z;l1-=z;r1-=z;
            if(u[i].first!=0 && l1>=r1)
            {
                int z=min(u[i].first/2,(l1-r1)/2);
                ans+=z;
                l1-=(2*z);
            }
            if(u[i].second!=0 && r1>=l1)
            {
                int z=min(u[i].second/2,(r1-l1)/2);
                ans+=z;
                r1-=(2*z);
            }
        }
        ans+=max(l1,r1);
        cout<<ans<<endl;
    }
    return 0;
}