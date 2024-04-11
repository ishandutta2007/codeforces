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
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) {int y;cin>>y;}
        sort(a,a+n);
        int u[n];
        pair <int,int> h[n+1];
        for(int i=0;i<n;++i)
        {
            u[i]=lower_bound(a,a+n,a[i]+k+1)-lower_bound(a,a+n,a[i]);
            h[i]={a[i],u[i]};
            //cout<<i<<" i "<<endl;
            //cout<<u[i]<<" u[i] "<<endl;
        }
        h[n]={1e18,0};
        int ma=(-1e18);
        for(int i=n;i>=0;i--)
        {
            ma=max(ma,h[i].second);
            h[i].second=ma;
        }
        int ans[n];
        for(int i=0;i<n;++i)
        {
            pair <int,int> r=*lower_bound(h,h+n+1,make_pair(a[i]+k+1,(int) -1));
            ans[i]=u[i]+r.second;
        }
        cout<<*max_element(ans,ans+n)<<endl;
    }
    return 0;
}