#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int n,m,x,y,f[200010],d[200010];
vector<pair<int,int>>ans;
vector<pair<int,int>>edge;
vector<pair<int,int>>v[200010];
int find(int x)
{
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}
int jihe(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        f[y]=x;
        return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        edge.push_back(make_pair(x,y));
        v[x].push_back(make_pair(x,y));
        v[y].push_back(make_pair(x,y));
        d[x]++;
        d[y]++;
    }
    int zd=0,mi;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        if(d[i]>zd)
        {
            zd=d[i];
            mi=i;
        }
    }
    for(auto it:v[mi])
    {
        ans.push_back(it);
        jihe(it.first,it.second);
    }
    for(auto it:edge)
    {
        if(jihe(it.first,it.second))
            ans.push_back(it);
    }
    for(auto it:ans)
        cout<<it.first<<' '<<it.second<<endl;
    return 0;
}