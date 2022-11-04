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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
int fa[maxn],da[maxn],x[maxn];
int findx(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    return fa[x]=findx(fa[x]);
}
void jihe(int u,int v)
{
    if(findx(u)!=findx(v))
        fa[findx(u)]=findx(v);
}
vector<pair<int,int>>mp;
int  main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    memset(da,0,sizeof(da));
    memset(x,inf,sizeof(x));
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        jihe(u,v);
    }
    int y;
    for(int i=1;i<=n;i++)
    {
        y=findx(i);
        da[y]=max(da[y],i);
        x[y]=min(x[y],i);
    }
    for(int i=1;i<=n;i++)
    {
        if(x[i]!=inf)
            mp.push_back(make_pair(x[i],da[i]));
    }
    sort(mp.begin(),mp.end());
    int now=0;
    int sum=0;
    for(int i=0;i<mp.size();i++)
    {
        if(now>mp[i].first)
            sum++;
        now=max(now,mp[i].second);
    }
    cout<<sum<<endl;
    return 0;
    
}