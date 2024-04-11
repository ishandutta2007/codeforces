#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y,k;
    cin>>x>>k>>y;
    int a[n];
    int u[n];
    for(int i=0;i<n;++i) {cin>>a[i];a[i]--;u[a[i]]=i;}
    int b[m];
    for(int i=0;i<m;++i) {cin>>b[i];b[i]--;}
    int ans=0;
    int l=(-1);
    int r=u[b[0]];
    //cout<<l<<" "<<r<<endl;
    int ma1=b[0];
    int ma=(-1);
    for(int i=(l+1);i<r;++i)
    {
        ma=max(ma,a[i]);
    }
    int ans1=1e18;
    if(ma1>ma)
    {
        ans1=(r-l-1)*y;
    }
    for(int i=1;i<=((r-l-1)/k);++i)
    {
        ans1=min(ans1,i*x+(r-l-1-k*i)*y);
    }
    //cout<<ans1<<" ans1 "<<endl;
    ans+=ans1;
    if(ans>=1e18)
    {
        cout<<(-1);
        return 0;
    }
    for(int i=0;i<(m-1);++i)
    {
        if(u[b[i+1]]<u[b[i]])
        {
            cout<<(-1);
            return 0;
        }
        int l=u[b[i]];
        int r=u[b[i+1]];
        //cout<<l<<' '<<r<<endl;
        int ma1=max(b[i],b[i+1]);
        int ma=(-1);
        for(int i=(l+1);i<r;++i)
        {
            ma=max(ma,a[i]);
        }
        int ans1=1e18;
        if(ma1>ma)
        {
            ans1=(r-l-1)*y;
        }
        for(int i=1;i<=((r-l-1)/k);++i)
        {
            ans1=min(ans1,i*x+(r-l-1-k*i)*y);
        }
        //cout<<ans1<<" ans1 "<<endl;
        ans+=ans1;
        if(ans>=1e18)
        {
            cout<<(-1);
            return 0;
        }
    }
    l=u[b[m-1]];
    r=n;
    ma1=b[m-1];
    ma=(-1);
    for(int i=(l+1);i<r;++i)
    {
        ma=max(ma,a[i]);
    }
    ans1=1e18;
    if(ma1>ma)
    {
        ans1=(r-l-1)*y;
    }
    for(int i=1;i<=((r-l-1)/k);++i)
    {
        ans1=min(ans1,i*x+(r-l-1-k*i)*y);
    }
    ans+=ans1;
    if(ans>=1e18)
    {
        cout<<(-1);
        return 0;
    }
    cout<<ans;
    return 0;
}