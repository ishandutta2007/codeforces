#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
int parent[maxn];
vector <int> v[maxn];
int a[maxn];
int sz[maxn];
int glav(int x)
{
    vector <int> v;
    while(true)
    {
        v.push_back(x);
        if(parent[x]==(-1))
        {
            for(int i=0;i<v.size()-1;++i)
            {
                parent[v[i]]=x;
            }
            return x;
        }
        x=parent[x];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i)
    {
        parent[i]=(-1);
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i) {cin>>a[i];a[i]--;v[a[i]].push_back(i);}
    for(int i=0;i<m;++i) sz[i]=v[i].size();
    int ans=1;
    for(int i=0;i<(n-1);++i)
    {
        if(a[i]!=a[i+1])
        {
            ++ans;
        }
    }
    cout<<ans-1<<endl;
    for(int i=0;i<(m-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        x=glav(x);y=glav(y);
        //cout<<x<<" "<<y<<endl;
        bool s=false;
        if(sz[x]>=sz[y])
        {
            s=true;
            swap(x,y);
        }
        for(auto h:v[x])
        {
            if(h!=0 && a[h-1]==y)
            {
                ans--;
            }
            if(h!=(n-1) && a[h+1]==y)
            {
                ans--;
            }
        }
        if(!s)
        {
            //cout<<" ytgfrd "<<endl;
            parent[x]=y;
        }
        for(auto h:v[x])
        {
            v[y].push_back(h);
            sz[y]++;
            a[h]=y;
        }
        sz[x]=0;
        v[x].clear();
        cout<<ans-1<<endl;
    }
    return 0;
}