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
int n,m,x,y,f[200010],degree,cnt;
vector<pair<int,int>>ans,edge1,wron;
vector<pair<int,int>>edge;
vector<pair<int,int>>v[200010];
int find(int x)
{
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}
int jihe(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        f[x]=y;
        return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>m>>degree;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(x==1||y==1)
            edge1.push_back(make_pair(x,y));
        else
            edge.push_back(make_pair(x,y));
    }
    if(edge1.size()<degree)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(auto it:edge)
        jihe(it.first,it.second);
    for(auto it:edge1)
    {
        if(jihe(it.first,it.second))
        {
            cnt++;
            ans.push_back(it);
        }
        else
            wron.push_back(it);
    }
    if(cnt>degree)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<degree-cnt;i++)
    {
        ans.push_back(wron[i]);
    }
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(auto it:ans)
    {
        jihe(it.first,it.second);
    }
    for(auto it:edge)
        if(jihe(it.first,it.second))
            ans.push_back(it);
    cout<<"YES"<<endl;
    for(auto it:ans)
        cout<<it.first<<' '<<it.second<<endl;
    return 0;
}