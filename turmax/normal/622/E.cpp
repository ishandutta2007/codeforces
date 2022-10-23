#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
vector<int> a[maxn];int deq[maxn];bool used[maxn];vector<int> u[maxn];int corn[maxn];
int h[maxn];
void dfs(int x)
{
    used[x]=true;
    for(int v:a[x])
    {
        if(!used[v])
        {
            h[v]=h[x];
            corn[v]=corn[x]+1;
            dfs(v);
        }
    }
    used[x]=false;
}
int f(vector<int> v)
{
    int ma=0;sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i) ma=max(ma,v[i]-i);
    return v.size()+ma;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);}
    for(int i=0;i<n;++i) deq[i]=a[i].size();
    used[0]=true;
    for(int v:a[0])
    {
        h[v]=v;corn[v]=1;
        dfs(v);
    }
    for(int i=1;i<n;++i)
    {
        if(deq[i]==1) u[h[i]].push_back(corn[i]);
    }
    int ans=0;
    for(int v:a[0])
    {
        ans=max(ans,f(u[v]));
    }
    cout<<ans-1;
    return 0;
}