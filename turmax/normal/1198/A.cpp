#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n,k;
    cin>>n>>k;
    k*=8;
    int l=(k/n);
    if(l>=25)
    {
        cout<<0;
        return 0;
    }
    int u=(1<<l);
    vector <int> v;
    unordered_map <int,int> b;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        if(b.count(x)==0)
        {
            v.push_back(x);
        }
        if(b.count(x)==0)
        {
            b[x]=1;
        }
        else
        {
            b[x]++;
        }
    }
    sort(v.begin(),v.end());
    int y=v.size()-u;
    if(y<=0)
    {
        cout<<0;
        return 0;
    }
    else
    {
        int sum=0;
        for(int i=0;i<v.size();++i)
        {
            sum+=b[v[i]];
        }
        int mi=1e18;
        for(int i=0;i<(v.size()-y);++i)
        {
            sum-=b[v[i]];
        }
        mi=min(mi,sum);
        for(int j=0;j<y;++j)
        {
            sum+=b[v[j]];
            sum-=b[v[j+v.size()-y]];
            mi=min(mi,sum);
        }
        cout<<mi;
        return 0;
    }
    return 0;
}