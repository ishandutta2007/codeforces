#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
vector <int> ch[maxn];
bool used[maxn];
int h[maxn];
int z[maxn];
int pr[maxn];
bool b[maxn];
set <pair<int,int> > u;
void dfs0(int x)
{
    used[x]=true;
    for(auto v:a[x]) if(!used[v]) {ch[x].push_back(v);pr[v]=x;dfs0(v);}
    used[x]=false;
}
void dfs(int x)
{
    h[x]=0;z[x]=(-1);
    for(auto v:ch[x]) {dfs(v);if((h[v]+1)>h[x]) {h[x]=h[v]+1;z[x]=v;}}
}
void upd(int x)
{
    u.insert({-h[x],x});
}
void del(int x)
{
    u.erase({-h[x],x});
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;++i)
    {
        int x,y;cin>>x>>y;x--;y--;a[x].push_back(y);a[y].push_back(x);
    }
    dfs0(0);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        if(ch[i].empty()) ++sum;
    }
    if(sum<=k)
    {
        int ans1=0;
        ans1=max((n-sum)*sum,(n-k)*k);
        if(sum<=(n/2) && k>=(n/2)) ans1=(n/2)*(n-(n/2));
        cout<<ans1;
        return 0;
    }
    dfs(0);
    upd(0);
    int ans=0;
    for(int i=0;i<k;++i)
    {
        pair <int,int> f=(*u.begin());
        ans+=(-f.first);
        del(f.second);
        int cur=f.second;
        b[cur]=true;
        while(z[cur]!=(-1))
        {
            for(auto v:ch[cur]) upd(v);
            cur=z[cur];
            b[cur]=true;del(cur);
        }
    }
    int res=1e18;
    for(int i=0;i<=(n-k-ans);++i)
    {
        res=min(res,(n-k-i)*(k-i));
    }
    cout<<res;
    return 0;
}