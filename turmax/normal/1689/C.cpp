#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector<int> a[maxn];bool used[maxn];int corn[maxn];int sub[maxn];int w[maxn];int t[maxn];
void dfs(int x)
{
    used[x]=true;sub[x]=1;
    for(int v:a[x]) if(!used[v]) {t[x]++;corn[v]=corn[x]+w[v];dfs(v);sub[x]+=sub[v];}
    used[x]=false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;
    while(t1--)
    {
        int n;cin>>n;for(int i=0;i<n;++i) a[i].clear();
        for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);}
        for(int i=0;i<n;++i) {if(a[i].size()>=2 || i==0) w[i]=2; else w[i]=1; t[i]=0;} t[0]=0;
        corn[0]=w[0];dfs(0);int ans=1e9;
        for(int i=0;i<n;++i) if(t[i]<=1) ans=min(ans,corn[i]);
        cout<<n-ans<<'\n';
    }
    return 0;
}