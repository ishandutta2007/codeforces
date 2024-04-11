#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int cycle=0;cycle<q;++cycle)
    {
    int n,t,a,b;
    cin>>n>>t>>a>>b;
    vector <int> c(n);
    vector <int> d(n);
    vector <int> f(n);
    vector <pair<pair<int,int>,pair<int,int> > > e(n);
    int l=0,r=0;
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
        if(c[i]==1)
        {
            c[i]=b;
            ++r;
        }
        else
        {
            c[i]=a;
            ++l;
        }
    }
    for(int i=0;i<n;++i)
    {
        cin>>d[i];
        if(d[i]>t)
        {
            f[i]=0;
            d[i]=0;
        }
        else
        {
            f[i]=1;
        }
    }
    for(int i=0;i<n;++i)
    {
        //cout<<(-f[i])<<endl;
        e[i]={{-f[i],d[i]},{c[i],i}};
        //cout<<e[i].first.first<<endl;
    }
    sort(e.begin(),e.end());
    int curr=0;
    bool h=true;
    int ans=0;
    int z;
    int ma=0;
    e.push_back({{-1,1e9+1},{1e9+1,1e9+1}});
    for(int j=0;j<n;++j)
    {
        z=e[j].second.second;
        //cout<<j<<" rfdes "<<endl;
        if((d[z]-curr)>0)
        ma=max(ma,ans+min(l,(d[z]-curr-1)/a));
        //cout<<ma<<endl;
        //cout<<z<<endl;
        if(e[j].first.first==0 && (curr+c[z])>t)
        {
            break;
        }
        if((curr+c[z])>t)
        {
            break;
        }
        curr+=c[z];
        if(c[z]==b)
        {
            r--;
        }
        else
        {
            l--;
        }
        ++ans;
        //cout<<curr<<endl;
        //cout<<e[j+1].first.first<<" "<<e[j+1].first.second<<endl;
        //cout<<(e[j+1].first.second*e[j+1].first.first)<<" tgfd "<<endl;
        if((curr)<(-e[j+1].first.second*e[j+1].first.first))
        {
            ma=max(ma,ans);
        }
    }
    cout<<ma<<endl;
    }
    return 0;
}