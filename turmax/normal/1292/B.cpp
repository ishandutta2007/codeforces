#include <bits/stdc++.h>

using namespace std;
#define int long long
int dist(pair<int,int> a,pair<int,int> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x0,y0,a1,a2,b1,b2;
    cin>>x0>>y0>>a1>>a2>>b1>>b2;
    int x,y,t;
    cin>>x>>y>>t;
    vector <pair<int,int> > a;
    a.push_back({x0,y0});
    pair<int,int> u;
    while(true)
    {
        u=a[a.size()-1];
        if(u.first>=(1e18/a1) || u.second>=(1e18/a2))
        {
            break;
        }
        a.push_back({u.first*a1+b1,u.second*a2+b2});
    }
    int ans=0;
    pair <int,int> curr=make_pair(x,y);
    int s=0;
    pair <int,int> d;
    int z;
    for(int i=0;i<a.size();++i)
    {
        curr=make_pair(x,y);
        int h=t;
        s=0;
        d=a[i];
        z=i;
        while(z<a.size() && dist(d,curr)<=h)
        {
            ++s;
            h-=dist(d,curr);
            if(z==0)
            {
                z=(i+1);
            }
            else if(z<=i)
            {
                z--;
            }
            else
            {
                ++z;
            }
            curr=d;
            if(z<a.size())
            {
                d=a[z];
            }
        }
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}