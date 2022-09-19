#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=8e5+5;
vector <pair <int,int> > a[maxn];
int is[maxn];
bool used[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) is[i]=1e18;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        a[4*x].push_back({4*y,w});
        a[4*x].push_back({4*y+1,0}); //("+1" -w)
        a[4*x].push_back({4*y+2,2*w});
        a[4*x].push_back({4*y+3,w});
        a[4*x+1].push_back({4*y+1,w});
        a[4*x+1].push_back({4*y+3,2*w}); //("+1" -w)
        a[4*x+2].push_back({4*y+2,w});
        a[4*x+2].push_back({4*y+3,0});
        a[4*x+3].push_back({4*y+3,w});
        swap(x,y);
        a[4*x].push_back({4*y,w});
        a[4*x].push_back({4*y+1,0}); //("+1" -w)
        a[4*x].push_back({4*y+2,2*w});
        a[4*x].push_back({4*y+3,w});
        a[4*x+1].push_back({4*y+1,w});
        a[4*x+1].push_back({4*y+3,2*w}); //("+1" -w)
        a[4*x+2].push_back({4*y+2,w});
        a[4*x+2].push_back({4*y+3,0});
        a[4*x+3].push_back({4*y+3,w});
    }
    is[0]=0;
    set <pair<int,int> > d;
    for(int i=0;i<4*n;++i) d.insert({is[i],i});
    while(!d.empty())
    {
        pair <int,int> o=(*d.begin());
        d.erase(d.begin());
        int x=o.second;int w=o.first;
        used[x]=true;
        for(auto h:a[x])
        {
            int v=h.first;
            int w1=h.second;
            if(used[v]) continue;
            d.erase({is[v],v});
            is[v]=min(is[v],w+w1);
            d.insert({is[v],v});
        }
    }
    for(int i=1;i<n;++i)
    {
        cout<<is[4*i+3]<<' ';
    }
    return 0;
}