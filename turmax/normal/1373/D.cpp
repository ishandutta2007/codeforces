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
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(i%2==0)
            {
                ans+=a[i];
            }
        }
        int pr[n+1];pr[0]=0;
        for(int i=0;i<n;++i)
        {
            if(i%2==0)
            {
                pr[i+1]=pr[i]+a[i];
            }
            else
            {
                pr[i+1]=pr[i]-a[i];
            }
        }
        int ma=0;
        int ans1=0;
        for(int i=0;i<=n;i+=2)
        {
            ans1=max(ans1,ma-pr[i]);
            ma=max(ma,pr[i]);
        }
        ma=(-1e18);
        for(int i=1;i<=n;i+=2)
        {
            ans1=max(ans1,ma-pr[i]);
            ma=max(ma,pr[i]);
        }
        cout<<ans+ans1<<endl;
    }
    return 0;
}