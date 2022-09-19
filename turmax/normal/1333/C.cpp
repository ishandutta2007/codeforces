#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int pr[n+1];
    pr[0]=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        pr[i+1]=pr[i]+a[i];
    }
    map <int,vector <int> > h;
    for(int i=0;i<=n;++i)
    {
        if(!h.count(pr[i]))
        {
            vector <int> v;
            v.push_back(i);
            h[pr[i]]=v;
        }
        else
        {
            h[pr[i]].push_back(i);
        }
    }
    int l[n+1];
    for(int i=0;i<=n;++i)
    {
        if(h[pr[i]][h[pr[i]].size()-1]==i)
        {
            l[i]=(n+1-i);
            continue;
        }
        l[i]=(*upper_bound(h[pr[i]].begin(),h[pr[i]].end(),i))-i;
    }
    for(int i=n;i>=0;--i)
    {
        l[i]=min(l[i],l[i+1]+1);
    }
    int sum=0;
    for(int i=0;i<=n;++i)
    {
        sum+=l[i];
    }
    cout<<sum-n-1;
    return 0;
}