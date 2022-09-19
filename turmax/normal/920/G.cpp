#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> rasl(int p)
{
    vector <int> v;
    if(p==1) return v;
    for(int i=2;i*i<=p;++i)
    {
        if(p%i==0)
        {
            v=rasl(p/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(p);
    return v;
}
int cnt(int x,vector <pair<int,int> > h)
{
    int sum=0;
    for(auto o:h)
    {
        sum+=(o.second*(x/o.first));
    }
    return sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int x,p,k;
    cin>>x>>p>>k;
    int low=x;
    int up=1e18;
    vector <int> v=rasl(p);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector <pair<int,int> > h;
    int sz=(1<<v.size());
    for(int mask=0;mask<sz;++mask)
    {
        int o1=1;int o2=1;
        for(int i=0;i<v.size();++i)
        {
            if(mask & (1<<i))
            {
                o2*=(-1);
                o1*=v[i];
            }
        }
        h.push_back({o1,o2});
    }
    int o=cnt(x,h);
    while(true)
    {
        if((up-low)==1)
        {
            cout<<up<<endl;
            break;
        }
        int m=(low+up)/2;
        if((cnt(m,h)-o)>=k)
        {
            up=m;
        }
        else
        {
            low=m;
        }
    }
    }
    return 0;
}