#include <bits/stdc++.h>

using namespace std;
vector <pair<int,int> > a;
int u[300001];
int check(int n)
{
    for(int i=0;i<300001;++i)
    {
        u[i]=0;
    }
    int y=a.size();
    for(int i=0;i<a.size();++i)
    {
        if(a[i].first!=n && a[i].second!=n)
        {
            u[a[i].first]++;
            u[a[i].second]++;
        }
        else
        {
            y--;
        }
    }
    for(int i=0;i<300001;++i)
    {
        if(u[i]==y)
        {
            return 1;
        }
    }
    return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y;
    int t[300001];
    for(int i=0;i<300001;++i)
    {
        t[i]=0;
    }
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        t[x]++;
        t[y]++;
        a.push_back({x,y});
    }
    vector <int> d;
    for(int i=1;i<=n;++i)
    {
        if(t[i]>=(m/2))
        {
            d.push_back(i);
        }
    }
    for(int i=0;i<d.size();++i)
    {
        if(check(d[i])==1)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}