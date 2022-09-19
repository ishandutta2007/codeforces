#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int sz;
vector <pair<int,int> > b[maxn];
vector <pair<int,int> > v(maxn);
int mp()
{
    set <pair<int,int> > u;
    int is[maxn];
    bool used[maxn];
    for(int i=0;i<sz;++i)
    {
        is[i]=1e18;
        used[i]=false;
        u.insert({is[i],i});
    }
    u.erase({is[0],0});u.insert({0,0});
    is[0]=0;
    while(!u.empty())
    {
        pair <int,int> curr=*u.begin();
        int x=curr.second;
        used[x]=true;
        u.erase(u.begin());
        for(auto v:b[x])
        {
            if(!used[v.second])
            {
                u.erase({is[v.second],v.second});
                is[v.second]=min(is[v.second],v.first+curr.first);
                u.insert({is[v.second],v.second});
            }
        }
    }
    return is[sz-1];
}
int dist(pair <int,int> u,pair <int,int> v)
{
    return min(abs(u.first-v.first),abs(u.second-v.second));
}
int dist1(pair <int,int> u,pair <int,int> v)
{
    return (abs(u.first-v.first)+abs(u.second-v.second));
}
bool cmp(pair <pair<int,int>,int> a,pair<pair<int,int>,int> c)
{
    return a.first.second<c.first.second;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    sz=(m+2);
    cin>>v[0].first>>v[0].second;
    cin>>v[m+1].first>>v[m+1].second;
    for(int i=1;i<=m;++i)
    {
        cin>>v[i].first>>v[i].second;
    }
    vector <pair<pair<int,int>,int> > v1(m+1);
    for(int i=0;i<=m;++i)
    {
        v1[i]={v[i],i};
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size()-1;++i)
    {
        //cout<<v1[i].second<<' '<<v1[i+1].second<<' '<<dist(v1[i].first,v1[i+1].first)<<endl;
        b[v1[i].second].push_back({dist(v1[i].first,v1[i+1].first),v1[i+1].second});
        b[v1[i+1].second].push_back({dist(v1[i].first,v1[i+1].first),v1[i].second});
    }
    sort(v1.begin(),v1.end(),cmp);
    for(int i=0;i<v1.size()-1;++i)
    {
        //cout<<v1[i].second<<' '<<v1[i+1].second<<' '<<dist(v1[i].first,v1[i+1].first)<<endl;
        b[v1[i].second].push_back({dist(v1[i].first,v1[i+1].first),v1[i+1].second});
        b[v1[i+1].second].push_back({dist(v1[i].first,v1[i+1].first),v1[i].second});
    }
    for(int i=0;i<=m;++i)
    {
        b[i].push_back({dist1(v[m+1],v[i]),m+1});
    }
    cout<<mp();
    return 0;
}