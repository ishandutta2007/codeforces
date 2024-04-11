#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e4+5;
int ptr[maxn];
int d[maxn];
int n;
vector <pair<int,int> > v;
vector<vector <pair<int,int> > > a(maxn);
int currflow;
pair <int,int> inv(pair <int,int> o)
{
    swap(o.first,o.second);
    return o;
}
bool bfs()
{
    for(int i=0;i<maxn;++i) d[i]=1e18;
    d[0]=0;
    deque <int> q;
    q.push_back(0);
    while(!q.empty())
    {
        deque <int> q1;
        while(!q.empty())
        {
            int curr=q.back();
            q.pop_back();
            for(auto z:a[curr])
            {
                if(d[z.first]==1e18 && v[z.second].first==curr)
                {
                    d[z.first]=d[curr]+1;
                    q1.push_back(z.first);
                }
            }
        }
        q=q1;
    }
    return d[2*n+1]!=1e18;
}
bool dfs(int x)
{
    if(x==(2*n+1))
    {
        ++currflow;
        return true;
    }
    for(int i=ptr[x];i<a[x].size();++i)
    {
        pair <int,int> h=a[x][i];
        if(v[h.second].first!=x || d[h.first]!=(d[x]+1)) continue;
        int z=h.first;
        if(dfs(z))
        {
            v[h.second]=inv(v[h.second]);
            ptr[x]=(i+1);
            return true;
        }
    }
    return false;
}
int maxflow()
{
    currflow=0;
    while(bfs())
    {
        for(int i=0;i<maxn;++i) ptr[i]=0;
        while(dfs(0))
        {

        }
    }
    return currflow;
}
vector <pair<int,pair<int,int> > > q;
bool check(int k)
{
    for(int i=0;i<k;++i)
    {
        int x=q[i].second.first;
        int y=q[i].second.second;
        a[x].push_back({y+n,v.size()});
        a[y+n].push_back({x,v.size()});
        v.push_back({x,y+n});
    }
    return (maxflow()==n);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        a[0].push_back({i+1,v.size()});
        a[i+1].push_back({0,v.size()});
        v.push_back({0,i+1});
    }
    for(int i=0;i<n;++i)
    {
        a[2*n+1].push_back({i+n+1,v.size()});
        a[i+n+1].push_back({2*n+1,v.size()});
        v.push_back({i+n+1,2*n+1});
    }
    for(int i=0;i<m;++i)
    {
        int w,x,y;
        cin>>x>>y>>w;
        q.push_back({w,{x,y}});
    }
    vector <pair<int,int> > v1=v;
    vector <vector <pair<int,int> > > a1=a;
    sort(q.begin(),q.end());
    int low=0;
    int up=(m+1);
    while(true)
    {
        v=v1;
        a=a1;
        if((up-low)==1)
        {
            if(low==m) {cout<<(-1);return 0;}
            else {cout<<q[low].first;return 0;}
        }
        int k=(low+up)/2;
        if(check(k)) up=k;
        else low=k;
    }
    return 0;
}