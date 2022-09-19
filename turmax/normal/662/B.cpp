#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector <pair<int,int> > a[maxn];
bool used1[maxn];bool used2[maxn];
int color1[maxn];int color2[maxn];
bool h1=true;bool h2=true;
vector <int> v1;vector <int> v2;
void dfs1(int x)
{
    if(color1[x]==0) {v1.push_back(x);}
    else {v2.push_back(x);}
    used1[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i].first;
        if(!used1[v])
        {
            color1[v]=(color1[x]+a[x][i].second)%2;
            dfs1(v);
        }
        else
        {
            if(color1[v]!=((color1[x]+a[x][i].second)%2))
            {
                h1=false;
            }
        }
    }
}
void dfs2(int x)
{
    if(color2[x]==0) {v1.push_back(x);}
    else {v2.push_back(x);}
    used2[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i].first;
        if(!used2[v])
        {
            color2[v]=(color2[x]+a[x][i].second+1)%2;
            dfs2(v);
        }
        else
        {
            if(color2[v]!=((color2[x]+a[x][i].second+1)%2))
            {
                h2=false;
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    char s;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        cin>>s;
        x--;y--;
        if(s=='R')
        {
            a[x].push_back({y,0});a[y].push_back({x,0});
        }
        else
        {
            a[x].push_back({y,1});a[y].push_back({x,1});
        }
    }
    vector <int> res1;
    for(int i=0;i<n;++i)
    {
        if(!used1[i])
        {
            dfs1(i);
            if(v1.size()>=v2.size())
            {
                swap(v1,v2);
            }
            for(int j=0;j<v1.size();++j) res1.push_back(v1[j]);
            v1.clear();v2.clear();
        }
    }
    vector <int> res2;
    for(int i=0;i<n;++i)
    {
        if(!used2[i])
        {
            dfs2(i);
            if(v1.size()>=v2.size())
            {
                swap(v1,v2);
            }
            for(int j=0;j<v1.size();++j) res2.push_back(v1[j]);
            v1.clear();v2.clear();
        }
    }
    if(!h1 && !h2) {cout<<(-1);return 0;}
    vector <int> ans;
    if(h1)
    {
        ans=res1;
    }
    if(h2)
    {
        if(!h1 || res2.size()<ans.size())
        {
            ans=res2;
        }
    }
    cout<<ans.size()<<endl;
    for(auto v:ans)
    {
        cout<<v+1<<' ';
    }
    return 0;
}