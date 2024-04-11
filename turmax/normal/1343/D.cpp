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
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int mi[n/2];
    int ma[n/2];
    int s[n/2];
    for(int i=0;i<(n/2);++i)
    {
        mi[i]=min(a[i],a[n-i-1]);
        ma[i]=max(a[i],a[n-i-1]);
        s[i]=a[i]+a[n-i-1];
    }
    sort(s,s+n/2);sort(mi,mi+n/2);sort(ma,ma+n/2);
    int ans=n;
    for(int x=2;x<=2*k;++x)
    {
        int ans1=0;
        ans1=(n/2)-(upper_bound(s,s+n/2,x)-lower_bound(s,s+n/2,x));
        //cout<<ans1<<" ans1 "<<endl;
        ans1+=(mi+n/2-lower_bound(mi,mi+n/2,x));
        ans1+=(lower_bound(ma,ma+n/2,x-k)-ma);
        //cout<<x<<" x "<<ans1<<endl;
        ans=min(ans,ans1);
    }
    cout<<ans<<endl;
    }
    return 0;
}