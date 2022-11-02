#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
const ll mod=1e9+7;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
const int MAXN=1e4+7,inf=1e7;
int n,m,k,g[20][20],dp[1<<20],id[20],L[MAXN],a[MAXN],cnt,d[MAXN];
void bfs(int u){
    memset(d,0x3f,sizeof(d));
    d[u]=0;queue<int> q;q.push(u);
    while(!q.empty()){
        u=q.front();q.pop();
        for(ri i=1;i<=m;++i){
            {
                int v=u+L[i];
                if(v>=1&&v<=n+1&&d[v]>d[u]+1) d[v]=d[u]+1,q.push(v);
            }
            {
                int v=u-L[i];
                if(v>=1&&v<=n+1&&d[v]>d[u]+1) d[v]=d[u]+1,q.push(v);
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    for(ri i=1;i<=k;++i){
        int p;scanf("%d",&p);a[p]=1;
    }
    for(ri i=n+1;i;--i) a[i]=a[i-1]^a[i];
    for(ri i=1;i<=n+1;++i) if(a[i]) id[cnt++]=i;
    for(ri i=1;i<=m;++i) scanf("%d",&L[i]);
    for(ri i=0;i<cnt;++i){
        bfs(id[i]);
        for(ri j=0;j<cnt;++j) g[i][j]=d[id[j]];
    }
    // for(ri u=0;u<cnt;++u){
    //     for(ri v=0;v<cnt;++v) printf("%d ",g[u][v]);
    //     puts("");
    // }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(ri s=0;s<(1<<cnt);++s) for(ri u=0;u<cnt;++u) if(!(s>>u&1)) for(ri v=u+1;v<cnt;++v) if(!(s>>v&1)) dp[s|1<<u|1<<v]=min(dp[s|1<<u|1<<v],dp[s]+g[u][v]);
    if(dp[(1<<cnt)-1]>=inf) printf("%d\n",-1);
    else printf("%d\n",dp[(1<<cnt)-1]);
}