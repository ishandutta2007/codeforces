#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
typedef long double lb;
int n,k,fri[N],dep[N],dp[N];
bool pd[N];
struct edge{
    int to,nex;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
void dfs(int u,int fa){
    for(int i=h[u];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
void fi(int u,int fa){
    if(fri[u])dp[u]=dep[u];
    for(int i=h[u];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        fi(v,u);
        dp[u]=min(dp[u],dp[v]);
    }
    if((dp[u]+1)/2==dep[u])pd[u]=1;
}
ll ans(int u,int fa){
    if(pd[u])return 1;
    ll con=0,res=0;
    for(int i=h[u];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        res+=ans(v,u);
        con++;
    }
    if(!con)return -1e9;
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            fri[i]=0;
            dp[i]=1e9;
            pd[i]=0;
            h[i]=0;
        }
        dep[1]=0;
        cnt=0;
        for(int i=1;i<=k;i++){
            int x;
            scanf("%d",&x);
            fri[x]=1;
        }
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        dfs(1,0);
        fi(1,0);
        ll res=ans(1,0);
        printf("%lld\n",res>=0?res:-1);
    }
    return  0;
}