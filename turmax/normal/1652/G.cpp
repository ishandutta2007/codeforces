#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
vector<int> a[maxn];
bool used[maxn];
int tin[maxn];
int corn[maxn];
int timer=0;
void dfs(int x)
{
    used[x]=true;tin[x]=timer;++timer;
    for(int v:a[x]) {if(!used[v]) {corn[v]=corn[x]+1;dfs(v);}}
    ++timer;used[x]=false;
}
bool cmp(int x,int y)
{
    return corn[x]>corn[y];
}
bool cmp2(pair <int,int> u,pair<int,int> v)
{
    return make_pair(u.first,-u.second)<make_pair(v.first,-v.second);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int c[n];for(int i=0;i<n;++i) cin>>c[i];
    for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);}
    dfs(0);
    int d[n];vector<pair<int,int> > h[n];for(int i=0;i<n;++i) {d[i]=1e9;h[i].push_back({0,-1e9});}
    vector<int> z1;for(int i=0;i<n;++i) if(c[i]) {d[i]=0;z1.push_back(i);}
    vector<int> z2;
    while(!z1.empty())
    {
        z2.clear();
        for(int x:z1)
        {
        for(int v:a[x])
        {
            if(d[v]==1e9) {d[v]=d[x]+1;z2.push_back(v);}
        }
        }
        sort(z1.begin(),z1.end(),cmp);
        for(int x:z1)
        {
            for(int y:a[x])
            {
                if(d[y]==d[x]-1)
                {
                    for(auto l:h[y])
                    {
                        h[x].push_back({max(0,l.first-1),l.second+1});
                    }
                }
                if(d[y]==d[x])
                {
                    for(int i=0;i<h[x].size();++i) if(h[x][i].first) h[x][i].second=max(h[x][i].second,0);
                    h[x].push_back({1,0});
                    for(int i=0;i<h[y].size();++i) if(h[y][i].first) h[y][i].second=max(h[y][i].second,0);
                    h[y].push_back({1,0});
                    while(h[x].size()<((int) h[y].size())+1) h[x].push_back(h[x].back());
                    for(auto l:h[y])
                    {
                        h[x].push_back({l.first+1,l.second});
                    }
                }
            }
            sort(h[x].begin(),h[x].end(),cmp2);
                vector<pair<int,int> > hnew;
                int cur=(-2e9);
                for(int i=0;i<h[x].size();++i)
                {
                    if(i==0 || h[x][i].second>cur)
                    {
                        hnew.push_back(h[x][i]);
                    }
                    cur=max(cur,h[x][i].second);
                }
                h[x]=hnew;
        }
        reverse(z1.begin(),z1.end());
        for(int x:z1)
        {
            for(int y:a[x])
            {
                if(d[y]==d[x]-1)
                {
                    for(auto l:h[y])
                    {
                        h[x].push_back({max(0,l.first-1),l.second+1});
                    }
                }
                if(d[y]==d[x])
                {
                    for(int i=0;i<h[x].size();++i) if(h[x][i].first) h[x][i].second=max(h[x][i].second,0);
                    h[x].push_back({1,0});
                    for(int i=0;i<h[y].size();++i) if(h[y][i].first) h[y][i].second=max(h[y][i].second,0);
                    h[y].push_back({1,0});
                    while(h[x].size()<((int) h[y].size())+1) h[x].push_back(h[x].back());
                    for(auto l:h[y])
                    {
                        h[x].push_back({l.first+1,l.second});
                    }
                }
            }
            sort(h[x].begin(),h[x].end(),cmp2);
                vector<pair<int,int> > hnew;
                int cur=(-1e9);
                for(int i=0;i<h[x].size();++i)
                {
                    if(i==0 || h[x][i].second>cur)
                    {
                        hnew.push_back(h[x][i]);
                    }
                    cur=max(cur,h[x][i].second);
                }
                h[x]=hnew;
        }
        z1=z2;
    }
    for(int i=0;i<n;++i)
    {
        int d1=d[i];int u=max(0,h[i][0].second);
        cout<<(d1+u)<<' ';
    }
    return 0;
}
/*
19
0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0 1
1 2
2 3
2 4
3 5
5 7
4 6
1 8
8 9
9 10
8 11
11 12
11 13
13 14
3 15
15 16
16 17
16 18
18 19
*/