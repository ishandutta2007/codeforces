#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int pr[n+1];
    pr[0]=0;
    for(int i=0;i<n;++i)
    {
        pr[i+1]=pr[i]+a[i];
    }
    int ans=1e18;
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        int z=upper_bound(a,a+n,x)-lower_bound(a,a+n,x);
        if(z>=k)
        {
            ans=0;
            continue;
        }
        int t=lower_bound(a,a+n,x)-a;
        int h=pr[t];
        if(t==i && (t+z)>=k)
        {
        ans=min(ans,k-z+(x-1)*i-pr[t]);
        }
        int u=x*t-pr[t];
        int l=t;
        t=upper_bound(a,a+n,x)-a;
        h=pr[n]-pr[t];
        if(t==(i+1) && (z+(n-t))>=k)
        {
        ans=min(ans,k-z+h-(x+1)*(n-i-1));
        }
        if(t==(i+1) && (l+z)<k)
        ans=min(ans,k-l-z+h-(x+1)*(n-i-1)+u);
    }
    cout<<ans<<endl;
    return 0;
}