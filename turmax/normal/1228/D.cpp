#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    map <pair<int,int>,int> b;
    vector <pair<int,int> > c;
    vector <vector <int> > a(n);
    int x,y;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
        b[{x,y}]=1;
        b[{y,x}]=1;
        c.push_back({x,y});
        c.push_back({y,x});
    }
    vector <int> res(n);
    for(int i=0;i<n;++i)
    {
        res[i]=(-1);
    }
    res[0]=0;
    for(int i=0;i<n;++i)
    {
        if(b.count({0,i})==0)
        {
            res[i]=0;
        }
    }
    int z;
    for(int i=0;i<n;++i)
    {
        if(res[i]==(-1))
        {
            z=i;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(res[i]==(-1) && b.count({z,i})==0)
        {
            res[i]=1;
        }
        else if(res[i]==(-1))
        {
            res[i]=2;
        }
    }
    int sz1=0,sz2=0,sz3=0;
    for(int i=0;i<n;++i)
    {
        if(res[i]==0)
        {
            ++sz1;
        }
        if(res[i]==1)
        {
            ++sz2;
        }
        if(res[i]==2)
        {
            ++sz3;
        }
    }
    if((sz1*sz2*sz3)==0)
    {
        cout<<(-1);
        return 0;
    }
    if((m)!=(sz1*sz2+sz2*sz3+sz3*sz1))
    {
        cout<<(-1);
        return 0;
    }
    int x1,x2;
    for(int i=0;i<2*m;++i)
    {
        x1=res[c[i].first];
        x2=res[c[i].second];
        if(x1==x2)
        {
            cout<<(-1);
            return 0;
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<res[i]+1<<" ";
    }
    return 0;
}