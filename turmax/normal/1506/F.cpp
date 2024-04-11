#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(pair <int,int> a,pair <int,int> b)
{
    //cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
    if(a==b) return 0;
    if(a.second==b.second)
    {
        if(a.second%2==1)
        {
            return 0;
        }
        else
        {
            return abs(b.first-a.first);
        }
    }
    if((b.second-a.second)==(b.first-a.first))
    {
        if(a.second%2==1)
        {
            return (b.second-a.second+1)/2;
        }
        else
        {
            return (b.second-a.second)/2;
        }
    }
    if(a.second%2==1)
    {
        a.first+=abs((b.second-a.second)-(b.first-a.first));
        return go(a,b);
    }
    else
    {
        a.second++;
        a.first++;
        return go(a,b);
    }
}
int go1(pair <int,int> a,pair <int,int> b)
{
    a.second=(a.first-a.second);
    a.first--;
    b.second=(b.first-b.second);
    b.first--;
    return go(a,b);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair <int,int> a[n];
        for(int i=0;i<n;++i) cin>>a[i].first;
        for(int i=0;i<n;++i) cin>>a[i].second;
        sort(a,a+n);
        int ans=go1({1,1},a[0]);
        for(int i=0;i<(n-1);++i)
        {
            ans+=go1(a[i],a[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}