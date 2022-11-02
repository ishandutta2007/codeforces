#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
const int N = 1e6+9;
int n,m,g[N],dep[N];
vector<int >vec[N];
vector<ll >sum[N];
void dfs(int u,int fa){
    if(u>n) return ;
    dep[u]=dep[fa]+g[u];
    dfs(ls(u),u);dfs(rs(u),u);
    if(rs(u)<=n)
        merge(vec[ls(u)].begin(),vec[ls(u)].end(),vec[rs(u)].begin(),vec[rs(u)].end(),back_inserter(vec[u]));
    else if(ls(u)<=n)
        vec[u].insert(vec[u].begin(),vec[ls(u)].begin(),vec[ls(u)].end());
    vec[u].push_back(dep[u]);
    sort(vec[u].begin(),vec[u].end());
    for(int i=0;i<(int)vec[u].size();i++) sum[u].push_back(vec[u][i]);
    for(int i=1;i<(int)sum[u].size();i++) sum[u][i]+=sum[u][i-1];return ;
}
ll calc(int u,int x){//udepx
    if(!vec[u].size()) return 0;
    int l=0,r=vec[u].size()-1;ll ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(vec[u][mid]<=x) l=mid+1,ans=mid;
        else r=mid-1;
    }
    if(ans!=-1) ans=(ans+1)*x-sum[u][ans];
    return max(ans,0ll);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++) scanf("%d",&g[i]);
    dfs(1,0);
    for(int i=1;i<=m;i++){
        int a,h;scanf("%d%d",&a,&h);
        ll ans=calc(a,h+dep[a]),u=a;
        while((u/2)&&h>0){
            h-=g[u];if(h<=0) break;
            ans+=h+calc(u^1,dep[u^1]+h-g[u^1]);
            u/=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}