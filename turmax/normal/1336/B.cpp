#include <bits/stdc++.h>

using namespace std;
#define int long long
int cls(vector <int> &v,int x,int n)
{
    int ans=1e18;
    int u=(lower_bound(v.begin(),v.begin()+n,(x+1)/2)-v.begin());
    //cout<<v[n-1]<<" v[n-1] "<<endl;
    //cout<<u<<" u "<<endl;
    if(u!=n)
    {
        ans=v[u];
    }
    if(u!=0 && (u==n || (v[u-1]+v[u])>=x))
    {
        ans=v[u-1];
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int na,nb,nc;
    cin>>na>>nb>>nc;
    vector <int> v1(na),v2(nb),v3(nc);
    for(int i=0;i<na;++i)
    {
        cin>>v1[i];
    }
    for(int i=0;i<nb;++i)
    {
        cin>>v2[i];
    }
    for(int i=0;i<nc;++i)
    {
        cin>>v3[i];
    }
    sort(v1.begin(),v1.begin()+na);sort(v2.begin(),v2.begin()+nb);sort(v3.begin(),v3.begin()+nc);
    int ans=1e18*4;
    for(int i=0;i<na;++i)
    {
        int x=v1[i];
        if(v1[i]>v2[nb-1] || v1[i]>v3[nc-1])
        {
            continue;
        }
        int y=*(lower_bound(v2.begin(),v2.begin()+nb,v1[i]));
        int z=*(lower_bound(v3.begin(),v3.begin()+nc,v1[i]));
        //cout<<x<<" "<<y<<" "<<z<<" xyz "<<endl;
        if(y>=z)
        {
            int z=cls(v3,x+y,nc);
            ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
        }
        else
        {
            int y=cls(v2,x+z,nb);
            ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
        }
    }
    swap(v1,v2);
    swap(na,nb);
    for(int i=0;i<na;++i)
    {
        int x=v1[i];
        if(v1[i]>v2[nb-1] || v1[i]>v3[nc-1])
        {
            continue;
        }
        int y=*(lower_bound(v2.begin(),v2.begin()+nb,v1[i]));
        int z=*(lower_bound(v3.begin(),v3.begin()+nc,v1[i]));
        //cout<<x<<" "<<y<<" "<<z<<" xyz "<<endl;
        if(y>=z)
        {
            int z=cls(v3,x+y,nc);
            ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
        }
        else
        {
            int y=cls(v2,x+z,nb);
            ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
        }
    }
    swap(v1,v3);
    swap(na,nc);
    for(int i=0;i<na;++i)
    {
        int x=v1[i];
        if(v1[i]>v2[nb-1] || v1[i]>v3[nc-1])
        {
            continue;
        }
        int y=*(lower_bound(v2.begin(),v2.begin()+nb,v1[i]));
        int z=*(lower_bound(v3.begin(),v3.begin()+nc,v1[i]));
        if(y>=z)
        {
            int z=cls(v3,x+y,nc);
            ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
        }
        else
        {
            int y=cls(v2,x+z,nb);
            ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}