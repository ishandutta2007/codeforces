#include <bits/stdc++.h>

using namespace std;
#define int long long
pair <int,int> perec(pair <int,int> a,pair<int,int> b)
{
    return {max(a.first,b.first),min(a.second,b.second)};
}
pair <bool,int> check(vector <int> a,int m)
{
    pair <int,int> u=make_pair(0,1e9);
    int n=a.size();
    for(int i=0;i<(n-1);++i)
    {
        if(a[i+1]!=(-1) && (a[i]!=(-1)))
        {
            if(abs(a[i+1]-a[i])>m)
            {
                return {false,-1};
            }
        }
        else if(a[i]!=(-1))
        {
            u=perec(u,{a[i]-m,a[i]+m});
        }
        else if(a[i+1]!=(-1))
        {
            u=perec(u,{a[i+1]-m,a[i+1]+m});
        }
    }
    if(u.first>u.second)
    {
        return {false,-1};
    }
    else
    {
        return {true,u.first};
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int low=(-1);
    int up=1e18;
    int k;
    int ans=(-1);
    while(true)
    {
        if((up-low)==1)
        {
            cout<<up<<" "<<ans<<endl;
            break;
        }
        k=(low+up)/2;
        pair <int,int> o=check(a,k);
        if(o.first)
        {
            up=k;
            ans=o.second;
        }
        else
        {
            low=k;
        }
    }
    }
    return 0;
}