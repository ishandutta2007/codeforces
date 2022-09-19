#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=803;
vector <pair<int,pair<int,int> > > u;
int dp[maxn][maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector <pair<int,pair<int,int> > > b;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        b.push_back({w,{x,y}});
    }
    sort(b.begin(),b.end());
    vector <pair<int,pair<int,int> > > h;
    vector <int> v;
    for(int i=0;i<min(k,(int) b.size());++i)
    {
        int w=b[i].first;int x=b[i].second.first;int y=b[i].second.second;
        h.push_back(b[i]);
        v.push_back(x);v.push_back(y);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    map <int,int> u1;
    for(int i=0;i<v.size();++i)
    {
        u1[v[i]]=i;
    }
    for(int i=0;i<h.size();++i)
    {
        u.push_back({h[i].first,{u1[h[i].second.first],u1[h[i].second.second]}});
    }
    for(int i=0;i<maxn;++i)
    {
        for(int j=0;j<maxn;++j)
        {
            dp[i][j]=1e18;
        }
    }
    for(int i=0;i<u.size();++i)
    {
        int w=u[i].first;int x=u[i].second.first;int y=u[i].second.second;
        dp[x][y]=w;
        dp[y][x]=w;
    }
    for(int cyc=0;cyc<maxn;++cyc)
    {
        //cout<<cyc<<" cyc "<<endl;
        for(int i=0;i<maxn;++i)
        {
            for(int j=0;j<maxn;++j)
            {
                dp[i][j]=min(dp[i][j],dp[i][cyc]+dp[cyc][j]);
            }
        }
    }
    vector <int> l;
    for(int i=0;i<maxn;++i)
    {
        for(int j=0;j<i;++j)
        {
            l.push_back(dp[i][j]);
        }
    }
    sort(l.begin(),l.end());
    cout<<l[k-1];
    return 0;
}