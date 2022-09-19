#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > a;
vector <int> b;
vector <bool> used;
vector <pair<int,int> > dfs(int x)
{
    int v;
    used[x]=true;
    vector <pair <int,int> > t;
    int z;
    z=0;
    vector <pair<int,int> > v1;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            v1=dfs(v);
            for(int i=0;i<v1.size();++i)
            {
                v1[i].first+=z;
            }
            z+=v1.size();
            for(int i=0;i<v1.size();++i)
            {
                t.push_back(v1[i]);
            }
        }
    }
    sort(t.begin(),t.end());
    int d=b[x];
    int r=t.size();
    if(t.empty())
    {
        r=0;
    }
    if(d>r)
    {
        cout<<"NO";
        exit(0);
    }
    for(int i=0;i<r;++i)
    {
        if(t[i].first>=b[x])
        {
            t[i].first++;
        }
    }
    t.push_back({b[x],x});
    return t;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int x,y;
    a.resize(n);
    b.resize(n);
    used.resize(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    int c;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        if(x!=0)
        {
            x--;
            a[x].push_back(i);
            a[i].push_back(x);
        }
        else
        {
            c=i;
        }
        b[i]=y;
    }
    vector <pair<int,int> > v=dfs(c);
    vector <int> ans(n);
    for(int i=0;i<v.size();++i)
    {
        ans[v[i].second]=v[i].first;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]+1<<" ";
    }
    return 0;
}