#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <pair<int,pair<int,int> > > ed;
int parent[maxn];
int get(int x)
{
    if(parent[x]==(-1)) return x;
    int ans=get(parent[x]);
    parent[x]=ans;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) parent[i]=(-1);
    int m,n;
    cin>>m>>n;
    int a[m],b[n];
    for(int i=0;i<m;++i) cin>>a[i];
    for(int j=0;j<n;++j) cin>>b[j];
    vector <int> u[m];
    vector <pair<int,int> > v[n];
    for(int i=0;i<m;++i)
    {
        int c;
        cin>>c;
        for(int j=0;j<c;++j)
        {
            int x;
            cin>>x;
            x--;
            u[i].push_back(x);
            v[x].push_back({a[i],i});
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(!v[i].empty())
        {
            for(int j=0;j<v[i].size();++j)
            {
                ed.push_back({v[i][j].first+b[i],{i+1e5+1,v[i][j].second}});
                ans+=(v[i][j].first+b[i]);
            }
        }
    }
    sort(ed.begin(),ed.end());reverse(ed.begin(),ed.end());
    for(auto h:ed)
    {
        int x=get(h.second.first);int y=get(h.second.second);
        if(x!=y)
        {
            parent[x]=y;
            ans-=h.first;
        }
    }
    cout<<ans;
    return 0;
}