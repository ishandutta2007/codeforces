#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int hson[N],n,w[N],mx[N];
struct edge{
    int to,nex;
};
edge ed[N<<1];
int cnt,h[N],pd[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
void dfs(int x,int fa){
    mx[x]=w[x];
    int now=0;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        if(mx[v]>now)now=mx[v],hson[x]=v;
    }
    mx[x]=max(mx[x],now);
}
int find(int x){
    return hson[x]?find(hson[x]):x;
}
int main(){
    scanf("%d",&n);
    long long ma=0,ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        ma=max(ma,1ll*w[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    int now=find(1);
    memset(hson,0,sizeof hson);
    dfs(now,0);
    for(int i=1;i<=n;i++){
        pd[hson[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(!pd[i])ans+=mx[i];
    }
    printf("%lld",ans+ma);
    return  0;
}