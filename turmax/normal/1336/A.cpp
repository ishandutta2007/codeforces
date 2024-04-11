#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200000;
vector <int> a[maxn];
bool used[maxn];
int corn[maxn];
bool used1[maxn];
int sub[maxn];
void dfs(int x)
{
    sub[x]=1;
    used[x]=true;
    int v;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            dfs(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
}
int dfs1(int x,int c)
{
    used[x]=true;
    int ans=0;
    if(used1[x])
    {
        ans+=c;
    }
    else
    {
        ++c;
    }
    int v;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            ans+=dfs1(v,c);
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    corn[0]=0;
    dfs(0);
    vector <pair<int,int> > v;
    for(int i=0;i<n;++i)
    {
        v.push_back({-corn[i]+sub[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k;++i)
    {
        //cout<<v[i].second+1<<" go "<<endl;
        used1[v[i].second]=true;
    }
    cout<<dfs1(0,0)<<endl;
    return 0;
}