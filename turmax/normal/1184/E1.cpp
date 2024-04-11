#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> parent;
vector <int> lp;
int glav(int x)
{
    int y=x;
    while(parent[y]!=y)
    {
        y=parent[y];
    }
    return y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    parent.resize(n);
    lp.resize(n);
    int x,y,w;
    vector <pair<pair<int,int>,pair<int,int> > > a;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>w;
        x--;
        y--;
        a.push_back({{w,i},{x,y}});
    }
    int low=0;
    int up=1e9+1;
    int k;
    int r1,r2;
    bool z;
    int v1,v2;
    v1=a[0].second.first;
    v2=a[0].second.second;
    while(true)
    {
        for(int i=0;i<n;++i)
        {
            parent[i]=i;
            lp[i]=1;
        }
        if((up-low)==1)
        {
            cout<<low;
            return 0;
        }
        k=(low+up)/2;
        for(int i=0;i<m;++i)
        {
            if(a[i].second.first==v1 && a[i].second.second==v2)
            {
                a[i].first.first=k;
                break;
            }
        }
        sort(a.begin(),a.end());
        z=false;
        for(int i=0;i<m;++i)
        {
            x=a[i].second.first;
            y=a[i].second.second;
            r1=glav(x);
            r2=glav(y);
            if(r1!=r2)
            {
                if(v1==x && v2==y)
                {
                    z=true;
                    break;
                }
                else
                {
                    if(lp[r1]>=lp[r2])
                    {
                        parent[r2]=r1;
                        lp[r1]+=lp[r2];
                    }
                    else
                    {
                        parent[r1]=r2;
                        lp[r2]+=lp[r1];
                    }
                }
            }
        }
        if(z)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
    return 0;
}