#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> parent;
vector <int> lp;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y;
    vector <vector <int> > a(n);
    set <pair<int,int> > z;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
        z.insert({x,y});
        z.insert({y,x});
    }
    int ans=0;
    vector <int> v;
    bool h;
    int u;
    for(int i=0;i<n;++i)
    {
        h=true;
        for(int j=(i+1);j<n;++j)
        {
            if(z.count({i,j})==0)
            {
                v=a[j];
                if(v.empty())
                {
                    h=false;
                    break;
                }
                for(int k=0;k<v.size();++k)
                {
                    u=v[k];
                    if(u<=i)
                    {
                        continue;
                    }
                    if(z.count({u,i})==0 && z.count({u,j})==1)
                    {
                        z.erase({u,j});
                        z.erase({j,u});
                    }
                }
                h=false;
                break;
            }
        }
        if(h)
        {
            ++ans;
        }
    }
    cout<<ans-1;
    return 0;
}