#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int pref[n];
    vector <pair<int,pair<int,int> > > v;
    int ans1=0;
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        int l=i;
        while(!v.empty() && v.back().first>=x)
        {
            ans1-=(v.back().second.second-v.back().second.first+1)*v.back().first;
            l=v.back().second.first;
            v.pop_back();
        }
        ans1+=(i-l+1)*x;
        v.push_back({x,{l,i}});
        pref[i]=ans1;
    }
    /*for(int i=0;i<n;++i) cout<<pref[i]<<' ';
    cout<<endl;*/
    reverse(a,a+n);
    int suf[n];
    v.clear();
    ans1=0;
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        int l=i;
        while(!v.empty() && v.back().first>=x)
        {
            ans1-=(v.back().second.second-v.back().second.first+1)*v.back().first;
            l=v.back().second.first;
            v.pop_back();
        }
        ans1+=(i-l+1)*x;
        v.push_back({x,{l,i}});
        suf[i]=ans1;
    }
    /*for(int i=0;i<n;++i) cout<<suf[i]<<' ';
    cout<<endl;*/
    reverse(a,a+n);
    int ans=0;
    int u=0;
    for(int i=0;i<n;++i)
    {
        if((pref[i]+suf[n-i-1]-a[i])>ans)
        {
            ans=(pref[i]+suf[n-i-1]-a[i]);
            u=i;
        }
    }
    int res[n];
    int curr=a[u];
    for(int i=u;i>=0;--i)
    {
        curr=min(curr,a[i]);
        res[i]=curr;
    }
    curr=a[u];
    for(int i=u;i<n;++i)
    {
        curr=min(curr,a[i]);
        res[i]=curr;
    }
    for(int i=0;i<n;++i) cout<<res[i]<<' ';
    return 0;
}